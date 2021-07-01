#include"Bus_depot.h"
#include"BusStop.h"

#include<ctime>
#include<iostream>
using namespace std;
//#include"Bus.h"

int main()
{

	srand(time(0));

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

		cout << "Остановка: " << stopname << "\nОбслуживающая компания: " << compname << endl;
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

			Bus a(id, number, seats);

			bd.push_back(a);


			break;
		}
		case 2:
		{
			bd.pop();
			break;
		}


		case 3:
		{			
			system("cls");					
			
			int t = 0;
			char Stop = '1';

			do {

				int m = rand() % 1 + 2;

				if (t % m == 0)

					bs.addPeople(People(cat[rand() % 5], 0));

				bs.start();

				if (t != 0 && t % 30 == 0)
				{

					int freeseats = bd.getseats() - rand() % 7;

					bd.print_first();

					gotoxy(40, 4);
					cout << "Кол-во свободных мест: " << freeseats << endl << endl;
					
					//system("pause");

					if (bs.getSize() > freeseats)
					{
						bs.popPeople(freeseats);
					}

					else
					{
						bs.popPeople(bs.getSize());
					}

					bd.pop_queue();
					gotoxy(40, 6);
					cout << "Укажите 0 для возврата к меню: ";
					cin >> Stop;
				}

				t++;
				Sleep(1000);

				

				

			} while (Stop != '0');

		

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