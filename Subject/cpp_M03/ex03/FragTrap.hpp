#ifndef FRAGTRAP_HPP
 #define FRAGTRAP_HPP

#include "ClapTrap.hpp"

/*
	Sanal(Virtual) kalıtım, temel sınıfın üye değişkenlerinin yalnızca bir kopyasının torundan türetilmiş sınıflar tarafından miras alınmasını sağlayan bir C++ tekniğidir.
	Sanal temel sınıflar, sanal kalıtımda, birden çok kalıtım kullanılırken bir kalıtım hiyerarşisinde görünen belirli bir sınıfın birden çok "örneklerinin" önlenmesi için kullanılır.
*/
class FragTrap : virtual public ClapTrap
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
