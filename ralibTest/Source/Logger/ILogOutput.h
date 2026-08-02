#pragma once

/// <summary>
/// ログ出力器
/// </summary>
class ILogOutput
{
public:
	/// <summary>
	/// ログ
	/// </summary>
	struct LOG
	{
		char text[2048]; // 文字列
	};
public:
	/// <summary>
	/// 出力対象のログとして追加する
	/// </summary>
	/// <param name="log">追加するログ</param>
	virtual void
		PushLog(const LOG& log) = 0;
};
