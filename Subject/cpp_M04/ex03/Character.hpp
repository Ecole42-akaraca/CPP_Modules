#ifndef CHARACTER_HPP
 #define CHARACTER_HPP

#include "ICharacter.hpp"
#include <iostream>

class Character : public ICharacter {

	private:
		std::string	_name;
		AMateria	*_inventory[4];
	public:
		Character();
		Character( std::string const &name );
		Character( Character const &ref );
		Character &operator=( Character const &ref );
		~Character();

		std::string const	&getName() const;
		void				equip( AMateria *m );
		void				unequip( int idx );
		void				use( int idx, ICharacter &target );
};

#endif
