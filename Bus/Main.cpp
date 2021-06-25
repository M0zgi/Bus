//#include"MyData.h"
//#include"Queue.h"
//#include"TemplateArray.h"
#include"Bus_depot.h"
//#include"Bus.h"

int main()
{

	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	std::cout.setf(std::ios_base::boolalpha);

	locale loc(cout.getloc(), new ::numpunct);
	cout.imbue(loc);

	BusDepot b;

	b.menu();



	cout << endl;
	system("pause");
}