#pragma once
#include<iostream>
#include<fstream>
#include<chrono>
#pragma region Пространство под DoubleLinkedList
namespace MyStruct
{

	template<typename T>
	class DoubleLinkedList
	{
	private:
		class Node
		{
		public:
			T value;
			Node* nextValue;
			Node* prevValue;
			Node()
			{

			}
			Node(T _value, Node* _nextValue = nullptr, Node* _prevValue = nullptr)
			{
				this->value = _value;
				this->nextValue = _nextValue;
				this->prevValue = _prevValue;
			}
			Node* operator=(Node* nod)
			{
				this->value = nod->value;
				this->nextValue = nod->nextValue;
				this->prevValue = nod->prevValue;
				return *this;
			}

			friend std::ostream& operator<<(std::ostream& tech, Node& nod)
			{
				tech<<nod.value << " ";
				return tech;
			}
		};
		Node* Head;
		Node* Tail;
		size_t size;
	public:
	#pragma region Конструктор по умолчанию;инициализации;оператор индексации

		//конструктов по умолчанию для создания 
		DoubleLinkedList()
		{
			Head = nullptr;
			Tail = nullptr;
			size = 0;
		}
		//Список инициализации
		DoubleLinkedList(std::initializer_list<T>array)
		{
			for (auto x = array.begin(); x != array.end(); x++)
			{
				push_back(*(x));
			}
		}

		T& operator[](size_t index)
		{
			try
			{
				return get(index)->value;
			}
			catch (const std::out_of_range& e)
			{
				std::cout << e.what();
			}
		}


		/*const void operator=()
		{

		}*/


		size_t get_size()
		{
			return size;
		}
	#pragma endregion

	#pragma region Методы что бы что то делать с листом 

		// Берем значение и ссылку по индуксу
		Node* get(size_t index)
		{
			Node* new_node = Head;
			if (index<0 || index >= size|| !size)
			{
				throw std::out_of_range("Out of range");
			}
			for (size_t i = 0; i < index; i++)
			{
				new_node = new_node->nextValue;
			}
			return new_node;
		}

		//добавение в конец листа введеного значения
		Node* push_back(T _value)
		{
			Node* new_node = new Node(_value);
			if (Head==nullptr)
			{
				Head = new_node;
				Head->nextValue = nullptr;
				Head->prevValue = nullptr;
				Tail = Head;
			}
			else
			{
				new_node->prevValue = Tail;
				Tail->nextValue = new_node;
				Tail = new_node;
				Tail->nextValue = nullptr;

			}
			this->size++;
			return new_node;
		}

		//удаление головы
		Node* pop()
		{
			try
			{
				
					Head = Head->nextValue;
					this->size--;
			}
			catch (const std::out_of_range& e)
			{
				std::cout << e.what();
				return nullptr;
			}
			return 0;
		}
	
		//удаление хвоста
		Node* pop_back()
		{
			Node* new_node = new Node;
			try
			{
				if (Head == Tail)
				{
					pop();
				}
				else
				{
					new_node = get(size - 2);
					Tail->prevValue = new_node->prevValue;
					Tail = new_node;
					Tail->nextValue = nullptr;
					size--;
				}
				
			}
			catch (const std::out_of_range& e)
			{
				std::cout << e.what();
				return nullptr;
			}
		
			return new_node;
		}

		//добавление элемента по индексу
		Node* insert(int index, T _value)
		{
			//голова
			Node* new_node = Head;
			//переменная для обмена значения и ссылки 
			Node* temp = new Node(_value);
			try
			{
				this->size++;
				if (!index)
				{
					temp->prevValue = nullptr;
					Head->prevValue = temp;
					temp->nextValue = Head;
					Head = temp;

				}//1 2 3 4 
				else if (index == size)
				{
					push_back(_value);
				}
				else
				{
					//иначе берем элмент по введеному индексу 
					new_node = get(index - 1);
					//перменной temp даём значение ссылки на следующий элемент и его числовую форму 
					temp->nextValue = new_node->nextValue;
					temp->prevValue = new_node;
					//кладём все это в new_node для прыжка 
					new_node->nextValue = temp;
					(new_node->nextValue)->prevValue = temp;
					//get(index+1)->prevValue = temp;
				}
			}
			catch (const std::out_of_range& e)
			{
				std::cout << e.what();
				return nullptr;
			}
			return new_node;
		}

