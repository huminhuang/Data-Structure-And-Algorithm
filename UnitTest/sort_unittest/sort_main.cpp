//#include <vld.h>
#include <random>
#include <iostream>
#include <windows.h>
#include <chrono>
#include <functional>
using namespace std;
using namespace std::chrono;

#include "BubbleSort.hpp"
#include "QuickSort.hpp"
#include "SelectSort.hpp"

#define RANDOM_COUNT 10000000 // 随机数数量	

class CRandomHandler
{
public:
	static CRandomHandler* Get()
	{
		static CRandomHandler random(RANDOM_COUNT);
		return &random;
	}

	CRandomHandler(size_t len)
	{
		m_len = len;
		m_num = new ULONG[len];
		memset(m_num, 0, len * sizeof(ULONG));

		// 产生随机数
		std::random_device rd;
		for (size_t i = 0; i < len; i++)
		{
			m_num[i] = rd();
		}
	}

	~CRandomHandler()
	{
		delete[] m_num;
		m_num = nullptr;
	}

	void copy(ULONG* _other, size_t _len)
	{
		memcpy_s(_other, _len * sizeof(ULONG), m_num, m_len * sizeof(ULONG));
	}

	size_t len() const
	{
		return m_len;
	}

private:
	ULONG*	m_num;
	size_t	m_len;
};

/*
	测试时间消耗
*/
void testSpeed(std::function<void()>&& task, const char* message)
{
	time_point<high_resolution_clock> begin = high_resolution_clock::now();

	task();

	int64_t time = duration_cast<chrono::milliseconds>(high_resolution_clock::now() - begin).count();

	cout << "[ " << message << " 消耗时间] " << time << "ms" << endl;
}

int main()
{		
	cout << "[ -------------开始测试排序性能-------------- ]" << endl << endl;

	CRandomHandler* rd = CRandomHandler::Get();

	ULONG* num = new ULONG[rd->len()];

	rd->copy(num, rd->len());
	testSpeed([&]{ QuickSort(num, 0, rd->len() - 1); }, "QuickSort");
	rd->copy(num, rd->len());
	testSpeed([&]{ BubbleSort(num, rd->len()); }, "BubbleSort");
	rd->copy(num, rd->len());
	testSpeed([&]{ SelectSort(num, rd->len()); }, "SelectSort");


	delete[] num;
	num = nullptr;

	cout << endl << "[ -------------性能测试完毕-------------- ]" << endl;

	getchar();

	return 0;
}