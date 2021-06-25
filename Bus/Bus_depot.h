#pragma once
#include"Bus.h"
#include <Windows.h>

struct numpunct
	: std::numpunct<char>
{
	std::string do_truename() const { return "правда"; }
	std::string do_falsename() const { return "враньё"; }
};

class BusDepot
{
private:
	//Bus* buss = nullptr;
	Bus* first = nullptr;
	Bus* last = nullptr;
	int size = 0;


public:
	~BusDepot();
	void menu();
	void print();
	void push_back(Bus _a);
	Bus pop();
	//Bus pop_id(int _id);
	void clear();
};

BusDepot::~BusDepot()
{
   clear();
}

inline void BusDepot::menu()
{
	while (true)
	{
		system("cls");
		cout << "1. Добавить автобус на маршрут.\n";
		cout << "2. Снять автобус с маршрута (первый в очереди).\n";
		//cout << "3. Снять автобус с маршрута (по ID).\n";
		cout << "3. Показать автобусы на маршруте.\n";
		cout << "4. Выход.\n\n";

		int n;

		cout << "Введите номер Меню: ";
		cin >> n;

		switch (n)
		{

		case 1:
		{		
			system("cls");
			int id;
			int number;
			int seats;

			cout << "Добавление автобуса на маршрут.\n";
			cout << "ID: ";
			cin >> id;
			cout << "Номер маршрута: ";
			cin >> number;
			//cout << "Кол-во пассажирских мест: ";
			//cin >> seats;

			seats = rand() % 25; //кол-во мест, случайная величина

			Bus a(id, number, seats);

			push_back(a);
			
			break;
		}
		case 2:
		{
			pop();
			break;
		}
	/*	case 3:
		{
			system("cls");
			int id;

			cout << "Снять автобус с маршрута (по ID).\n";
			cout << "Введите ID: ";
			cin >> id;

			pop_id(id);

			break;
		}*/

		case 3:
		{
			print();
			system("pause");
			break;
		}			

		case 4:
			exit(0);

		default:
			break;
		}
	}
}

inline void BusDepot::print()
{
	system("cls"); 
	
	cout << "-------- Список автобусов на маршруте --------\n\n";

	if (size > 0)
	{
		Bus* temp = first;
		while (temp)
		{
			cout << "ID: " << temp->id << " Номер маршрута: " << temp->number << " Кол-во мест: " << temp->seats << endl;
			temp = temp->next;
		}
		cout << endl;
	}

	else
		cout << "На маршруте нет автобусов!\nНо это легко исправить. Меню -> 1\n\n";
	
}

inline void BusDepot::push_back(Bus _a)
{
	if (size == 0)
	{
		first = new Bus;
		first->id = _a.id;
		first->number = _a.number;
		first->seats = _a.seats;
		last = first;
	}

	else
	{
		Bus* temp = new Bus;

		temp->id = _a.id;
		temp->number = _a.number;
		temp->seats = _a.seats;

		last->next = temp;
		last = temp;
	}

	size++;
}

inline Bus BusDepot::pop()
{
	if (size == 0)
	{
		cout << "Oops!!! На маршруте нет автобусов!";
		cout << endl;
		system("pause");
		exit(1);
	}

	Bus id = first->id;

	if (size == 1)
	{
		delete first;
		first = last = nullptr;
	}

	else
	{
		Bus* temp = first;
		first = first->next;
		delete temp;
	}

	size--;

	return id;
}

//inline Bus BusDepot::pop_id(int _id)
//{
//	if (size == 0)
//	{
//		cout << "Очередь пустая!";
//		system("pause");
//		exit(1);
//	}
//
//	int id = _id;
//
//	if (size == 1)
//	{
//		delete first;
//		first = last = nullptr;
//		size--;
//	}
//
//
//	else
//	{		
//		Bus* temp = first;
//		while (temp)
//		{
//			if (temp->id == _id)
//			{
//				Bus* temp1 = temp->next;
//				delete temp;
//				first->next = temp1;
//				size--;
//				return id;
//			}
//
//			else
//			temp = temp->next;
//		}
//		
//		cout << "Автобуса с указанным ID не найдено на маршруте!";
//		
//	}
//
//	return id;
//}

inline void BusDepot::clear()
{
	while (size)
		pop();
	first = last = nullptr;
}