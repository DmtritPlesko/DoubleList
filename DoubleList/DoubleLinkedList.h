#pragma once
#include<iostream>
#include<fstream>
#include<chrono>
#pragma region ������������ ��� DoubleLinkedList
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
	#pragma region ����������� �� ���������;�������������;�������� ����������

		//����������� �� ��������� ��� �������� 
		DoubleLinkedList()
		{
			Head = nullptr;
			Tail = nullptr;
			size = 0;
		}
		//������ �������������
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

	#pragma region ������ ��� �� ��� �� ������ � ������ 

		// ����� �������� � ������ �� �������
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

		//��������� � ����� ����� ��������� ��������
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

		//�������� ������
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
	
		//�������� ������
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

		//���������� �������� �� �������
		Node* insert(int index, T _value)
		{
			//������
			Node* new_node = Head;
			//���������� ��� ������ �������� � ������ 
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
					//����� ����� ������ �� ��������� ������� 
					new_node = get(index - 1);
					//��������� temp ��� �������� ������ �� ��������� ������� � ��� �������� ����� 
					temp->nextValue = new_node->nextValue;
					temp->prevValue = new_node;
					//����� ��� ��� � new_node ��� ������ 
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
				//���� ������ ��������� �� ������ �� ������� �
				if (index == 0)
				{
					pop();
				}
				//���� �������� ������ ��������� �� ����� �� ������� ���
				else if (index == size)
				{
					pop_back();
				}
				//���� ��������� ������ ��������� ����� ���� �� ���������� ��� � ��� ��������� �������� 
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


	#pragma region ������� ������ � ���������� ��������� ������::DoubleLinkedList

		//����� �� ����� ����� �������(����� ���������� �� ����������)
		//����� �� �����
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

	#pragma region ������� ����������,���������� ��������� ������� � ������ � ����

	//������� ��� ���������� ����� ���� ��������� �����
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

	//������� ��� ���������� ������������� �������� � ����� 
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


	//������� ���������� min->max
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


	//������� ���������� max->min
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
					/* � i-��� ��-� �������� j+1 ��-�
					 swap()*/
					/* T operator[] -> Node : LinkedList \/
					 operator<< -> value: Node \/
					 operator= -> �������� value � ������ Node : Node \/*/
					list[i] = list[j + 1];
					list[j + 1] = min;
				}
			}
		}
		return min;
	}

	//������� ������ � ���� 
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


