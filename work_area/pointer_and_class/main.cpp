#include <iostream>
using namespace std;

class Employee{

private: // class dışında değiştirilebilir bir argüman olmadığını tanımlıyor. // güvenlik amacıyla değiştirilmesini istemediğimiz argümanlar private yapılır.
	string name;
	int age;

public:
	void setAge(int yas){
		if (yas < 0)
		{
			cout << "Yas değeri 0'dan küçük girildi" << endl;
			age = -1;
		}
		else
			age = yas;
	}
	int getAge(){
		return (age);
	}
	void setName(string isim){
		name = isim;
	}
	string getName(){
		return (name);
	}
};


//g++ main.cpp && ./a.out
int main()
{
	Employee *employee = new Employee(); //pointer yapısında employee oluşturmak için, bu yapı kullanılıyor.

	employee->setName("Ahmet KARACA");
	employee->setAge(24);
	cout << employee->getName() << endl;
	cout << employee->getAge() << endl;

	return (0);
}