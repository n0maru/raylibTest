#include "Pch.h"
#include "FlipLogOutput.h"
#include <fstream>

void FlipLogOutput::Update()
{
	// TODO: フリップ時にミューテックスを 2 つともロックしないといけないのは非効率的かも

	// 出力が終わってなかったらフリップは行わない
	if (m_outputMutex.try_lock()) {
		// 入力は短い時間しか行われないはずだから、終わるのを待つ
		m_inputMutex.lock();
		// 入力と出力を入れ替え
		m_inputPoolIndex = 1u - m_inputPoolIndex;

		m_inputMutex.unlock();
		m_outputMutex.unlock();
	}
	else {
		WARNING_LOG("Failed to Flip");
	}

	// 別スレッドで出力する
	std::thread outputThread(&FlipLogOutput::_Flush, this);
	outputThread.join();
}

void FlipLogOutput::PushLog(const LOG& log)
{
	std::scoped_lock<std::mutex> lock(m_inputMutex);
	_RefInputPool().push_back(log);
}

void FlipLogOutput::_Flush()
{
	{
		std::scoped_lock<std::mutex> lock(m_outputMutex);

		std::ofstream out(m_outFilePath, std::ios::app);
		if (out.is_open())
		{
			auto& outputPool = _RefOutputPool();
			// C++側がいい感じのタイミングでフラッシュしてくれることを期待している
			for (const LOG& log : outputPool) {
				out << log.text << '\n';
			}
			// 最後にフラッシュを行う
			out.flush();
			out.close();

			INFO_LOG("Flushed %u logs", outputPool.size());

			outputPool.clear();
		}
		else
		{
			WARNING_LOG("Failed to open file(%s)", m_outFilePath.c_str());
		}

	}
}
