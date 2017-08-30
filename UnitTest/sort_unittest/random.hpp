#pragma once
#include <windows.h>

class CRandom
{
public:
	inline CRandom(size_t len)
	{
		m_len = len;
		m_num = new LONG[len];
		m_copy = new LONG[len];
		memset(m_num, 0, len * sizeof(LONG));
		memset(m_copy, 0, len * sizeof(LONG));

		// 产生随机数
		srand((unsigned)time(0));
		for (size_t i = 0; i < len; i++)
		{
			m_num[i] = rand() % len;
		}

		memcpy_s(m_copy, m_len * sizeof(LONG), m_num, m_len * sizeof(LONG));
	}

	inline ~CRandom()
	{
		delete[] m_num;
		m_num = nullptr;

		delete[] m_copy;
		m_copy = nullptr;
	}

	inline size_t len() const
	{
		return m_len;
	}

	inline LONG* num(bool _reset = true)
	{
		if (_reset)
		{
			memcpy_s(m_copy, m_len * sizeof(LONG), m_num, m_len * sizeof(LONG));
		}
		
		return m_copy;
	}

private:
	LONG*	m_num;
	LONG*	m_copy;
	size_t	m_len;
};