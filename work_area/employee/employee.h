#ifndef EMPLOYEE_H_
# define EMPLOYEE_H_
#include <iostream>
using namespace std; //stringin çalışması için eklenmelidir.

class Employee{
public:
	string name;
	int id;
	int salary;

	void showInfos();
};

#endif