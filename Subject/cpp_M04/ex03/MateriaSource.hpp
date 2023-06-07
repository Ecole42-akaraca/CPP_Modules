#ifndef MATERIASOURCE_HPP
 #define MATERIASOURCE_HPP

#include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource{

	private:
		AMateria	*_materias[4];
	public:
		MateriaSource();
		MateriaSource( const MateriaSource &ref );
		~MateriaSource();

		MateriaSource &operator=( const MateriaSource &ref );

		void		learnMateria( AMateria *);
		AMateria	*createMateria( const std::string  &type );
};

#endif