#ifndef SCAVTRAP_HPP
 #define SCAVTRAP_HPP

#include "ClapTrap.hpp"

/*
	Sanal(Virtual) kalıtım, temel sınıfın üye değişkenlerinin yalnızca bir kopyasının torundan türetilmiş sınıflar tarafından miras alınmasını sağlayan bir C++ tekniğidir.
	Sanal temel sınıflar, sanal kalıtımda, birden çok kalıtım kullanılırken bir kalıtım hiyerarşisinde görünen belirli bir sınıfın birden çok "örneklerinin" önlenmesi için kullanılır.
*/
class ScavTrap : virtual public ClapTrap
{
public:
	ScavTrap( void ); // default constructor
	ScavTrap( const ScavTrap &ref ); // copy constructor.
	ScavTrap( std::string name ); // Name, which is passed as parameter to a constructor
	ScavTrap &operator=( const ScavTrap &ref ); // copy assignment operator overload.
	~ScavTrap(); // destructor.

	void	guardGate();
};

#endif
