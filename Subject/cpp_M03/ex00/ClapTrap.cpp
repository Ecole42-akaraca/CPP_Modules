#include "ClapTrap.hpp"

ClapTrap::ClapTrap( void ){

	std::cout << GREEN "--ClapTrap Empty Constructor Called--" END << std::endl;
	this->name = "Default";
	this->hitPoint = 10;
	this->energyPoint = 10;
	this->attackDamage = 0;
}

ClapTrap::ClapTrap( const ClapTrap &ref ){

	std::cout << GREEN "--ClapTrap Copy Constructor Called--" END << std::endl;
	*this = ref;
}

ClapTrap::ClapTrap( std::string name ){

	std::cout << GREEN "--ClapTrap Constructor Called--" END << std::endl;
	this->name = name;
	this->hitPoint = 10;
	this->energyPoint = 10;
	this->attackDamage = 0;
}

ClapTrap& ClapTrap::operator=( const ClapTrap &ref ){

	std::cout << GREEN "--ClapTrap Copy Assignment Operator Called--" END << std::endl;
	if (this != &ref)
	{
		this->name = ref.name;
		this->hitPoint = ref.hitPoint;
		this->energyPoint = ref.energyPoint;
		this->attackDamage = ref.attackDamage;
	}
	return (*(this));
}

ClapTrap::~ClapTrap( void ){

	std::cout << GREEN "--ClapTrap Destructor Called--" END << std::endl;
}

void	ClapTrap::attack( const std::string &target ){

if (this->hitPoint == 0)
{
	std::cout << RED << this->name << " is already dead!" END << std::endl;
}
else if (this->energyPoint > 0)
{
	std::cout << YELLOW "ClapTrap ";
	std::cout << this->name;
	std::cout << " attacks ";
	std::cout << target;
	std::cout << ", causing ";
	std::cout << this->attackDamage;
	std::cout << " points of damage!" END << std::endl;

	if (this->energyPoint > 1)
		this->energyPoint -= 1;
	else
		this->energyPoint = 0;
	std::cout << YELLOW << this->name << " has " << this->energyPoint << " energy points left." END << std::endl;
}
else
	std::cout << RED << this->name << " hasn't not enough energy!" END << std::endl;
}

/*
	-> amount parametresinin unsigned tipinde kullanılmasının nedeni, eski bir değer almaması içindir.
*/
void	ClapTrap::takeDamage( unsigned int amount ){

if (this->hitPoint == 0)
{
	std::cout << RED << this->name << " is already dead!" END << std::endl;
}
else
{	
	std::cout << BLUE "ClapTrap ";
	std::cout << this->name;
	std::cout << " take ";
	std::cout << amount;
	std::cout << " points of damage!" END << std::endl;

	if (this->hitPoint >= amount)
		this->hitPoint -= amount;
	else
		this->hitPoint = 0;
	std::cout << BLUE << this->name << " has " << this->hitPoint << " hit points left." END << std::endl;
	if (this->hitPoint == 0)
		std::cout << RED << this->name << " is dead!" END << std::endl;
}

}

void	ClapTrap::beRepaired( unsigned int amount ){

if (this->hitPoint == 0)
{
	std::cout << RED << this->name << " is already dead!" END << std::endl;
}
else if (this->energyPoint > 0)
{
	std::cout << PURPLE "ClapTrap ";
	std::cout << this->name;
	std::cout << " self repaired ";
	std::cout << amount;
	std::cout << " points!" END << std::endl;

	if (this->energyPoint > 1)
		this->energyPoint -= 1;
	else
		this->energyPoint = 0;
	this->hitPoint += amount;

	std::cout << PURPLE << this->name << " has " << this->hitPoint << " hit points left." END << std::endl;
	std::cout << PURPLE << this->name << " has " << this->energyPoint << " energy points left." END << std::endl;
}
else
	std::cout << RED << this->name << " hasn't not enough energy!" END << std::endl;

}

int	ClapTrap::getDamage(){

	return (this->attackDamage);
}
