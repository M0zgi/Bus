#pragma once

#include<iostream>
using namespace std;


class Bus
{
public:
	int id;
	int number;
	int seats;
	Bus* next = nullptr;

	Bus();
	Bus(int id) : Bus(id, 0, 0) {};
	Bus(int _id, int _number, int _seats);

	//friend void AddEllemArr(Bus*& a, int& _size, Bus _buss);
	//friend void DelEllemArr(Bus*& a, int& _size, int _id);
};


inline Bus::Bus()
{
}

Bus::Bus(int _id, int _number, int _seats)
{
	id = _id;
	number = _number;
	seats = _seats;
}

//inline Bus::Bus()
//{
//}
//
//Bus::Bus(int _id, int _number, int _seats)
//{
//	id = _id;
//	number = _number;
//	seats = _seats;
//}



/*class Bus
{
private:
	
	int id;
	int number;
	int seats;

public:
	Bus();
	Bus(int id) : Bus(id, 0, 0) {};
	Bus(int _id, int _number, int _seats);

	Bus(const Bus& obj);
	Bus& operator=(const Bus& obj);

	void print();

	
	friend void AddEllemArr(Bus*& a, int& _size, Bus _buss);	
	friend void DelEllemArr(Bus*& a, int& _size, int _id);
};

inline Bus::Bus()
{
}

Bus::Bus(int _id, int _number, int _seats)
{
	id = _id;
	number = _number;
	seats = _seats;
}

inline Bus::Bus(const Bus& obj)
{
	id = obj.id;
	number = obj.number;
	seats = obj.seats;
}

inline Bus& Bus::operator=(const Bus& obj)
{
	if (this == &obj)
		return *this;

	id = obj.id;
	number = obj.number;
	seats = obj.seats;
}

inline void Bus::print()
{
	cout << "ID: " << id << " Номер маршрута: " << number << " Кол-во мест: " << seats << endl;
}
*/