#include "FragTrap.hpp"

FragTrap::FragTrap( void ): ClapTrap(){

	std::cout << GREEN "--FragTrap Empty Constructor Called--" END << std::endl;
	this->name = "Default";
	this->hitPoint = 100;
	this->energyPoint = 50;
	this->attackDamage = 20;
}

FragTrap::FragTrap( const FragTrap &ref ): ClapTrap(ref){

	std::cout << GREEN "--FragTrap Copy Constructor Called--" END << std::endl;
	*this = ref;
}

FragTrap::FragTrap( std::string name): ClapTrap(name){

	std::cout << GREEN "--FragTrap Constructor Called--" END << std::endl;
	this->name = name;
	this->hitPoint = 100;
	this->energyPoint = 100;
	this->attackDamage = 30;
}

FragTrap& FragTrap::operator=( const FragTrap &ref ){

	std::cout << GREEN "--FragTrap Copy Assignment Operator Called--" END << std::endl;
	if (this != &ref)
	{
		this->name = ref.name;
		this->hitPoint = ref.hitPoint;
		this->energyPoint = ref.energyPoint;
		this->attackDamage = ref.attackDamage;
	}
	return (*this);
}

FragTrap::~FragTrap(){

	std::cout << GREEN "--FragTrap Destructor Called--" END << std::endl;
}

void FragTrap::highFivesGuys( void ){

	std::cout << GREEN "FragTrap is doing highFive!" END << std::endl;
}
