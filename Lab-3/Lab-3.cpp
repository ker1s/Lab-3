#include <iostream>
#include <iomanip>
#include <random>

using namespace std;

struct List
{
	int data;
	List* next;
};

bool IsEmpty(List* list)
{
	return list == nullptr;
}
int RandGenerate()
{
	random_device seed;
	mt19937 generator(seed());
	uniform_int_distribution<int> distribution(-100, 100);
	return distribution(generator);
}


List* AddHead(List* head, int value)
{
	List* temp = new List;
	temp->next = head;
	temp->data = value;
	head = temp;
	return head;
}
List* AddTail(List* tail, int value)
{
	List* temp {new List};
	temp->data = value;
	temp->next = nullptr;
	
	if (IsEmpty(tail))
	{
		tail = temp;
		return tail;
	}
	else
	{ 
		List* last{ tail };
		while (last->next != nullptr)
		{
			last = last->next;
		}
		last->next = temp;
		last = temp;
		return tail;
	}
}
List* AddTailRand(List* randList, int quant)
{
	int value;
	for (int i = 0; i < quant; i++)
	{
		value = RandGenerate();
		randList = AddTail(randList, value);
	}
	return randList;
}



List* findPos(List* find, int pos)
{
	List* temp{ find };
	while (temp!=nullptr&& pos > 1)
	{
		temp = temp->next;
		pos--;
	}
	return temp;
}
List* Insert(List* insert, int pos,int value)
{
	if (insert == nullptr || pos == 0)
	{
		return AddHead(insert, value);
	}
	List* temp = insert;
	List* newElem = new List;
	List* preview{ findPos(temp, pos - 1) };
	newElem->next = findPos(temp, pos);
	newElem->data = value;
	preview->next = newElem;
	return insert;
}

List* RemoveHead(List* head)
{
	if (IsEmpty(head))
	{
		return head;
	}
	List* removed{ head->next };
	delete head;
	return removed;
}
List* RemoveTail(List* tail)
{
	if (IsEmpty(tail))
	{
		return tail;
	}
	List* removed{ tail };
	while (removed->next->next!= nullptr)
	{
		removed = removed->next;
	}
	delete removed->next;
	removed->next = nullptr;
	return tail;
}
List* Remove(List* any,int pos)
{
	if (pos == 0)
	{
		return RemoveHead(any);
	}
	if (any == nullptr)
	{
		return any;
	}

	List* prevew{ findPos(any, pos-1) };
	if (prevew->next != nullptr)
	{
		List* removed{ prevew->next };
		prevew->next = removed->next;
		delete removed;
		return any;
	}
	return any;
}
List* RemoveAll(List* all)
{
	if (IsEmpty(all))
	{
		return all;
	}
	while (all != nullptr)
	{
		all = RemoveHead(all);
	}
	return all;
}


void OutList(List* list)
{
	if (list == nullptr)
	{
		cout << "Пусто.\n";
		return;
	}
	List* temp = list;
	while (temp != nullptr)
	{
		cout << setw(10) << temp->data << endl;
		temp = temp->next;
	}
	cout << endl;
}

List* FindData(List* find, int value)
{
	List* current{ find };
	while (current != nullptr && current->data != value)
	{
		current = current->next;
	}
	return current;
}
List* FindPos(List* find, int pos)
{
	if (find == nullptr || pos < 0) // проверяем, что список не пустой и позиция корректна
	{
		return nullptr;
	}
	int i{ 0 };
	List* temp = find;
	while (temp != nullptr && i <= pos)
	{
		if (i == pos)
		{
			return temp;
		}
		i++;
		temp = temp->next;
	}
	return nullptr;
}

int Retrieve(List* find, List* elem)
{

	List* temp = find;
	while (temp != elem)
	{
		temp = temp->next;
	}
	return temp->data;
}

