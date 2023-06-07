#include "ScavTrap.hpp"

/*
	": ClapTrap()" ifadesi ise, ScavTrap sınıfının ClapTrap sınıfından türediğini gösterir.
	Bu ifade "initialization list" olarak adlandırılan bir yapıya sahiptir ve yapıcı fonksiyonunun başında yer alır.
	":" ifadesinden sonra gelen "ClapTrap()" ifadesi, ScavTrap sınıfının ClapTrap sınıfının yapıcısını çağırdığını belirtir.
	Bu, ScavTrap nesnesi oluşturulurken, ClapTrap sınıfının yapıcısının da çağrılmasını sağlar.

	Bu şekilde, ScavTrap sınıfı, ClapTrap sınıfının özelliklerini de miras alır ve ScavTrap nesnesi oluşturulduğunda, hem ScavTrap sınıfının yapıcısı hem de ClapTrap sınıfının yapıcısı çağrılır.
*/
ScavTrap::ScavTrap( void ): ClapTrap(){

	std::cout << GREEN "--ScavTrap Empty Constructor Called--" END << std::endl;
	this->name = "Default";
	this->hitPoint = 100;
	this->energyPoint = 50;
	this->attackDamage = 20;
}

ScavTrap::ScavTrap( const ScavTrap &ref ): ClapTrap(ref){

	std::cout << GREEN "--ScavTrap Copy Constructor Called--" END << std::endl;
	*this = ref;
}

ScavTrap::ScavTrap( std::string name): ClapTrap(name){

	std::cout << GREEN "--ScavTrap Constructor Called--" END << std::endl;
	this->name = name;
	this->hitPoint = 100;
	this->energyPoint = 50;
	this->attackDamage = 20;
}

ScavTrap& ScavTrap::operator=( const ScavTrap &ref ){

	std::cout << GREEN "--ScavTrap Copy Assignment Operator Called--" END << std::endl;
	if (this != &ref)
	{
		this->name = ref.name;
		this->hitPoint = ref.hitPoint;
		this->energyPoint = ref.energyPoint;
		this->attackDamage = ref.attackDamage;
	}
	return (*this);
}

ScavTrap::~ScavTrap(){

	std::cout << GREEN "--ScavTrap Destructor Called--" END << std::endl;
}

void ScavTrap::guardGate(){

	std::cout << RED "ScavTrap is now in Gate keeper mode." END<< std::endl;
}
