#include "DiamonTrap.hpp"

DiamondTrap::DiamondTrap( void ): ClapTrap(), ScavTrap(), FragTrap(){

	std::cout << GREEN "--DiamondTrap Empty Constructor Called--" END << std::endl;
	this->name = "Default";
	ClapTrap::name += "_clap_name";
	this->hitPoint = FragTrap::hitPoint;
	this->energyPoint = ScavTrap::energyPoint;
	this->attackDamage = FragTrap::attackDamage;
}

DiamondTrap::DiamondTrap( const DiamondTrap &ref ): ClapTrap(ref), ScavTrap(ref), FragTrap(ref){

	std::cout << GREEN "--DiamondTrap Copy Constructor Called--" END << std::endl;
	*this = ref;
}

DiamondTrap::DiamondTrap( std::string name): ClapTrap(name), ScavTrap(name), FragTrap(name){

	std::cout << GREEN "--DiamondTrap Constructor Called--" END << std::endl;
	this->name = name;
	ClapTrap::name += "_clap_name";
	this->hitPoint = FragTrap::hitPoint;
	this->energyPoint = ScavTrap::energyPoint;
	this->attackDamage = FragTrap::attackDamage;
}

DiamondTrap& DiamondTrap::operator=( const DiamondTrap &ref ){

	std::cout << GREEN "--DiamondTrap Copy Assignment Operator Called--" END << std::endl;
	if (this != &ref)
	{
		this->name = ref.name;
		this->hitPoint = ref.hitPoint;
		this->energyPoint = ref.energyPoint;
		this->attackDamage = ref.attackDamage;
	}
	return (*this);
}

DiamondTrap::~DiamondTrap(){

	std::cout << GREEN "--DiamondTrap Destructor Called--" END << std::endl;
}

void	DiamondTrap::attack( const std::string &target ){

	ScavTrap::attack(target);
}

void	DiamondTrap::whoAmI(){

	std::cout << "DiamonTrap name: " << this->name << std::endl;
	std::cout << "ClapTrap name: " << ClapTrap::name << std::endl;
}
