#ifndef BITCOINEXCHANGE_HPP
 #define BITCOINEXCHANGE_HPP

# include <iostream>
# include <algorithm>
# include <map>
# include <fstream>
# include <sstream>
# include <sys/stat.h>
# include "Color.hpp"

class Bitcoin{

private:
	static std::string						_input;
	static std::string						_data;
	static std::string						_delimiterPosData;
	static std::string						_delimiterPosInput;
	static std::map<std::string, double>	_arr;

public:
	static int			checkFile( std::string );
	
	static void			setInputName( std::string );
	static std::string	getInputName( void );
	static std::string	getDataName( void );
	static std::string	getDelimiterPosData( void );
	static std::string	getDelimiterPosInput( void );

	static void			setContainer( void );
	static void			printContainer( void );

	static void			printInputExchange( void );
};


#endif
