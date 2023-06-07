#ifndef FRAGTRAP_HPP
 #define FRAGTRAP_HPP

#include "ClapTrap.hpp"

class FragTrap : public ClapTrap
{
public:
	FragTrap( void ); // default constructor
	FragTrap( const FragTrap &ref ); // copy constructor.
	FragTrap( std::string name ); // Name, which is passed as parameter to a constructor
	FragTrap &operator=( const FragTrap &ref ); // copy assignment operator overload.
	~FragTrap(); // destructor.

	void	highFivesGuys(void);
};

#endif
