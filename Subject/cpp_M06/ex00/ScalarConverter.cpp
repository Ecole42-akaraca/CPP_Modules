#include "ScalarConverter.hpp"

std::string	ScalarConverter::_string = "";
e_type		ScalarConverter::_type = NONE;
int			ScalarConverter::_index = 0;
int			ScalarConverter::_sign = 1;
char		ScalarConverter::_char = '\0';
int			ScalarConverter::_int = 0;
float		ScalarConverter::_float = 0.0f;
double		ScalarConverter::_double = 0.0;

std::string	ScalarConverter::getString( void ) { return (_string); }
char		ScalarConverter::getChar( void ) { return (_char); }
int			ScalarConverter::getInt( void ) { return (_int); }
float		ScalarConverter::getFloat( void ) { return (_float); }
double		ScalarConverter::getDouble( void ) { return (_double); }
int			ScalarConverter::getType( void ) { return (_type); }

void		ScalarConverter::setString( std::string string ) { _string = string; }

void		ScalarConverter::setType( void ){
	if (isChar())
		_type = CHAR;
	else if (isInt())
		_type = INT;
	else if (isFloat())
		_type = FLOAT;
	else if (isDouble())
		_type = DOBULE;
	else if (isLiterals())
		_type = LITERALS;
	std::string type_name_list[] = {"NONE", "CHAR", "INT", "FLOAT", "DOUBLE", "LITERALS"};
	std::cout << BLUE "The input type is: " << type_name_list[_type] << END << std::endl;
}

bool		ScalarConverter::isChar( void ){
	return ( _string.length() == 1 && std::isprint(_string[0]) );
}

/*
	int -> (1), (-1), (+1), (--1), (++1) ...
*/
bool		ScalarConverter::isInt( void ){
	int	i;
	_sign = 1;

	i = 0;
	while (_string[i] == '-' || _string[i] == '+')
	{
		if (_string[i] == '-')
			_sign *= -1;
		i++;
	}
	_index = i;
	while (i < (int)_string.length())
	{
		if (!std::isdigit(_string[i]))
			return (false);
		i++;
	}
	return (true);
}

/*
	Float tipi bir değişkende en az bir nokta ve float olduğunu belli eden 'f' bulunmalıdır.
	float -> (3.1f), (.4f), (2.f), (-1.1f), (--1.2f), (-+4.f), (-+-.1f)
	Wrong use -> (2..), (3.1.), (1.1ff), (.1ff), (-1.+3f), (2.f+), (f.1), (1f), (1.4), (.2), (1.), (.f)

	tmp.back() -> string'in son elamanını döndürür. (_string[_string.length() - 1])
	tmp.find('x') -> string'in içinde x karakterini arar ve indexini döndürür. Eğer bulamaz ise -1 döndürür.

	1.for döngüsü, string içindeki 'f' ve '.' sayısını bulurken istenilmeyen karakter girdisi varsa false döndürür.
	if, stringin içerisinde 1 adet 'f' ve '.' kontrolünü yapar ve '.f' biçiminden daha fazla girdi varmı kontrol eder, girdinin sonu 'f' ile bitiyor mu kontrol eder.
	2.for döngüsü, stringin başında işaret değerlerini atlar ve '-' durumu için 'sign' değerini tutar.
		İşaretçilerden sonra farklı bir karakter var ise o kısımdan itibaren başka bir string üzerinden kontrole devam eder.
		Bu yeni string içinde işaretçi karakterler var mı kontrol eder ve '.f' biçimden uzunmu kontrolü yapılır.
*/
bool		ScalarConverter::isFloat( void ){
	int countF = 0;
	int	countDot = 0;
	std::string tmp;
	_sign = 1;

	for (int i = 0; _string[i] != '\0'; i++)
	{
		if (_string[i] == 'f')
			countF++;
		if (_string[i] == '.')
			countDot++;
		if (_string[i] != 'f' && _string[i] != '.' && _string[i] != '-' && _string[i] != '+' && !(_string[i] >= 48 && _string[i] <= 57))
			return (false);
	}
	if (countF != 1 || countDot != 1 || _string.length() < 3 || (_string[_string.length() - 1] != 'f' && countF == 1))
		return (false);
	for (int i = 0; _string[i] == '-' || _string[i] == '+'; i++)
	{
		if (_string[i] == '-')
			_sign *= -1;
		if (_string[i + 1] != '\0' && (_string[i + 1] != '-' || _string[i + 1] != '+'))
		{
			tmp = &_string[i + 1];
			_index = i + 1;
			if ((int)tmp.find('-') != -1 || (int)tmp.find('+') != -1 || tmp.length() < 3)
				return (false);
		}
	}
	return (true);
}

