#include <vld.h>
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
#include "CountSort.hpp"

#define RANDOM_COUNT 1000 // 随机数数量	

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
		m_num = new LONG[len];
		memset(m_num, 0, len * sizeof(LONG));

		// 产生随机数
		srand((unsigned)time(0));
		for (size_t i = 0; i < len; i++)
		{
			m_num[i] = rand() % len;
		}
	}

	~CRandomHandler()
	{
		delete[] m_num;
		m_num = nullptr;
	}

	void copy(LONG* _other, size_t _len)
	{
		memcpy_s(_other, _len * sizeof(LONG), m_num, m_len * sizeof(LONG));
	}

	size_t len() const
	{
		return m_len;
	}

private:
	LONG*	m_num;
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

	LONG* num = new LONG[rd->len()];

	rd->copy(num, rd->len()); testSpeed([&] { CountSort(num, rd->len()); }, "CountSort");
	rd->copy(num, rd->len()); testSpeed([&] { QuickSort(num, 0, rd->len() - 1); }, "QuickSort");
	rd->copy(num, rd->len()); testSpeed([&] { BubbleSort(num, rd->len()); }, "BubbleSort");
	rd->copy(num, rd->len()); testSpeed([&] { SelectSort(num, rd->len()); }, "SelectSort");


	delete[] num;
	num = nullptr;

	cout << endl << "[ -------------性能测试完毕-------------- ]" << endl;

	getchar();

	return 0;
}