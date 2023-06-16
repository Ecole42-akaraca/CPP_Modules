#ifndef BITCOINEXCHANGE_HPP
 #define BITCOINEXCHANGE_HPP

# include <iostream>
# include <map>			// std::map
# include <fstream>		// std::ifstream
# include <sstream>		// std::istringstream
# include <climits>		// INT_MAX
// # include <sys/stat.h>
# include <algorithm>
# include "Color.hpp"

class Bitcoin{

private:
	static std::string						_input;
	static std::string						_inputFirstLine;
	static std::string						_data;
	static std::string						_dataFormat;
	static std::string						_dataFirstLine;
	static std::string						_delimiterPosData;
	static std::string						_delimiterPosInput;
	static std::map<std::string, double>	_arr;

public:
	static void			checkArg( int argc, char **argv );
	static void			checkFile( std::string );
	
	static void			setInputName( std::string );
	static std::string	getInputName( void );
	static std::string	getDataName( void );
	static std::string	getDelimiterPosData( void );
	static std::string	getDelimiterPosInput( void );

	static void			setContainer( void );
	static void			printContainer( void );

	static void			printInputExchange( void );

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

	class FileDoesNotExist : public std::exception{
		public:
			virtual const char *what(void) const throw(){
				return ( RED "###	Error: file doesn't exist!	###" END );
			}
	};

	class DataFileFirstLineWrong : public std::exception{
		public:
			virtual const char *what(void) const throw(){
				return ( RED "###	Error: The first line of the data file should contain 'data,exchange_rate'	###" END );
			}
	};

	class InputFileFirstLineWrong : public std::exception{
		public:
			virtual const char *what(void) const throw(){
				return ( RED "###	Error: The first line of the input file should contain 'date | value'	###" END );
			}
	};

	class NotPositiveNumber : public std::exception{
		public:
			virtual const char *what(void) const throw(){
				return ( RED "Error: not a positive number." END );
			}
	};

	class TooLargeNumber : public std::exception{
		public:
			virtual const char *what(void) const throw(){
				return ( RED "Error: too large a number." END );
			}
	};

};

#endif
