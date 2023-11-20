#pragma once
#include"DoubleLinkedList.h"
#pragma region Пространство под Benchmark::DoubleLinkedList
namespace Benchmark
{
	long long test_push_and_pop(long long push,long long delet)
	{
		MyStruct::DoubleLinkedList<int> list;
		auto begin = std::chrono::steady_clock::now();
		for (size_t i = 0; i < push; i++)
		{
			list.push_back(rand() % 100);
		}
		for (size_t i = 0; i < delet; i++)
		{
			list.pop_back();
		}
		auto end = std::chrono::steady_clock::now();
		auto ms = std::chrono::duration_cast<std::chrono::milliseconds>(end - begin);
		return ms.count();



	}
}