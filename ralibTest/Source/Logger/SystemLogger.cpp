#include "Pch.h"
#include "SystemLogger.h"
#include "StringBuilder.h"
#include <cstdarg>
#include <string>
#include <chrono>
#include <iomanip>
#include <sstream>
#include <ctime>

ILogOutput* SystemLogger::s_logOutput = nullptr;

void
SystemLogger::Print(const char* filePath, int line, int logLevel, const char* format, ...)
{
	if (!s_logOutput) {
		return;
	}

	static const char* logLevelStr[] = {
		"ALL",
		"TRACE",
		"DEBUG",
		"INFO",
		"WARNING",
		"ERROR",
		"FATAL",
	};
	static constexpr size_t MAX_LOG_LENGTH = 2048;

	// 時刻文字列
	std::string timeStr;
	{
		auto now = std::chrono::system_clock::now();
		auto now_time_t = std::chrono::system_clock::to_time_t(now);
		auto now_us = std::chrono::duration_cast<std::chrono::microseconds>(now.time_since_epoch()).count() % 1000000;
		std::tm tm;
		localtime_s(&tm, &now_time_t);

		std::ostringstream oss;
		oss << std::put_time(&tm, "%F %T");
		oss << '.' << std::setfill('0') << std::setw(6) << now_us;
		timeStr = oss.str();
	}

	ILogOutput::LOG log;
	StringBuilder builder(log.text, sizeof(log.text));

	// ログのヘッダー構築
	builder.Append('[');
	builder.Append(logLevelStr[logLevel]); // ログレベル
	builder.Append("][", 2);
	builder.Append(filePath); // ファイルパス
	builder.Append("][", 2);
	builder.Append(std::to_string(line)); // 行数
	builder.Append("][", 2);
	builder.Append(timeStr); // 時刻
	builder.Append(']');

	// 本体
	{
		char* begin = builder.GetBegin();
		char* end = builder.GetEnd();

		va_list args;
		va_start(args, format);
		const int expectedLength = std::vsnprintf(
			begin,
			end - begin,
			format,
			args
		);
		va_end(args);

#ifdef _DEBUG
		assert(expectedLength >= 0);

		// 文字数が足りていたかチェック
		ASSERT_WARNING_LOG(expectedLength + 1 > end - begin, "log length shortage(expected:%d, limit:%d, in %s L.%d)", expectedLength, end - begin, filePath, line);
#endif // _DEBUG
	}

	// 出力対象として追加
	s_logOutput->PushLog(log);
}
