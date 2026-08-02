#pragma once
#include <string>

/// <summary>
/// バッファ上に文字列を構築する
/// </summary>
class StringBuilder
{
public:
	/// <summary>
	/// コンストラクタ
	/// </summary>
	/// <param name="buffer">バッファ</param>
	/// <param name="size">バッファサイズ[byte]</param>
	explicit StringBuilder(char* buffer, size_t size);

	/// <summary>
	/// 末尾に文字列を追加する
	/// </summary>
	/// <param name="str">追加する文字列</param>
	/// <returns>追加されたら true、追加されなければ false</returns>
	bool
		Append(const std::string& str);

	/// <summary>
	/// 末尾に文字列を追加する
	/// </summary>
	/// <param name="src">追加する文字列（'\0'が追加されていること）</param>
	/// <returns>追加されたら true、追加されなければ false</returns>
	bool
		Append(const char* src)
	{
		return Append(src, strlen(src));
	}

	/// <summary>
	/// 末尾に文字列を追加する
	/// </summary>
	/// <param name="src">追加する文字列</param>
	/// <param name="size">追加する文字数</param>
	/// <returns>追加されたら true、追加されなければ false</returns>
	bool
		Append(const char* src, size_t size);

	/// <summary>
	/// 末尾に 1 文字追加する
	/// </summary>
	/// <param name="c">文字</param>
	/// <returns>追加されたら true、追加されなければ false</returns>
	bool
		Append(char c);

public:
	/// <summary>
	/// 現在までに構築された文字列長を取得する
	/// </summary>
	/// <returns>現在までに構築された文字列長</returns>
	size_t
		GetSize() const
	{
		return m_size;
	}

	/// <summary>
	/// 構築可能な最大の文字列長を取得する
	/// </summary>
	/// <returns>構築可能な最大の文字列長</returns>
	size_t
		GetCapacity()
	{
		return m_capacity;
	}

	/// <summary>
	/// 追加できる残り文字数を取得する
	/// </summary>
	/// <returns>追加できる残り文字数</returns>
	size_t
		GetLeftSize() const
	{
		return m_capacity - m_size;
	}
private:
	char* m_buffer; // バッファ
	size_t m_capacity; // 構築可能な最大の文字列長
	size_t m_size; // 現在までに構築された文字列長
};