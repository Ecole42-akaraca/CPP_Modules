#include <iostream>
using namespace std;

class Employee{
private:
	string name;
	int age;
	int salary;
public:
	Employee(string name, int age, int salary){
		this->name = name;
		this->age = age;
		this->salary = salary;
	}
	friend void showInfos(Employee emp); // private argümanlara fonksiyonlar tarafından erişmek için.
};

void showInfos(Employee emp){
	cout << emp.name << " " << emp.age << " " << emp.salary << endl; 
}

int main()
{
	Employee emp("ahmet", 25, 3000);
	showInfos(emp);
	return (0);
}