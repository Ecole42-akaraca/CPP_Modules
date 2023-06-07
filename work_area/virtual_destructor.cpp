#include <iostream>
using namespace std;

class Base {
public:
  Base() {
    cout << "Base constructor is called." << endl;
  }

/*
Virtual olur ise çıktısı:
	Base constructor is called.
	Derived constructor is called.
	Derived destructor is called.
	Base destructor is called.

Virtual olmaz ise çıktısı:
	Base constructor is called.
	Derived constructor is called.
	Base destructor is called.

base class için delete kullandığımızda virtual yapıya sahip olmaz ise leak oluşturur.

*/

  virtual ~Base() {// ~Base() {
    cout << "Base destructor is called." << endl;
  }
};

class Derived : public Base {
public:
  Derived() {
    cout << "Derived constructor is called." << endl;
  }
  ~Derived() {
    cout << "Derived destructor is called." << endl;
  }
};

int main() {
  Base* b = new Derived();
  delete b;
  return 0;
}
