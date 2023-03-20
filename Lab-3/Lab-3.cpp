#include <iostream>
#include <iomanip>

using namespace std;

struct List
{
	int data;
	List* next;
};

bool isEmpty(List* list)
{
	return list == nullptr;
}

List* addHead(List* head, int value)
{
	List* temp = new List;
	temp->next = head;
	temp->data = value;
	head = temp;
	return head;
}

List* addTail(List *tail, int value)
{
	List* temp {new List};
	temp->data = value;
	temp->next = nullptr;
	
	if (isEmpty(tail))
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

void outList(List* head)
{
	List* temp = head;
	while (temp != nullptr)
	{
		cout << setw(10) << temp->data << endl;
		temp = temp->next;
	}
	cout << endl;
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
				labList = addHead(labList, value);
			}
			outList(labList);
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
				labList = addTail(labList, value);
			}
			outList(labList);
		}

		break;

		case 3:
		{

		}
		break;


		default:
		{

		}
		break;
		}
	}
}




