//#include <vld.h>
#include <iostream>
#include <windows.h>
#include <functional>
using namespace std;

#include "BubbleSort.hpp"
#include "QuickSort.hpp"
#include "SelectSort.hpp"
#include "CountSort.hpp"


#define CATCH_CONFIG_MAIN

#include "catch.hpp"
#include "random.hpp"

Catch::Timer timer;

/*
*	����ʱ������
*/
void testSpeed(std::function<void()>&& task, const char* message)
{
	timer.start();

	task();

	cout << "[" << message << "] ����ʱ�䣺 " << timer.getElapsedMilliseconds() << "ms" << endl;
}

/*
*	����������ȷ��
*/
bool testCorrect(LONG arr[], size_t len)
{
	for (size_t i = 0; i < len - 1; i++)
	{
		if (arr[i] > arr[i + 1])
		{
			return false;
		}
	}

	return true;
}

TEST_CASE("����������ȷ��")
{
	CRandom rd(10000);

	CountSort(rd.num(), rd.len())		; REQUIRE(testCorrect(rd.num(false), rd.len()));
	QuickSort(rd.num(), 0, rd.len() - 1); REQUIRE(testCorrect(rd.num(false), rd.len()));
	QuickSort2(rd.num(), 0, rd.len() - 1); REQUIRE(testCorrect(rd.num(false), rd.len()));
	SelectSort(rd.num(), rd.len())		; REQUIRE(testCorrect(rd.num(false), rd.len()));
	BubbleSort(rd.num(), rd.len())		; REQUIRE(testCorrect(rd.num(false), rd.len()));
}

TEST_CASE("������������") 
{
	CRandom rd(100000);

	std::clog << "------------------------��ʼ������������------------------------\n";

	testSpeed([&] { CountSort(rd.num(), rd.len()); }, "CountSort");
	testSpeed([&] { CountSort(rd.num(false), rd.len()); }, "CountSort(����)");
	testSpeed([&] { QuickSort(rd.num(), 0, rd.len() - 1); }, "QuickSort");
	testSpeed([&] { QuickSort(rd.num(false), 0, rd.len() - 1); }, "QuickSort(����)");
	testSpeed([&] { QuickSort2(rd.num(), 0, rd.len() - 1); }, "QuickSort2");
	testSpeed([&] { QuickSort2(rd.num(false), 0, rd.len() - 1); }, "QuickSort2(����)");
	testSpeed([&] { SelectSort(rd.num(), rd.len()); }, "SelectSort");
	testSpeed([&] { SelectSort(rd.num(false), rd.len()); }, "SelectSort(����)");
	testSpeed([&] { BubbleSort(rd.num(), rd.len()); }, "BubbleSort");
	testSpeed([&] { BubbleSort(rd.num(false), rd.len()); }, "BubbleSort(����)");

	std::clog << "------------------------�������ܲ������------------------------\n";
}