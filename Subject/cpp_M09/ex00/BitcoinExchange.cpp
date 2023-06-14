#include "BitcoinExchange.hpp"

int								Bitcoin::_line = 0;
std::string						Bitcoin::_file = "";
std::string						Bitcoin::_data = "test_data.csv";
std::string						Bitcoin::_delimiterPos = ",";
std::map<std::string, double>	Bitcoin::_arr;

int			Bitcoin::checkFile( std::string file ){
	std::ifstream	read;

	read.open(file);
	if (!read.is_open())
	{
		std::cout << RED << file << " file doesn't not exist" END << std::endl;
		read.close();
		return (0);
	}
	if (!read)
		std::cout << "Empty" << std::endl;
	read.close();
	std::cout << GREEN << file << " file exists" END << std::endl;
	return (1);
}

void		Bitcoin::setFileName( std::string file ) { _file = file; }
std::string	Bitcoin::getFileName( void ) { return (_file); }
std::string	Bitcoin::getDataName( void ) { return (_data); }

void		Bitcoin::setContainer( void ){
	std::ifstream	file(_data);
	
	std::string		line;
	while (getline(file, line))
	{
		std::string	date;
		double		value;

		size_t	delimiterPos = line.find(_delimiterPos); // hangi harf/kelime grubundan itibaren ayıracak belirliyoruz.
		if (delimiterPos != std::string::npos)
		{
			date = line.substr(0, delimiterPos);
			std::istringstream iss(line.substr(delimiterPos + 1)); // double yerine string bir girdi varsa atlamak için kullanıyorum.
			if (date.empty() || line[0] == '#') // date'in boş olmasını istemdiğim için ekledim.
			 	continue;
			if (iss >> value)
			{
				value = std::stod(line.substr(delimiterPos + 1));
				_arr[date] = value; // red tree yapısına göre atandığı için date değerinin karşılığını vermem yeterli, kendi içinde sıralıyor.
			}
		}
	}

	file.close();
}

void		Bitcoin::printContainer( void ){

	std::map<std::string, double>::const_iterator it;
	for (it = Bitcoin::_arr.begin(); it != Bitcoin::_arr.end(); ++it)
		std::cout << "1:	" << it->first << "	2:	" << it->second << std::endl;
}
