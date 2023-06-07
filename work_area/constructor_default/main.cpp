#include <iostream>
using namespace std;

class Employee{

private: // class dışında değiştirilebilir bir argüman olmadığını tanımlıyor. // güvenlik amacıyla değiştirilmesini istemediğimiz argümanlar private yapılır.
	string name;
	int salary;
	int id;
	int number;

public:
	// Employee(){ // bu şekilde tanımlama yapmazsak cpp kendisi default olarak yapı oluşturmaktadır.

	// }
	void setSalary(int maas){
		salary = maas;
	}
	int getSalary(){
		return(salary);
	}
	void setName(string isim){
		name = isim;
	}
	string getName(){
		return (name);
	}

	void showInfos(){
		cout << "Kimlik: " << id << endl;
		cout << "İsim: " << name << endl;
		cout << "Maas: " << salary << endl;
		cout << "Numara: " << number << endl;
	}
};

//g++ main.cpp && ./a.out
int main()
{
	Employee employee;
	employee.showInfos();
	return (0);
}