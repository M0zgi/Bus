#pragma once
#include"Bus.h"
#include"QueuePriority.h"
#include <Windows.h>
#include<iomanip>
#include<string>


void gotoxy(int x, int y)
{
	COORD coord;
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

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
	string BusDepotName;
	Bus* first = nullptr;
	Bus* last = nullptr;
	int size = 0;


public:
	~BusDepot();
	BusDepot(string BusDepotName) :BusDepotName(BusDepotName) {}
	void print();
	void print_first();
	void push_back(Bus _a);
	Bus pop();
	Bus pop_queue();
	int getseats();
	//Bus pop_id(int _id);
	Bus operator[](int ind);
	void clear();
};

BusDepot::~BusDepot()
{
   clear();
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

inline void BusDepot::print_first()
{
	
	gotoxy(40, 1);
	cout << "-------- Приехал автобус --------\n\n";

	if (size > 0)
	{
		Bus* temp = first;
		while (temp)
		{
			gotoxy(40, 2);
			cout << "ID: " << temp->id << " Номер маршрута: " << temp->number << " Кол-во мест: " << temp->seats << endl;
			temp = nullptr;
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

inline Bus BusDepot::pop_queue()
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
		return id;
	}

	else
	{
		Bus* temp = first;
		first = first->next;
		last->next = temp;
		last = temp;
		temp->next = nullptr;
	}	

	return id;
}

inline int BusDepot::getseats()
{
	return first->seats;
}

inline Bus BusDepot::operator[](int ind)
{
	Bus* temp = first;
	
	for (size_t i = 0; i < ind; i++)
	{
		temp = temp->next;
	}

	return temp->id;
}

inline void BusDepot::clear()
{
	while (size)
		pop();
	first = last = nullptr;
}