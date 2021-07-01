#include"Bus_depot.h"
#include"BusStop.h"

#include<iostream>
using namespace std;
//#include"Bus.h"

int main()
{

	

	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	std::cout.setf(std::ios_base::boolalpha);

	locale loc(cout.getloc(), new ::numpunct);
	cout.imbue(loc);

	//string fName[] = { "zvit.xls", "otchet.doc", "file1.txt", "foto.jpg", "presentation.ppt" };
	string cat[] = { "Ветеран АТО", "Пенсионер", "Ученик", "Инвалид", "Другие" };

	int timebus = 0;
	
	string stopname;
	cout << "Введите название остановки: ";
    getline(cin, stopname);

	string compname;
	cout << "Введите название компании: ";
	getline(cin, compname);

	BusStop bs(stopname);
	BusDepot bd(compname);

	while (true)
	{
		system("cls");

		cout << "Остановка: " << stopname << "Обслуживающая компания: " << compname << endl;
		cout << "1. Добавить автобус на маршрут.\n";
		cout << "2. Снять автобус с маршрута (первый в очереди).\n";
		//cout << "3. Снять автобус с маршрута (по ID).\n";
		cout << "3. Показать движение автобусов по маршруту.\n";
		cout << "4. Показать автобусы на маршруте.\n";
		cout << "5. Выход.\n\n";

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
			cout << "Кол-во пассажирских мест: ";
			cin >> seats;

			//seats = rand() % 25; //кол-во мест, случайная величина

			Bus a(id, number, seats);

			bd.push_back(a);


			break;
		}
		case 2:
		{
			bd.pop();
			//pop_queue();
			break;
		}


		case 3:
		{			
			system("cls");					
			
			int t = 0;

			while (true)
			{
				if (t!=0 && t % 30 == 0)
				{
					
					int freeseats = bd.getseats() % 1 + 10;				
				
					gotoxy(40, 5);
					bd.print_first();		
					
					cout << bd[0].seats;
					if (bs.getSize() > freeseats)
					{
						bs.popPeople(freeseats);
					}

					else 					
					{
						bs.popPeople(bs.getSize());
					}
										
					bd.pop_queue();
				}
				
				int m = rand() % 1 + 5;				

				if (t % m == 0)					

				bs.addPeople(People(cat[rand() % 5], 0));

				bs.start();
				t++;
				Sleep(1000);
			}

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

		case 4:
		{
			bd.print();
			system("pause");
			break;
		}

		case 5:
			exit(0);

		default:
			break;
		}
	}

	cout << endl;
	system("pause");
}