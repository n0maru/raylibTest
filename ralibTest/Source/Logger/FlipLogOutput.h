#pragma once
#include "ILogOutput.h"
#include <array>
#include <vector>
#include <mutex>

/// <summary>
/// 2 つのログプールをフリップしながらファイルに出力する
/// </summary>
class FlipLogOutput final : public ILogOutput
{
public:
	/// <summary>
	/// コンストラクタ
	/// </summary>
	/// <param name="outFilePath">出力先ファイルパス</param>
	explicit FlipLogOutput(const std::string& outFilePath)
		: m_logPools()
		, m_inputPoolIndex(0)
		, m_inputMutex()
		, m_outputMutex()
		, m_outFilePath(outFilePath)
	{
	}

	/// <summary>
	/// 更新処理
	/// </summary>
	void Update();

	/// <summary>
	/// ログを追加する
	/// </summary>
	/// <param name="log">追加するログ</param>
	void
		PushLog(const LOG& log) override;
private:
	/// <summary>
	/// 入力用ログプールの参照を取得する
	/// </summary>
	/// <returns>入力用ログプールの参照</returns>
	std::vector<LOG>&
		_RefInputPool()
	{
		return m_logPools[m_inputPoolIndex];
	}

	/// <summary>
	/// 出力用ログプールの参照を取得する
	/// </summary>
	/// <returns>出力用ログプールの参照</returns>
	std::vector<LOG>&
		_RefOutputPool()
	{
		return m_logPools[1u - m_inputPoolIndex];
	}
private:
	/// <summary>
	/// 出力用ログプールにあるログを全て出力する
	/// </summary>
	void
		_Flush();

private:
	/// <summary>
	/// 入力用と出力用のログプール
	/// </summary>
	std::array<std::vector<LOG>, 2> m_logPools;

	/// <summary>
	/// 入力用ミューテックス。
	/// 入出力添え字フリップ時にミューテックスがフリップされてほしくないから添え字で管理しない。
	/// </summary>
	std::mutex m_inputMutex;

	/// <summary>
	/// 出力用ミューテックス。
	/// 入出力添え字フリップ時にミューテックスがフリップされてほしくないから添え字で管理しない。
	/// </summary>
	std::mutex m_outputMutex;

	/// <summary>
	/// 入力用ログプールのインデックス
	/// </summary>
	size_t m_inputPoolIndex;

	/// <summary>
	/// 出力先ファイル
	/// </summary>
	std::string m_outFilePath;
};
