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
	static std::string						_data;
	static std::string						_dataFormat;
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