		Node* Remove(size_t index)
		{
			Node* new_node = Head;
			Node* temp = new Node;
			try
			{
				//если индекс указывает на голову то удаляем её
				if (index == 0)
				{
					pop();
				}
				//если введеный индекс указывает на хвост то удаляем его
				else if (index == size)
				{
					pop_back();
				}
				//если введенный индекс находится между ними то пропускаем его а все следующие сдвигаем 
				else
				{
					temp = get(index + 1);
					new_node = get(index - 1);
					new_node->prevValue = temp->prevValue;
					new_node->nextValue = temp;

				} //1 2 3 4 
			}
			catch (const std::out_of_range& e)
			{
				std::cout << e.what();
				return nullptr;
			}
			this->size--;
			return new_node;
		}
	#pragma endregion


	#pragma region Функции вывода и перегрузка оператора вывода::DoubleLinkedList

		//вывод на экран через функцию(потом поменяется на перегрузку)
		//вывод на экран
		friend std::ostream& operator<<(std::ostream& tech, DoubleLinkedList& list)
		{
			for (size_t i = 0; i < list.size; i++)
			{
				tech << *(list.get(i)) << " ";
			}
			return tech;
		}
	
		void display()
		{
			Node* new_node = Head;
			while (new_node != nullptr)
			{
				std::cout << new_node->value << " ";
				new_node = new_node->nextValue;
			}
		}
		void display2()
		{
			Node* new_node = Tail;
			while (new_node != nullptr)
			{
				std::cout << new_node->value << " ";
				new_node = new_node->prevValue;
			}
		}
	#pragma endregion
	};

	#pragma region Функции сортировки,нахождения максимума минимум и записи в файл

	//функция для нахождения суммы всех элементов листа
	template<typename T>
	T summ(DoubleLinkedList<T>list)
	{
		//std::cout<<typeid(list[0]).name();
		T result = list[0];
		for (size_t i = 1; i < list.get_size(); i++)
		{
			result += list[i];
		}
		return result;
	}

	//функция для нахождения максимального элемента в листе 
	template<typename T>
	T Max(DoubleLinkedList<T>list)
	{
		T max = list[0];
		for (int i = 0; i < list.get_size(); i++)
		{
			if (max < list[i])
			{
				max = list[i];
			}
		}
		return max;
	}


	//функция сортировки min->max
	template<typename T>
	T sort_max(DoubleLinkedList<T>list)
	{
		T max = list[0];
		for (size_t i = 0; i < list.get_size(); i++)
		{
			for (size_t j = 0; j < list.get_size(); j++)
			{
				if (list[i] > list[j])
				{
					//list = ...

					max = list[i];
					list[i] = list[j + 1];
					list[j + 1] = max;
				}
			}
		}
	}


	//функция сортировки max->min
	template<typename T>
	T sort_min(DoubleLinkedList<T>list)
	{
		T min = list[0];
		for (size_t i = 0; i < list.get_size(); i++)
		{
			for (size_t j = 0; j < list.get_size(); j++)
			{
				if (list[i] < list[j])
				{
					min = list[i];
					/* в i-тый эл-т положить j+1 эл-т
					 swap()*/
					/* T operator[] -> Node : LinkedList \/
					 operator<< -> value: Node \/
					 operator= -> изменяет value у твоего Node : Node \/*/
					list[i] = list[j + 1];
					list[j + 1] = min;
				}
			}
		}
		return min;
	}

	//функция записи в файл 
	template<typename T>
	void Write_to_file(DoubleLinkedList<T> list)
	{
		std::ofstream file;
		file.open("MyList.txt");
		for (size_t i = 0; i < list.get_size(); i++)
		{
			file << list[i] << " ";
		}
		file.close();
	}
	#pragma endregion
}
#pragma endregion


