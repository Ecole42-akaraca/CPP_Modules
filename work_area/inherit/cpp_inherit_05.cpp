#include <iostream>

class ClapTrap {
protected:
	int a;
public:
    ClapTrap() : hitPoints(100), name("ClapTrap") {}
    int hitPoints;
    std::string name;

};

class ScavTrap : protected ClapTrap {
public:
    ScavTrap() : ClapTrap(){}
	void test() {
	    
	    printf("%d\n", hitPoints);
	    printf("%d\n", a);
	};
    std::string scavAttribute;
};

class FragTrap : public ScavTrap {
public:
    FragTrap() : ScavTrap(){}
	void test2(){
	    
	   printf("%d\n", hitPoints);  
	   printf("%d\n", a);
	};
    std::string fragAttribute;
};


int main() {

    
    ScavTrap b;
    b.test();
//    b.hitPoints = 1000;
  //  printf("%d\n", b.hitPoints);

    FragTrap a;
    
    a.test2();
    return 0;
}