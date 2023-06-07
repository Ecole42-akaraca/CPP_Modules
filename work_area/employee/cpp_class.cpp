#include <iostream>
using namespace std;

#include "employee.h" // g++ cpp_class.cpp employee.cpp  && ./a.out

class ogrenci{
public: //heryerden erişebilmek için public yapılmalıdır.
	string name;

	void tellName(){
		cout << "Kek istiyorum " << name << endl;
	}
};

int main()
{
	ogrenci one;
	ogrenci two;
	one.name = "Umut";
	two.name = "BATumut";
	cout << "one: " << one.name << endl;
	cout << "two: " << two.name << endl;
	one.tellName(); // içerdeki fonksiyon çalışıyor.
	two.tellName();

	cout << "---------------------------------" << endl;
	Employee employee;

	employee.id = 12;
	employee.name = "Son Umut";
	employee.salary = 3000;
	employee.showInfos();
	return (0);
}