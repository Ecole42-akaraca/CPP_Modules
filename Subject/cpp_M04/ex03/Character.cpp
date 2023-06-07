#include "Character.hpp"

Character::Character(){
	std::cout << "Character Default Constructor Called" << std::endl;
	this->_name = "Default";
	for(int i = 0; i < 4; i++){
		this->_inventory[i] = NULL;
	}
}

Character::Character( std::string const &name ){
	std::cout << "Character Constructor Called" << std::endl;
	this->_name = name;
	for(int i = 0; i < 4; i++){
		this->_inventory[i] = NULL;
	}
}

Character::Character( Character const &ref ){
	std::cout << "Character Copy Constructor Called" << std::endl;
	this->_name = ref._name;
	for(int i = 0; i < 4; i++){
		this->_inventory[i] = ref._inventory[i];
	}
}

Character &Character::operator=( Character const &ref ){
	std::cout << "Character Copy Assignment Operator Called" << std::endl;
	if (this != &ref)
	{
		this->_name = ref._name;
		for(int i = 0; i < 4; i++){
			delete this->_inventory[i];
			this->_inventory[i] = ref._inventory[i];
		}
	}
	return (*this);
}

Character::~Character(){
	std::cout << "Character Destructor Called" << std::endl;
	for (int i = 0; i < 4; i++)
	{
		if (this->_inventory[i])
			delete this->_inventory[i];
	}
}

std::string const &Character::getName() const{
	return (this->_name);
}

void	Character::equip( AMateria *m ){

	for(int i = 0; i < 4; i++)
	{
		if (this->_inventory[i] == NULL)
		{
			int x = 0;
			while (x < 4 && (this->_inventory[x] == NULL || this->_inventory[x] != m)) // aynı materia'dan equip fonksiyonun kullanılmasını engellemek için koydum.
				x++;
			if (x == 4)
				this->_inventory[i] = m;
		}
	}
}

void	Character::unequip( int idx ){
	
	if (idx >= 0 && idx <= 3)
	{
		if (this->_inventory[idx] != NULL)
		{
			// delete this->_inventory[idx];
			this->_inventory[idx] = NULL;
		}
	}
}

void	Character::use( int idx, ICharacter &target ){

	if (idx >= 0 && idx <= 3 && this->_inventory[idx])
	{
		this->_inventory[idx]->use(target);
	}
}