#ifndef RPN_HPP
 #define RPN_HPP

# include <iostream>
# include <stack>
# include <sstream>
# include <string.h>
# include "Color.hpp"

class RPN{

private:
	static std::string				_input;
	static std::string				_allowedChars;
	static std::stack<std::string>	_arr;

public:
	static void						setInput( std::string );
	static void						setContainer( void );
	static std::string				getInput( void );
	static std::stack<std::string>	&getContainer( void );
	static void						unwantedChars( void );
	static void						checkArg( int, char ** );
	static int						stringToInt( std::string );
	static void						printRPN( void );

	class NotEnoughtInputs : public std::exception{
		public:
			virtual const char *what(void) const throw(){
				return ( RED "###	Error: not enought inputs!	###" END );
			}
	};

	class TooManyInputs : public std::exception{
		public:
			virtual const char *what(void) const throw(){
				return ( RED "###	Error: too many inputs!		###" END );
			}
	};

	class ContainsUnwantedChars : public std::exception{
		public:
			virtual const char *what(void) const throw(){
				return ( RED "###	Error: input contains disallowed characters!	###" END );
			}
	};

	class WrongInputs : public std::exception{
		public:
			virtual const char *what(void) const throw(){
				return ( RED "###	Error: wrong inputs!	###" END );
			}
	};
};

#endif
