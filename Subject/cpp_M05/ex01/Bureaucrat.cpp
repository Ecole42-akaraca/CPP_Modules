#include "Bureaucrat.hpp"
#include "Form.hpp"

Bureaucrat::Bureaucrat( void ):_name("Default"), _grade(150){
	std::cout << GREEN "Bureaucrat Default Constructor Called" END << std::endl;
}

Bureaucrat::Bureaucrat( const std::string &name, int grade):_name(name){
	std::cout << GREEN "Bureaucrat Constructor Called" END << std::endl;

	this->_grade = grade;
	if (this->_grade < 1)
		throw( Bureaucrat::GradeTooHighException() );
	else if (this->_grade > 150)
		throw( Bureaucrat::GradeTooLowException() );
}

Bureaucrat::Bureaucrat( const Bureaucrat &ref ):_name(ref._name), _grade(ref._grade){
	std::cout << GREEN "Bureaucrat Copy Constructor Called" END << std::endl;
}

Bureaucrat::~Bureaucrat( void ){
	std::cout << GREEN "Bureaucrat Destructor Called" END << std::endl;
}

Bureaucrat &Bureaucrat::operator=( const Bureaucrat &ref ){
	std::cout << GREEN "Bureaucrat Copy Assignment Operator Called" END << std::endl;

	if (this != &ref)
		this->_grade = ref.getGrade();
	return (*this);
}

std::string Bureaucrat::getName( void ) const{
	return (this->_name);
}

int Bureaucrat::getGrade( void ) const{
	return (this->_grade);
}

void	Bureaucrat::upGrade( void ){
	if (this->_grade - 1 < 1)
		throw( Bureaucrat::GradeTooHighException() );
	this->_grade--;
}

void	Bureaucrat::downGrade( void ){
	if (this->_grade + 1 > 150)
			throw( Bureaucrat::GradeTooLowException() );
		this->_grade++;
}

/*
	Bürokratın, formu imzalarken yetki seviyesinin try-cath ile kontrol edilmesi gerekir.
	Duruma göre istisna döndürülecektir.
	Burada forma ait olan istisnalar döndürülecektir(sadece forma ait istisna döndürmeler bulunduğu için).

	Burada try-catch kullanılmasaydı main'deki try-catch devam etmeyecekti ve program tamamen duracaktı.
*/
void	Bureaucrat::signForm( Form &ref ){
	try
	{
		ref.beSigned( *this );
		std::cout << BLUE << this->getName() << " signed "\
		<< ref.getName() << END << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << PURPLE << this->getName() << " couldn't sign "\
		<< ref.getName() << " because " << e.what() << '\n' << END;
	}
	
}

const char *Bureaucrat::GradeTooHighException::what() const throw(){
	return ( RED "Bureaucrat: Grade too HIGH" END );
}

const char *Bureaucrat::GradeTooLowException::what() const throw(){
	return ( RED "Bureaucrat: Grade too LOW" END );
}

std::ostream &operator<<( std::ostream &os, const Bureaucrat &obj ){
	os << "Bureaucrat Name: " << obj.getName() << " - Grade: " << obj.getGrade();
	return (os);
}