/*
	Double tipi bir değişkende en az bir nokta bulunmalıdır.
	double -> (1.4), (1.), (.3)
	Wrong use -> (1.4f), (1.f), (.3f), (2..), (3.1.), (1.1ff), (.1ff), (-1.+3f), (2.f+), (f.1), (1f)
*/
bool		ScalarConverter::isDouble( void ){
	int countDot = 0;
	std::string tmp;
	_sign = 1;

	for (int i = 0; _string[i] != '\0'; i++)
	{
		if (_string[i] == '.')
			countDot++;
		if (_string[i] != '.' && _string[i] != '-' && _string[i] != '+' && !(_string[i] >= 48 && _string[i] <= 57))
			return (false);
	}
	if (countDot != 1)
		return (false);
	for (int i = 0; _string[i] == '-' || _string[i] == '+'; i++)
	{
		if (_string[i] == '-')
			_sign *= -1;
		if (!_string[i + 1] && (_string[i + 1] != '-' || _string[i + 1] != '+'))
		{
			tmp = &_string[i + 1];
			_index = i + 1;
			if ((int)tmp.find('-') != -1 || (int)tmp.find('+') != -1)
				return (false);
		}
	}
	return (true);
}

bool		ScalarConverter::isLiterals( void ){
	if ( (_string.compare("nan") == 0)
		|| (_string.compare("nanf") == 0)
		|| (_string.compare("+inff") == 0) // Float
		|| (_string.compare("inff") == 0) // Float
		|| (_string.compare("-inff") == 0) // Float
		|| (_string.compare("+inf") == 0) // Double
		|| (_string.compare("inf") == 0) // Double
		|| (_string.compare("-inf") == 0)) // Double
		return (true);
	return (false);
}

void		ScalarConverter::printChar( void ){
	if (isLiterals() || !(_int >= 0 && _int < 127))
		std::cout << "impossible" << std::endl;
	else if (!std::isprint(_int))
		std::cout << "Non displayable" << std::endl;
	else
		std::cout << "'" << getChar() << "'" << std::endl;
}

void		ScalarConverter::printInt( void ){
	if (isLiterals())
		std::cout << "impossible" << std::endl;
	else
		std::cout << getInt() << std::endl;
}

void		ScalarConverter::printFloat( void ){
	if (_string.compare("nan") == 0 || _string.compare("nanf") == 0)
		std::cout << "nanf" << std::endl;
	else if (_string.compare("+inf") == 0 || _string.compare("+inff") == 0)
		std::cout << "+inff" << std::endl;
	else if (_string.compare("-inf") == 0 || _string.compare("-inff") == 0)
		std::cout << "-inff" << std::endl;
	else
	{
		if (_float - static_cast<int>(_float) == 0)
			std::cout << _float << ".0f" << std::endl;
		else
			std::cout << getFloat() << "f" << std::endl;
	}
}

void		ScalarConverter::printDouble( void ){
	if (_string.compare("nan") == 0 || _string.compare("nanf") == 0)
		std::cout << "nan" << std::endl;
	else if (_string.compare("+inf") == 0 || _string.compare("+inff") == 0)
		std::cout << "+inf" << std::endl;
	else if (_string.compare("-inf") == 0 || _string.compare("-inff") == 0)
		std::cout << "-inf" << std::endl;
	else
	{
		if (_double - static_cast<int>(_double) == 0)
			std::cout << _double << ".0" << std::endl;
		else
			std::cout << getDouble() << std::endl;
	}
}


