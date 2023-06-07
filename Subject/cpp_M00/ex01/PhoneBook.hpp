#ifndef PHONEBOOK_HPP_
# define PHONEBOOK_HPP_

#include "Contact.hpp"
#include <string>
#include <cstdlib>

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

class	PhoneBook{
private:
	Contact		_users[8];
	static int	_maxUser;
public:
	int	cmdAdd(int i);
	int	cmdSearch(void);
};

void	print(char *str, bool endl);

#endif