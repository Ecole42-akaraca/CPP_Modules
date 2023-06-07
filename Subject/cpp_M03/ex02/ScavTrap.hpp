#ifndef SCAVTRAP_HPP
 #define SCAVTRAP_HPP

#include "ClapTrap.hpp"

/*
	ScavTrap'in ClapTrap'ten kalıtılması için ": public ClapTrap" şeklinde tanımlanması gerekiyor.

	private kalıtım: Türetilen sınıfın üyelerinin, temel sınıftan özgülenmiş olacağı ve temel sınıfın üyelerine sadece türetilen sınıfın üyeleri tarafından erişilebileceği anlamına gelir.
	Bu durumda, ScavTrap sınıfı, ClapTrap sınıfını özgülemiş olduğundan, ClapTrap sınıfındaki üyeleri kendi üyeleri gibi kullanabilir, ancak ClapTrap sınıfından kalıtım alan başka sınıflar bu üyelere erişemez.
	Örneğin, ScavTrap sınıfında ClapTrap sınıfındaki protected ve public üyelere erişilebilir.
	Ancak, ScavTrap sınıfından kalıtım alan başka bir sınıf, ClapTrap sınıfının protected ve public üyelerine erişemez.
	Bu, türetilen sınıfın bir temel sınıfın özelliklerini kullanmasını sağlar, ancak temel sınıfın diğer sınıflar tarafından kullanılmasını engeller. 

	protected kalıtım: Türetilen sınıfın üyelerinin, temel sınıftan özgülenmiş olacağı ve türetilen sınıfın üyeleri ile temel sınıftaki protected ve public üyelerine erişebileceği anlamına gelir.
	Bu durumda, ScavTrap sınıfı, ClapTrap sınıfını özgülemiş olduğundan, ClapTrap sınıfındaki protected ve public üyeleri kendi üyeleri gibi kullanabilir.
	Ayrıca, ScavTrap sınıfından kalıtım alan başka bir sınıf, ClapTrap sınıfındaki protected üyelerine de erişebilir.
	Ancak, ClapTrap sınıfındaki private üyeler ScavTrap ve diğer türetilen sınıflar tarafından erişilemez.

	public kalıtım: Temel sınıftaki public ve protected üyelerin türetilen sınıfın üyeleri gibi kullanılacağı anlamına gelir.
	Bu durumda, ScavTrap sınıfı ClapTrap sınıfını public olarak özgülemiş olduğundan, ScavTrap sınıfı ClapTrap sınıfındaki public ve protected üyelere erişebilir.
*/
class ScavTrap : public ClapTrap
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
