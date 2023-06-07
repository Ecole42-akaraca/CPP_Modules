#include <iostream>

using namespace std;

class Employee{
public:
	Employee(){
		cout << "Constructor Cağırıldı" << endl;
	}
	~Employee(){ //delete yapmak için bu yapı gereklidir.
		cout << "Desturctor Çağırıldı" << endl;
	}
};

int main()
{
	Employee *emp = new Employee();
	delete emp;
	return (0);
}