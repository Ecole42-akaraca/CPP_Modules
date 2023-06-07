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
	friend class Test; // private argümanlara classlar tarafından erişmek için.
};

class Test{
public:
	static void showInfos(Employee emp){
		cout << emp.name << " " << emp.age << " " << emp.salary << endl; 
	}
};


int main()
{
	Employee emp("ahmet", 25, 3000);
	Test::showInfos(emp);
	return (0);
}