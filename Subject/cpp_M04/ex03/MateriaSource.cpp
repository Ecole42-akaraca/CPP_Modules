#include "MateriaSource.hpp"

MateriaSource::MateriaSource(){
	std::cout << "MateriaSource Default Constructor Called" << std::endl;
	for(int i = 0; i < 4; i++)
	{
		this->_materias[i] = NULL;
	}
}

MateriaSource::MateriaSource( const MateriaSource &ref ){
	std::cout << "MateriaSource Copy Constructor Called" << std::endl;
	for(int i = 0; i < 4; i++)
	{
		this->_materias[i] = ref._materias[i];
	}
}

MateriaSource::~MateriaSource(){
	std::cout << "MateriaSource Destructor Called" << std::endl;
	for(int i = 0; i < 4; i++)
	{
		delete this->_materias[i];
	}
}

MateriaSource &MateriaSource::operator=( const MateriaSource &ref ){
	std::cout << "MateriaSource Assignment Operator Called" << std::endl;
	if (this != &ref)
	{
		for(int i = 0; i < 4; i++)
		{
			delete this->_materias[i];
			this->_materias[i] = ref._materias[i];
		}	
	}
	return (*this);
}

void	MateriaSource::learnMateria( AMateria *materia ){

	for(int i = 0; i < 4; i++)
	{
		if (!this->_materias[i])
		{
			this->_materias[i] = materia;
			return ;
		}
	}
	delete materia; // materiasource dolu ise materia envatere alınmayacak ve leak oluşturacak. Bu yüzden delete edilmelidir.
}

AMateria	*MateriaSource::createMateria( const std::string &type ){

	for(int i = 0; i < 4; i++)
	{
		if (this->_materias[i] != NULL && this->_materias[i]->getType() == type)
		{
			return (this->_materias[i]->clone());
		}	
	}
	return (NULL);
}
