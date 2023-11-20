#include<iostream>
#include"DoubleLinkedList.h"
#include"Benchmark.h"
#include<vector>
int main()
{
	setlocale(LC_ALL, "ru");
	/*std::vector<int>vec;
	MyStruct::DoubleLinkedList<int> list;
	list.push_back(5);
	list.push_back(4);
	list.push_back(3);
	list.push_back(2);
	list.push_back(1);
	list.push_back(0);
	std::cout << list;*/
	std::cout << "100 элементов: " << Benchmark::test_push_and_pop(100, 100);
	std::cout <<std::endl<< "1000 элементов: " << Benchmark::test_push_and_pop(1000, 1000);
	std::cout << std::endl << "10000 элементов: " << Benchmark::test_push_and_pop(10000, 10000);
	std::cout << std::endl << "100000 элементов: " << Benchmark::test_push_and_pop(100000, 100000);


	/*list.display();

	std::cout << std::endl;
	list.pop();
	list.display();

	std::cout << std::endl;
	list.pop_back();
	list.display();

	std::cout << std::endl;
	list.insert(3, 100);
	list.insert(2, 100);
	list.insert(1, 100);
	list.insert(0, 100);
	list.display();
	std::cout <<std::endl<< "После удаления rev"<<std::endl;
	list.display2();

	std::cout << std::endl;
	list.Remove(3);
	list.display();
	Write_to_file(list);
	std::cout << std::endl;
	std::cout<<"summa = " << summ(list);

	std::cout << std::endl << "max " <<Max(list);
	std::cout << std::endl << "max->min = " << sort_min(list);
	std::cout << std::endl << "min->max = " << sort_max(list);*/


}