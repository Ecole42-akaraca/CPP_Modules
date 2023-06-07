#include "Brain.hpp"

Brain::Brain( void ){

	std::cout <<GREEN "--Brain Default Constructor Called--" END<< std::endl;
}

Brain::Brain( const Brain &ref ){

	std::cout <<GREEN "--Brain Copy Constructor Called--" END<< std::endl;
	int	i = -1;
	while (++i < 100)
	{
		this->ideas[i] = ref.ideas[i];
	}
}

Brain &Brain::operator=( const Brain &ref ){

	std::cout <<GREEN "--Brain Copy Assignment Consturtor Called--" END<< std::endl;
	if (this != &ref)
	{
		int	i = -1;
		while (++i < 100)
		{
			this->ideas[i] = ref.ideas[i];
		}
	}
	return (*this);
}

Brain::~Brain( void ){

	std::cout <<GREEN "--Brain Destructor Called--" END<< std::endl;
}

void	Brain::setIdea( int const &index, std::string const &idea ){

	if (index >= 0 && index < 100)
		this->ideas[index] = idea;
}

std::string	const &Brain::getIdea( int const &index ) const{

	if (index >= 0 && index < 100)
		return (this->ideas[index]);
	return (this->ideas[0]);
}
