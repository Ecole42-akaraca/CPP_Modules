#include "employee.h"

void Employee::showInfos(){
	cout << "Id: " << Employee::id << endl;
	cout << "Isim: " << Employee::name << endl;
	cout << "Maas: " << Employee::salary << endl;
}