int main()
{
	bool enter(false);
	while (!enter)
	{
		int task;
		cout << "Выберете задание\n";  cin >> task;

		switch (task)
		{
		case 1:			//Добавление в начало
		{
			List* labList = nullptr;
			int quant;
			cout << "Сколько элементов хотите добавить?\n";
			cin >> quant;
			cout << endl;
			for (int i = 0; i < quant; i++)
			{
				int value;
				cout << i << " элемент списка равен: "; cin >> value;
				labList = AddHead(labList, value);
			}
			OutList(labList);
		}
		break;

		case 2:		//Добавоение в конец
		{
			List* labList = nullptr;
			int quant;
			cout << "Сколько элементов хотите добавить?\n";
			cin >> quant;
			cout << endl;
			for (int i = 0; i < quant; i++)
			{
				int value;
				cout << i << " элемент списка равен: "; cin >> value;
				labList = AddTail(labList, value);
			}
			OutList(labList);
		}
		break;

		case 3: //добавление узла в указанную позицию
		{
			List* labList = nullptr;
			int quant;
			int pos;
			int value;
			cout << "\n\nСколько элементов будет в списке?\n";
			cin >> quant;
			cout << endl;
			labList = AddTailRand(labList, quant);
			cout << "\n\n";
			OutList(labList);

			cout << "\n\nКуда хотите добавить элемент?\n";
			cin >> pos;
			cout << "\nЗначение элемент?\n";
			cin >> value;
			labList = Insert(labList, pos, value);
			OutList(labList);
			system("pause");
		}
		break;

		case 4: // удаление из начала
		{
			List* labList = nullptr;
			int quant;
			cout << "\n\nСколько элементов будет в списке?\n";
			cin >> quant;
			cout << endl;
			labList = AddTailRand(labList, quant);
			cout << "\n\n";
			OutList(labList);

			cout << "\n\nСколько элементов хотите удалить из начала списка?\n";
			cin >> quant;
			cout << endl;
			for (int i = 0; i < quant; i++)
			{
				labList = RemoveHead(labList);
			}
			cout << "\n\n";
			OutList(labList);

		}
		break;

		case 5: //удаление из конца
		{
			List* labList = nullptr;
			int quant;
			cout << "\n\nСколько элементов будет в списке?\n";
			cin >> quant;
			cout << endl;
			labList = AddTailRand(labList, quant);
			cout << "\n\n";
			OutList(labList);

			cout << "\n\nСколько элементов хотите удалить из конца списка?\n";
			cin >> quant;
			cout << endl;
			for (int i = 0; i < quant; i++)
			{
				labList = RemoveTail(labList);
			}
			cout << "\n\n";
			OutList(labList);

		}
		break;

		case 6: //удаление указанного
		{
			List* labList = nullptr;
			int quant;
			int pos;
			cout << "\n\nСколько элементов будет в списке?\n";
			cin >> quant;
			cout << endl;
			labList = AddTailRand(labList, quant);
			cout << "\n\n";
			OutList(labList);

			cout << "\n\nОт куда хотите удалить элемент?\n";
			cin >> pos;
			labList = Remove(labList, pos);
			OutList(labList);
			system("pause");
		}
		break;

		case 7: //удалить весь
		{
			List* labList = nullptr;
			int quant;
			cout << "\n\nСколько элементов будет в списке?\n";
			cin >> quant;
			cout << endl;
			labList = AddTailRand(labList, quant);
			cout << "\n\n";
			OutList(labList);

			labList = RemoveAll(labList);
			OutList(labList);

		}
		break;

		case 8://поиск по значениею
		{
			List* labList = nullptr;
			int quant;
			int value;
			int size{ 1 };
			List* answ = new List[size];
			cout << "\n\nСколько элементов будет в списке?\n";
			cin >> quant;
			cout << endl;
			labList = AddTailRand(labList, quant);
			cout << endl;
			OutList(labList);
			cout << endl;
			
			cout << "Искомое значение: "; cin >> value;
			cout << "Указатель равнен " << FindData(labList, value) << endl;
		}
		break;

		case 9: //поиск по позиции
		{
			List* labList = nullptr;
			int quant;
			int pos;
			cout << "\n\nСколько элементов будет в списке?\n";
			cin >> quant;
			cout << endl;
			labList = AddTailRand(labList, quant);
			cout << endl;
			OutList(labList);
			cout << endl;

			cout << "Искомый элемент: "; cin >> pos;
			cout << endl << "Значение указателя с данным индексом:" << FindPos(labList, pos) << endl;
		}
		break;

		case 10: // вывод data по указателю
		{
			List* labList = nullptr;
			int quant;
			int pos;
			cout << "\n\nСколько элементов будет в списке?\n";
			cin >> quant;
			cout << endl;
			labList = AddTailRand(labList, quant);
			cout << endl;
			OutList(labList);
			cout << endl;
			cout << endl;
			cout << labList;
			cout << endl;
			cout << "Искомый элемент по позиции: "; cin >> pos;
			cout << endl << "Значение указателя с данным индексом: " << FindPos(labList, pos) << endl;
			cout << endl << "Значение с данным индексом: " << Retrieve(labList, FindPos(labList, pos)) << endl;
		}
		break;

		default:
		{
			cout << "Нет такого!!!\n";
		}
		break;
		}
		cout << "Что бы продолжить нажмите 0\n";
		cin >> enter;
	}
	return 0;
}



