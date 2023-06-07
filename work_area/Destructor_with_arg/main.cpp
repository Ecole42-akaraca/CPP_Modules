#include <iostream>

using namespace std;

class Employee{
public:

	string *s;
	int *i;

	Employee(string str, int value){
		s = new string; // yer ayırmak için kullanılmaktadır, malloc kullanmak gibi.
		i = new int;

		*s = str;
		*i = value;

		cout << "Constructor Cağırıldı" << endl;
	}
	void show(){
		cout << "String değeri: " << *s << endl;
		cout << "İnt değeri: " << *i << endl;
	}
	~Employee(){ //delete yapmak için bu yapı gereklidir.
		delete s;
		delete i;
		cout << "Desturctor Çağırıldı" << endl;
	}
};

int main()
{
	Employee *emp = new Employee("Ahmet", 24);
	emp->show();
	delete emp;
	system("leaks a.out");
	return (0);
}