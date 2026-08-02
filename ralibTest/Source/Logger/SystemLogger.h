#pragma once
#include "ILogOutput.h"
#include <raylib.h>
#include <cstdarg>

/// <summary>
/// ロガー
/// </summary>
class SystemLogger
{
public:
	/// <summary>
	/// 初期化
	/// </summary>
	static void
		Initialize()
	{
		// ログを出力するかしないかは s_logOutput（＝出力側）で決めるため、SystemLogger では全て出力する
		::SetTraceLogLevel(LOG_ALL);

		// Raylib からのログのリダイレクト設定
		::SetTraceLogCallback(SystemLogger::Print);
	}

	/// <summary>
	/// 終了処理
	/// </summary>
	static void
		Finalize()
	{
		SetLogOutput(nullptr);
	}

	/// <summary>
	/// ログ出力を設定する
	/// </summary>
	/// <param name="logger">ログ出力器</param>
	/// <remarks>
	/// 設定していなければ出力されない。
	/// </remarks>
	static void
		SetLogOutput(ILogOutput* logOutput)
	{
		s_logOutput = logOutput;
	}

	/// <summary>
	/// ログを出力する（Raylib用）
	/// </summary>
	/// <param name="logLevel">ログレベル</param>
	/// <param name="format">フォーマット文字列(%s, %d などを含む)</param>
	/// <param name="args">フォーマット文字列を置き換えるための引数</param>
	static void
		Print(int logLevel, const char* format, va_list args)
	{
		_Print("Raylib", -1, logLevel, format, args);
	}

	/// <summary>
	/// ログを出力する（タイトル用）
	/// </summary>
	/// <param name="filePath">出力元ファイルパス</param>
	/// <param name="line">行数</param>
	/// <param name="logLevel">ログレベル</param>
	/// <param name="format">フォーマット文字列(%s, %d などを含む)</param>
	/// <param name="">可変長引数</param>
	static void
		Print(const char* filePath, int line, int logLevel, const char* format, ...);

private:
	/// <summary>
	/// ログを出力する（タイトル用）
	/// </summary>
	/// <param name="filePath">出力元ファイルパス</param>
	/// <param name="line">行数</param>
	/// <param name="logLevel">ログレベル</param>
	/// <param name="format">フォーマット文字列(%s, %d などを含む)</param>
	/// <param name="args">可変長引数</param>
	static void
		_Print(const char* filePath, int line, int logLevel, const char* format, va_list args);

private:
	/// <summary>
	/// ログ出力器
	/// </summary>
	static ILogOutput* s_logOutput;
};