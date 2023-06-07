#include "Intern.hpp"

Intern::Intern( void ){
	std::cout << GREEN "Intern Default Constructor Called" END << std::endl;
}

Intern::Intern( const Intern &ref ){
	std::cout << GREEN "Intern Copy Constructor Called" END << std::endl;
	*this = ref;
}

Intern::~Intern(void){
	std::cout << GREEN "Intern Destructor Called" END << std::endl;
}

Intern &Intern::operator=( const Intern &ref ){
	std::cout << GREEN "Intern Assignment Operator Called" END << std::endl;
	if (this != &ref)
	{
		*this = ref;
	}
	return (*this);
}

/* AForm bir abstract class olduğundan dolayı AForm tipinde döndüremeyiz.
	Yani döndürülen şey, AForm'un alt sınıfları oluyor.
	AForm Abstract class olmasa dahi işaretçisini döndürmek zorundayız çünkü bu fonk. döndürüldüğü yerde form nesnesinden bir adet vardır,
		yani birden fazla forma ihtiyacımız  yoktur.
	Subject'de işaretçi olarak döndüreceğinden bahsedilmektedir.

	if/else kullanımı yasak olduğundan dolayı switch-case yapısını kullanacağım.

	Burada try-catch kullanırsam, hata durumunda istisna buradan dönecek ve değer NULL olarak döndürülecek.
	Bu durumda döndürülen fonksiyonda bu veriye erişilmeye çalışıldığında Seg.fault verecek, bundan dolayı
		try-catch'i burada kullanmadım, döndürdüğü fonksiyonda kullandım.
	*/
AForm *Intern::makeForm( std::string formName, std::string targetName ){

	std::string form_name_list[] = {"robotomy request", "presidential pardon", "shrubbery creation"};
	int index = 0;
	int lenght = form_name_list->length() - 1;
	while (index < lenght && (form_name_list[index].empty() == false) && (form_name_list[index]).compare(formName))
		index++;
	AForm *ret;
	switch (index)
	{
		case 0:
			ret = new RobotomyRequestForm(targetName);
			break;
		case 1:
			ret = new PresidentialPardonForm(targetName);
			break;
		case 2:
			ret = new ShrubberyCreationForm(targetName);
			break;
		default:
			throw ( Intern::InternCantCreatedForm() );
	}
	std::cout << YELLOW "Intern creates " << ret->getName() << END << std::endl;
	return (ret);
}

const char *Intern::InternCantCreatedForm::what() const throw(){
	return ( RED "Intern can't created form because there is no form this type!" END );
}
