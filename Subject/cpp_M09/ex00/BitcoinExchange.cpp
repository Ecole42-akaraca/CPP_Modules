#include "BitcoinExchange.hpp"

std::string						Bitcoin::_input = "";
std::string						Bitcoin::_inputFirstLine = "date | value";
std::string						Bitcoin::_data = "data.csv";
std::string						Bitcoin::_dataFormat = ".csv";
std::string						Bitcoin::_dataFirstLine = "date,exchange_rate";
std::string						Bitcoin::_delimiterPosData = ",";
std::string						Bitcoin::_delimiterPosInput = "|";
std::map<std::string, double>	Bitcoin::_arr;

void		Bitcoin::checkArg( int argc, char **argv ){

	if (argc < 2)
		throw ( NotEnoughtInputs() );
	if (argc > 2)
		throw ( TooManyInputs() );
	Bitcoin::checkFile(argv[1]);
	Bitcoin::checkFile(Bitcoin::getDataName());
}

void		Bitcoin::checkFile( std::string file ){
	std::ifstream	read;

	read.open(file.c_str());
	if (!read.is_open())
	{
		read.close();
		throw ( FileDoesNotExist() );
	}
	read.close();
	std::cout << GREEN "###	" << file << "	file exists	###" END << std::endl;
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
	std::ifstream		file(Bitcoin::getDataName().c_str());
	std::string			line;
	std::string			date;
	double				value;
	size_t				delimiterPos; // bu değerlerin her defasında sıfırlanması gerekiyor.
	std::istringstream	iss;

	getline(file, line);
	if (line.compare(_dataFirstLine) != 0) // data.csv dosyasının ilk satırında 'date,exchange_rate' ifadesi bulunmalıdır.
		throw ( DataFileFirstLineWrong() );
	while (getline(file, line))
	{
		value = 0;
		delimiterPos = 0;
		date.clear();
		iss.clear();

		delimiterPos = line.find(Bitcoin::getDelimiterPosData()); // hangi harf/kelime grubundan itibaren ayıracak belirliyoruz.
		if (delimiterPos != std::string::npos)
		{
			date = line.substr(0, delimiterPos);
			date.erase(std::remove(date.begin(), date.end(), ' '), date.end()); // space karakterini temizlemek için kullanıyorum. // remove iterator döndürdüğünden dolayı iterator alan erase kullanıyorum.
			iss.str(line.substr(delimiterPos + 1)); // double yerine string bir girdi varsa atlamak için kullanıyorum.
			if (date.empty() || line[0] == '#') // date'in boş olmasını istemdiğim için ekledim.
				continue;
			if (iss >> value)
			{
				_arr[date] = value; // red tree yapısına göre atandığı için date değerinin karşılığını vermem yeterli, kendi içinde sıralıyor.
			}
		}
	}
	file.close();
}

void		Bitcoin::printContainer( void ){

	std::map<std::string, double>::const_iterator it;
	for (it = Bitcoin::_arr.begin(); it != Bitcoin::_arr.end(); ++it)
		std::cout << "1:	" << it->first << "		2:	" << it->second << std::endl;
}

void		Bitcoin::printInputExchange( void ){
	std::ifstream	file(Bitcoin::getInputName().c_str());
	std::string		line;
	std::string		date;
	double			value;
	size_t			delimiterPos;
	int				year, month, day;
	char			dash1, dash2;
	std::istringstream issTime;
	std::istringstream iss;

	getline(file, line);
	if (line.compare(_inputFirstLine) != 0) 
		throw ( InputFileFirstLineWrong() ); // input.txt dosyasının ilk satırında 'date | value' ifadesi bulunmalıdır.

	while (getline(file, line))
	{
		date.clear();
		value = 0;
		delimiterPos = 0;
		year = month = day = 0;
		dash1 = dash2 = '\0';
		issTime.clear();
		iss.clear();

		delimiterPos = line.find(Bitcoin::getDelimiterPosInput());
		date = line.substr(0, delimiterPos);
		if (date.empty() || line[0] == '#')
			continue;

		issTime.str(date);
		issTime >> year >> dash1 >> month >> dash2 >> day;
		try
		{
			if (issTime.fail() || dash1 != '-' || dash2 != '-' || (month < 1 || month > 12) || (day < 1 || day > 30))
			{
				std::cout << RED "Error: bad input => " << END << date << std::endl;
				continue;
			}
			if (delimiterPos != std::string::npos)
			{
				date = line.substr(0, delimiterPos);
				date.erase(std::remove(date.begin(), date.end(), ' '), date.end());
				iss.str(line.substr(delimiterPos + 1));
				if (iss >> value)
				{
					if (value < 0)
						throw ( NotPositiveNumber() );
					if (value > 1000)//INT_MAX)
						throw ( TooLargeNumber() );
					std::map<std::string, double>::iterator upperBoundIter = Bitcoin::_arr.upper_bound(date);
					if (upperBoundIter != Bitcoin::_arr.end())
					{
						--upperBoundIter;
						std::cout << date << " => " << value << " = " << value*(upperBoundIter->second) << std::endl;
					}
				}
			}
		}
		catch (std::exception& e)
		{
			std::cerr << e.what() << std::endl;
		}
	}
	file.close();
}
