#ifndef BITCOINEXCHANGE_HPP
 #define BITCOINEXCHANGE_HPP

# include <iostream>
# include <algorithm>
# include <map>
# include <fstream>
# include <sstream>
# include "Color.hpp"

class Bitcoin{

private:
	static int								_line;
	static std::string						_file;
	static std::string						_data;
	static std::string						_delimiterPos;
	static std::map<std::string, double>	_arr;

public:
	static int			checkFile( std::string );
	
	static void			setFileName( std::string );
	static std::string	getFileName( void );
	static std::string	getDataName( void );

	static void			setContainer( void );
	static void			printContainer( void );
};


#endif
