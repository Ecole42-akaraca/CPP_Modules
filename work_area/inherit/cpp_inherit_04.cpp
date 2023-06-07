#include <iostream>

class ClapTrap {
public:
    ClapTrap() : hitPoints(100), name("ClapTrap") {}
    int hitPoints;
	int a;
    std::string name;
};

class ScavTrap : private ClapTrap {
public:
    ScavTrap() : ClapTrap(){}
	int a;
	void test() {
	    
	    printf("%d\n", hitPoints);
	};
    std::string scavAttribute;
};

class FragTrap : public ScavTrap {
public:
    FragTrap() : ScavTrap(){}
	int a;
	void test2(){
	    
	   printf("%d\n", hitPoints);  
	};
    std::string fragAttribute;
};


int main() {

    
    ScavTrap b;
    b.test();
//    b.hitPoints = 1000;
  //  printf("%d\n", b.hitPoints);

    //FragTrap a;
    
  //  a.hitPoints = 1200;
//    printf("%d\n", a.hitPoints);
    return 0;
}