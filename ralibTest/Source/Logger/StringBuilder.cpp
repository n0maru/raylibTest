#include "StringBuilder.h"
#include <string>

StringBuilder::StringBuilder(char* buffer, size_t size)
	: m_buffer(buffer)
	, m_capacity(size)
	, m_size(0)
{
}

bool StringBuilder::Append(const std::string& str)
{
	return Append(str.data(), str.size());
}

bool StringBuilder::Append(const char* src, size_t size)
{
	if (m_size + size <= m_capacity) {
		const char* readIt = src;
		char* writeIt = m_buffer + m_size;
		for (size_t i = 0; i < size; ++i, ++readIt, ++writeIt) {
			*writeIt = *readIt;
		}
		*writeIt = '\0';
		m_size += size;
		return true;
	}
	else {
		return false;
	}
}

bool StringBuilder::Append(char c)
{
	if (m_size + 1 <= m_capacity) {
		m_buffer[m_size] = c;
		m_buffer[m_size + 1] = '\0';
		m_size += 1;
		return true;
	}
	else {
		return false;
	}
}
