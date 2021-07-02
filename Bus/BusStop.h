#pragma once
#include"MyData.h"
#include"Bus_depot.h"
#include"QueuePriority.h"
#include<iomanip>
#include<iostream>
#include<string>

class People
{
	string category;
	int wait = 0;

public:
	People(){}
	People(string c, int t):category(c), wait(t) {}
	int getTimeWait();
	void setTimeWait(int t);

	//PRIORITY getPrioryty() const; //если нужно с приориетом

	friend ostream& operator <<(ostream& out, const People& obj);
};

inline int People::getTimeWait()
{
	return wait;
}

void People::setTimeWait(int t)
{
	wait = t;
}

ostream& operator<<(ostream& out, const People& obj)
{
	out << left << setw(15) << obj.category;// << setw(5) << obj.wait;
	return out;
}

////если нужно с приориетом
//inline PRIORITY People::getPrioryty() const
//{
//
//	if (category == "Пенсионер" || category == "Инвалид")
//		return MEGAHIGH;
//
//	if (category == "Другие")
//		return HIGH;
//
//	if (category == "Ветеран АТО")
//		return MEDIUM;
//	
//	return LOW;
//}

class BusStop
{
	string stopname;
	Queue<People> qpl;
	People currWait;
	//QueueRing<People> qrpl;

public:

	BusStop(string stopname) : stopname(stopname){}
	void addPeople(const People& pl);
	void popPeople(int s);
	void PeopleWait(int t);
	int getSize();
	void start();
	
	
};

inline void BusStop::addPeople(const People &pl)
{
	qpl.push(pl);
}

inline void BusStop::popPeople(int s)
{
	for (size_t i = 0; i < s; i++)
	{
		qpl.pop();
	}
}

inline void BusStop::PeopleWait(int t)
{
	currWait = qpl.peekwait();


	//for (int i = 0; i < qpl.getSize(); i++)
	//{
		currWait.setTimeWait(currWait.getTimeWait() + t);
	//}
	
}


inline int BusStop::getSize()
{
	return qpl.getSize();
}

void BusStop::start()
{			
	system("cls");	

	static int timer = 0;

	cout << "Остановка: " << stopname << endl << endl;
	qpl.print();
	cout << "Кол-во людей в очереди: " << qpl.getSize();
	cout << endl;
	cout << "Максимальное вермя ожидания в очереди: " << timer << " минут";	
	
	//PeopleWait(timer);	
	
	timer++;

	if (!qpl.getSize() || qpl.getSize() == 1)
		timer = 0;
}