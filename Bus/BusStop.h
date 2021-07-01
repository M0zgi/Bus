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
	out << left << setw(15) << obj.category << setw(15) << obj.wait;
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


inline int BusStop::getSize()
{
	return qpl.getSize();
}


void BusStop::start()
{			
	system("cls");	

	static int timer = 0;

	cout << "Остановка: " << stopname << endl;
	qpl.print();
	cout << "Кол-во людей в очереди: " << qpl.getSize();
	cout << endl;
	cout << "Максимальное вермя ожидания автобуса: " << timer << " минут";
	timer++;

	if (!qpl.getSize() || qpl.getSize() == 1)
		timer = 0;
}


//class TaskPrint
//{
//private:
//	
//	
//	//string fileName;
//	string department;
//	int timePrint = -1;	
//	
//
//public:
//	TaskPrint() {}
//	TaskPrint(string d, int t) : department(d), timePrint(t) {}
//	int getTimePrint();
//	void setTimePrint(int t);
//	
//	//PRIORITY getPriority() const;//если нужно с приориетом
//
//	friend ostream& operator <<(ostream& out, const TaskPrint& obj);
//
//
//};
//
//int TaskPrint::getTimePrint()
//{
//	return timePrint;
//}
//
//inline void TaskPrint::setTimePrint(int t)
//{
//	timePrint = t;
//}
//
////если нужно с приориетом
////inline PRIORITY TaskPrint::getPriority() const
////{
////	if (department == "Пенсионер" || department == "Инвалид")
////		return MEGAHIGH;
////
////	if (department == "Другие")
////		return HIGH;
////	if (department == "Ветеран АТО")
////		return MEDIUM;
////	return LOW;
////}
//
//ostream& operator<<(ostream& out, const TaskPrint& obj)
//{
//	out << left << setw(15) << obj.department << setw(5) << obj.timePrint;
//	return out;
//}
//
//class PrintServer
//{
//	string ip;
//	//QueuePriority<TaskPrint> qPrint; //если нужно с приоритетом раскомментировать
//	Queue<TaskPrint> qPrint;
//	TaskPrint currPrint;
//
//
//public:
//	PrintServer(string ip) :ip(ip) {}
//	void addTaskPrint(const TaskPrint& tp);
//	void work();
//};
//
////если нужно с приоритетом раскомментировать
////void PrintServer::addTaskPrint(const TaskPrint& tp)
////{
////	qPrint.push(tp, tp.getPriority());
////}
//
//void PrintServer::addTaskPrint(const TaskPrint& tp)
//{
//	qPrint.push(tp);
//}
//
//inline void PrintServer::work()
//{
//
//	if (currPrint.getTimePrint() != -1)
//	{
//		currPrint.setTimePrint(currPrint.getTimePrint() - 1);
//	}
//
//	system("cls");
//	cout << "PrintServer: " << ip << endl;
//	cout << "-------------------------------------" << endl;
//
//	cout << endl << "Printing: " << endl;
//	cout << "----------------------" << endl;
//	if (currPrint.getTimePrint() != -1)
//		cout << currPrint << endl;
//	else
//		cout << endl;
//
//	cout << endl << "Waitings:                     Logs: " << endl;
//	cout << "---------------------------         --------------------" << endl;
//	qPrint.print();
//
//
//	if (!qPrint.isEmpty() && currPrint.getTimePrint() == -1)
//		currPrint = qPrint.pop();
//
//}