/*
	-> staic_cast<...> nedir ne işe yarar?
		static_cast <veri-türü> (ifade) şeklinde gösterilir.
			veri-türü: İfade ile elde edilecek olan verinin çevrileceği veri türüdür.
			ifade: Değişken, sabit ve işlemcilerden oluşan değerlerdir. Çevrilecek olan veri türünü gösterir.

	örn:
		double dd1 = 7.21;
  		double dd2 = 15.12;
  		double dd3;

		sayı değerlerimiz olsun;
			Tip dönüşüm örnekleri:	dd3 = (int) dd1 + dd2;
									dd3 = static_cast<int>(dd1) + dd2;
			Bu örneklerin sonuçları aynı olacaktır sadece kullanım tarzları/syntaxları farklıdır.

	Bu iki tip dönüşüm arasındaki fark, kullanılan dönüşüm operatörleri farklı olduğu için syntax farkıdır.
	
	Birincisi, C dilinde yaygın olarak kullanılan bir dönüşüm operatörü olan (int) kullanıyor.
	Bu, bir double değerini tamsayı tipine dönüştürür ve sonucu bir tamsayı olarak atar.
	Bu durumda, dd1 double değerini (int) ile dönüştürür ve sonucu 7 olarak atar.
	Ardından, dd2 double değeri ile 7 toplar ve sonucu 22.12 olarak dd3 değişkenine atar. Sonuçta, dd3 bir double değerdir.

	İkincisi, C++ dilinde kullanılan bir dönüşüm operatörü olan static_cast<int> kullanılıyor.
	Bu, C dilindeki (int) operatörüne benzer şekilde, double değeri tamsayı tipine dönüştürür, ancak biraz daha güvenli bir şekilde yapar.
	Bu operatör, C++ dilindeki tip güvenliğini sağlamak için kullanılır.
	Bu durumda, static_cast<int>(dd1) double değerini tamsayı tipine güvenli bir şekilde dönüştürür ve sonucu 7 olarak atar.
	Ardından, dd2 double değeri ile 7 toplar ve sonucu 22 olarak dd3 değişkenine atar. Sonuçta, dd3 bir tamsayı değerdir.

	Özetle, (int) dönüşüm operatörü, C dilindeki yaygın bir dönüşüm operatörüdür, ancak C++ dilinde kullanımı önerilmemektedir.
	static_cast<int> operatörü, C++ dilinde tip güvenliği sağlamak için kullanılır ve C dilindeki (int) operatöründen daha güvenlidir.
		
*/
void		ScalarConverter::ScalarConvertingString( std::string argv ){
	setString(argv);
	setType();
	if (getType() == NONE)
		throw ( ScalarConverter::InvalidType() );
	switch (getType())
	{
		case CHAR:
			_char	= _string[0];
			_int	= static_cast<int>(_char);
			_float	= static_cast<float>(_char);
			_double	= static_cast<double>(_char);
			break;
		
		case INT:
			_int	= atoi(&_string.c_str()[_index]);
			_int	= _int * _sign;
			_char	= static_cast<char>(_int);
			_float	= static_cast<float>(_int);
			_double	= static_cast<double>(_int);
			break;

		case FLOAT:
			_float	= atof(&_string.c_str()[_index]);
			_float	= _float * _sign;
			_char	= static_cast<char>(_float);
			_int	= static_cast<int>(_float);
			_double	= static_cast<double>(_float);
			break;

		case DOBULE:
			_double = atof(&_string.c_str()[_index]);
			_double	= _double * _sign;
			_char	= static_cast<char>(_double);
			_int	= static_cast<int>(_double);
			_float	= static_cast<float>(_double);
			break;
		default:
			break;
	}
	std::cout << "char: "; ScalarConverter::printChar();
	std::cout << "int: "; ScalarConverter::printInt();
	std::cout << "float: "; ScalarConverter::printFloat();
	std::cout << "double: "; ScalarConverter::printDouble();
}
