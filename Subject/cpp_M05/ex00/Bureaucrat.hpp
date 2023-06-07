#ifndef BUREAUCRAT_HPP
 #define BUREAUCRAT_HPP

#include <iostream>

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

class Bureaucrat{

private:
	std::string const	_name;
	int					_grade;

public:
	/* Constructors & Destructors */
	Bureaucrat();
	Bureaucrat( const std::string &name, int grade );
	Bureaucrat( const Bureaucrat &ref );
	~Bureaucrat();

	/* Basic Operators */
	Bureaucrat &operator=( const Bureaucrat &ref );

	/* Getters & Setters */
	std::string getName() const;
	int getGrade() const;

	/* Main Member Functions */
	void		upGrade( void );
	void		downGrade( void );

	/* Exceptions */
	class GradeTooHighException : public std::exception{
		public:
			virtual const char *what(void) const throw(); // throw() meaning; not throwing any exceptions.
	};

/*
	GradeTooLowException sınıfı, exception sınıfından türetilmiştir.
	Türetilmiş sınıfın, base sınıfının tüm özelliklerini miras aldığı anlamına gelir.

	"virtual" anahtar kelimesi polimorfik bir yapı oluşturmak için kullanılan bir özelliktir.
	Bu, bir işlevin türetilen sınıflar tarafından yeniden tanımlanabilmesine izin verir.
	Türetilmiş sınıfın özel durum açıklamasını kendi amaçlarına uygun şekilde yeniden tanımlayabilececeği anlamına gelir.
	Böylece, üst sınfın "what()" işlevini alt sınıflar tarafından yeniden tanımlandığında, alt sınıfın "what()" işlevi çağrılır.

	Bu sınıfın "what()" işlevi, exception sınıfında "throw()" özellikleri ile tanımlanmıştır.
	Bu işlevin hiçbir istisna fırlatmayacağını garanti eder. Yani, bu işlevin çağrılması,
		bir hata durumu oluştuğunda programın beklenmedik şekilde çökmesini önleyecektir.

	- virtual: Bu yapı şuanki class için hiçbir şeyi etkilememektedir.

	- const char *what(): Hiçbir bağımsız değişken almayan ve const char'a bir işaretci döndüren what() adlı bir üye işlevdir.

	- const: İkinci const, what() fonksiyonunun const niteliği taşıdığını belirtir.
		Bu, what() fonk.'nun, sınıf nesnesinin durumunu değiştirmemesi gerektiği anlamına gelir.

	- throw(): what() fonk.'nun hiçbir istisna fırlatmayacağını belirtir.
		Bu kelime C++ dilinde "exception specification" olarak bilinir.
		Modern C++ sürümlerinde istisna belirtimi yerine "noexcept" kelimesi kullanılması önerilir.
		virtual const char *what(void) const noexcept;
			noexcept:
				C++11 sürümünden itibaren kullanıma sürülmüştür.
				C++11 veya daha yeni sürümlerde bu öneriliyor.
		virtual const char *what(void) const _NOEXCEPT;
			_NOEXCEPT:
				Bu yapı, C++11'den önceki sürümlerinde "noexcept" yerine kullanılan bir makro isimdir.
				_NOEXCEPT ve noexcept aynı şeyi ifade eder, yalnızca kullanıldıkları sürümler farklıdır.
*/
	class GradeTooLowException : public std::exception{
		public:
			virtual const char *what(void) const throw();
	};
};

std::ostream &operator<<( std::ostream &os, const Bureaucrat &obj );

#endif
