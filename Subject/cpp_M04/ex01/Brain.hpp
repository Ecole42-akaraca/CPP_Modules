#ifndef BRAIN_HPP
 #define BRAIN_HPP

#include <iostream>

# define BLACK		"\033[0;30m"
# define RED		"\033[0;31m"
# define GREEN		"\033[0;32m"
# define YELLOW		"\033[0;33m"
# define BLUE		"\033[0;34m"
# define PURPLE		"\033[0;35m"
# define CYAN		"\033[0;36m"
# define WHITE		"\033[0;37m"
# define END		"\033[m"
# define RESET		"\033[0m"

class Brain{

private:
	std::string ideas [100];

public:
	Brain( void );
	Brain( const Brain &ref );
	Brain &operator=( const Brain &ref );
	~Brain( void );

	void				setIdea( int const &index, std::string const &idea );
	std::string	const	&getIdea( int const &index ) const;
};

#endif
