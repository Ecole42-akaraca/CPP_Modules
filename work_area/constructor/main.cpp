#include <iostream>
using namespace std;

class Employee{

private: // class dışında değiştirilebilir bir argüman olmadığını tanımlıyor. // güvenlik amacıyla değiştirilmesini istemediğimiz argümanlar private yapılır.
	string name;
	int salary;
	int id;
	int number;

public:
	Employee(string isim, int maas, int kimlik, int number){
		name = isim;
		salary = maas;
		id = kimlik;
		this->number = number; // aynı isimler kullanılırsa "this->" şeklinde pointer kullanılmalıdır.
	}
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
	Employee employee("Ahmet KARACA", 2400, 12, 7);

	employee.showInfos();
	return (0);
}