#include "BitcoinExchange.hpp"

std::string						Bitcoin::_input = "";
std::string						Bitcoin::_data = "test_data.csv";
std::string						Bitcoin::_dataFormat = ".csv";
std::string						Bitcoin::_delimiterPosData = ",";
std::string						Bitcoin::_delimiterPosInput = "|";
std::map<std::string, double>	Bitcoin::_arr;

int			Bitcoin::checkFile( std::string file ){
	std::ifstream	read;

	read.open(file.c_str());
	if (!read.is_open())
	{
		std::cout << RED "###	Error: " << file << " file doesn't not exist	###" END << std::endl;
		read.close();
		return (0);
	}
	read.close();
	std::cout << GREEN "###	" << file << " file exists	###" END << std::endl;
	return (1);
}

void		Bitcoin::setInputName( std::string input ) { _input = input; }
std::string	Bitcoin::getInputName( void ) { return (_input); }
std::string	Bitcoin::getDataName( void ) {

	if (_data.substr(_data.size() - _dataFormat.size()).compare(_dataFormat) == 0) // data dosyasının formatı karşılaştırılıyor.
		return (_data);
	return ("");
}
std::string Bitcoin::getDelimiterPosData( void ) { return (_delimiterPosData); }
std::string	Bitcoin::getDelimiterPosInput( void ) { return (_delimiterPosInput); }

void		Bitcoin::setContainer( void ){
	std::ifstream	file(Bitcoin::getDataName().c_str());
	std::string		line;

	getline(file, line);
	size_t	delimiterPos = line.find(Bitcoin::getDelimiterPosData());
	if (line.substr(0, delimiterPos).compare("date") != 0 || line.substr(delimiterPos + 1).compare("exchange_rate") != 0) // data.csv dosyasının ilk satırında 'date,exchange_rate' ifadesi bulunmalıdır.
		std::cout << RED "###	Error: The first line of the data file should contain 'data,exchange rate'	###" END << std::endl;
	else
	{
	while (getline(file, line))
	{
		std::string	date;
		double		value;

		delimiterPos = line.find(Bitcoin::getDelimiterPosData()); // hangi harf/kelime grubundan itibaren ayıracak belirliyoruz.
		if (delimiterPos != std::string::npos)
		{
				date = line.substr(0, delimiterPos);
				date.erase(std::remove(date.begin(), date.end(), ' '), date.end());
				std::istringstream iss(line.substr(delimiterPos + 1)); // double yerine string bir girdi varsa atlamak için kullanıyorum.
				if (date.empty() || line[0] == '#') // date'in boş olmasını istemdiğim için ekledim.
					continue;
				if (iss >> value)
				{
					_arr[date] = value; // red tree yapısına göre atandığı için date değerinin karşılığını vermem yeterli, kendi içinde sıralıyor.
				}
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

void		Bitcoin::printInputExchange( void ){
	std::ifstream	file(Bitcoin::getInputName().c_str());
	std::string		line;

	getline(file, line);
	size_t	delimiterPos = line.find(Bitcoin::getDelimiterPosInput());
	if (line.substr(0, delimiterPos).compare("date ") != 0 || line.substr(delimiterPos + 1).compare(" value") != 0) // input.txt dosyasının ilk satırında 'date | value' ifadesi bulunmalıdır.
		std::cout << RED "###	Error: The first line of the input file should contain 'date | value'	###" END << std::endl;
	else
	{
		while (getline(file, line))
		{
			std::string	date;
			double		value;

			delimiterPos = line.find(Bitcoin::getDelimiterPosInput());
			date = line.substr(0, delimiterPos);
			if (date.empty() || line[0] == '#')
				continue;

			int year, month, day;
			char dash1, dash2;

			std::istringstream issTime(date);

			issTime >> year >> dash1 >> month >> dash2 >> day;

			if (issTime.fail() || dash1 != '-' || dash2 != '-' || (month < 1 || month > 12) || (day < 1 || day > 30))
				std::cout << RED "Error: bad input => " END << date << std::endl;
			else if (delimiterPos != std::string::npos)
			{
				date = line.substr(0, delimiterPos);
				date.erase(std::remove(date.begin(), date.end(), ' '), date.end());
				std::istringstream iss(line.substr(delimiterPos + 1));
				if (iss >> value)
				{
					if (value < 0)
						std::cout << RED "Error: not a positive number." END << std::endl;
					else if (value > 1000)//INT_MAX)
						std::cout << RED "Error: too large a number." END << std::endl;
					else
					{
						typename std::map<std::string, double>::iterator upperBoundIter = Bitcoin::_arr.upper_bound(date);
						if (upperBoundIter != Bitcoin::_arr.end())
						{
							--upperBoundIter;
							std::cout << date << " => " << value << " = " << value*(upperBoundIter->second) << std::endl;
						}

						// if (Bitcoin::_arr.find(date) != Bitcoin::_arr.end())
					}
				}
			}
		}
	}
	file.close();
}
