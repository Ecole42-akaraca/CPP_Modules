#ifndef DIAMONDTRAP_HPP
 #define DIAMONDTRAP_HPP

#include "FragTrap.hpp"
#include "ScavTrap.hpp"

class DiamondTrap : public ScavTrap, public FragTrap //Child inherits Father and Mother
{
private:
	std::string name;

public:
	DiamondTrap( void ); // default constructor
	DiamondTrap( const DiamondTrap &ref ); // copy constructor.
	DiamondTrap( std::string name ); // Name, which is passed as parameter to a constructor
	DiamondTrap &operator=( const DiamondTrap &ref ); // copy assignment operator overload.
	~DiamondTrap(); // destructor.

	void	attack( const std::string &target );
	void	whoAmI();
};

#endif
