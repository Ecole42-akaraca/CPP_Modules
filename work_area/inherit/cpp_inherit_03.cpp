#include <iostream>

class ClapTrap {
public:
    ClapTrap() : hitPoints(100), name("ClapTrap") {}
    int hitPoints;
	int a;
    std::string name;
};

class ScavTrap : virtual public ClapTrap {
public:
    ScavTrap() : ClapTrap(), scavAttribute("ScavTrap") {}
	int a;
    std::string scavAttribute;
};

class FragTrap : virtual public ClapTrap {
public:
    FragTrap() : ClapTrap(), fragAttribute("FragTrap") {}
	int a;
    std::string fragAttribute;
};

class DiamondTrap : public ScavTrap, public FragTrap {
public:
    DiamondTrap() : ClapTrap(), ScavTrap(), FragTrap(), name("DiamondTrap"){}
	int a;
    std::string name;
};

int main() {
    DiamondTrap dt;
    std::cout << dt.ScavTrap::name << std::endl; // Output: ScavTrap
    std::cout << dt.FragTrap::name << std::endl; // Output: FragTrap
    std::cout << dt.name << std::endl; // Output: DiamondTrap
    return 0;
}