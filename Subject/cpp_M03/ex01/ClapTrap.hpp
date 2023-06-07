#ifndef CLAPTRAP_HPP
 #define CLAPTRAP_HPP

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

class ClapTrap{

protected: // kalıtım ile erişilmesini istediğimiz değişkenleri protected yapısı altında sıralıyoruz.
	std::string		name;			//isim
	unsigned int	hitPoint;		//can puanı
	unsigned int	energyPoint;	//enerji puanı
	unsigned int	attackDamage;	//saldırı gücü

public:
	ClapTrap( void ); // default constructor
	ClapTrap( const ClapTrap &ref ); // copy constructor.
	ClapTrap( std::string name ); // Name, which is passed as parameter to a constructor
	ClapTrap &operator=( const ClapTrap &ref ); // copy assignment operator overload.
	~ClapTrap(); // destructor.

	void	attack( const std::string &target );

	/*
		Kalıtımı yapılan sınıftada aynı fonksiyon türü varsa ve temel sınıftaki fonksiyon kullanılmak isteniyorsa;
		temel sınıftaki fonksiyon başına virtual eklenmez. Eğerki kullanmak istemiyorsak, yani türetilen sınıftaki fonksiyon kullanılmak isteniyorsa;
		temel sınıftaki fonksiyon başına virtual eklenir.

		Bu işlem ancak temel ve türetilmiş sınıfların oluşturulup, türetilmiş sınıfların temel sınıflara &ref olarak atanması ile çalışmaktadır.
	*/
	// virtual void	takeDamage( unsigned int amount );
	void	takeDamage( unsigned int amount );
	void	beRepaired( unsigned int amount );

	int	getDamage();
};

#endif
