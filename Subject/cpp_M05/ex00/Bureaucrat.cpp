#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat( void ):_name("Default"), _grade(150){
	std::cout << "Bureaucrat Default Constructor Called" << std::endl;
}

/*
	Sadece bu methodta olmasının nedeni, kullanıcı tarafından oluşturulduğundan dolayıdır.
*/
Bureaucrat::Bureaucrat( const std::string &name, int grade):_name(name){
	std::cout << "Bureaucrat Constructor Called" << std::endl;

	this->_grade = grade;
	if (this->_grade < 1)
		throw( Bureaucrat::GradeTooHighException() );
	else if (this->_grade > 150)
		throw( Bureaucrat::GradeTooLowException() );
}

/*
	Burasıda kullanıcı tarafından oluşturulur lakin,
		daha önce oluşturulan nesne, istenilen yapıya mecburi olarak sahip olmasından dolayı,
		burada kontrol etmeye gerek duyulmaz.

	*this = ref; Burada kullanmıyorum,
		çünkü değerler "inizialize-list(başlatma listesi)" - "Colon Members Initialization" ile belirtilmiştir..
*/
Bureaucrat::Bureaucrat( const Bureaucrat &ref ):_name(ref._name), _grade(ref._grade){
	std::cout << "Bureaucrat Copy Constructor Called" << std::endl;
}

Bureaucrat::~Bureaucrat( void ){
	std::cout << "Bureaucrat Destructor Called" << std::endl;
}

/*
	this->_name; const tipinde olduğundan dolayı eşitlenemez.
*/
Bureaucrat &Bureaucrat::operator=( const Bureaucrat &ref ){
	std::cout << "Bureaucrat Copy Assignment Operator Called" << std::endl;

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

/*
	Kullanıcı tarafından etkileşim halinde olduğundan dolayı kontrol edilmesi gerekmektedir.
*/
void	Bureaucrat::upGrade( void ){
	if (this->_grade - 1 < 1)
		throw( Bureaucrat::GradeTooHighException() );
	this->_grade--;
}

/*
	Kullanıcı tarafından etkileşim halinde olduğundan dolayı kontrol edilmesi gerekmektedir.
*/
void	Bureaucrat::downGrade( void ){
	if (this->_grade + 1 > 150)
			throw( Bureaucrat::GradeTooLowException() );
		this->_grade++;
}

const char *Bureaucrat::GradeTooHighException::what() const throw(){
	return ( "Bureaucrat: Grade too HIGH" );
}

const char *Bureaucrat::GradeTooLowException::what() const throw(){
	return ( "Bureaucrat: Grade too LOW" );
}

std::ostream &operator<<( std::ostream &os, const Bureaucrat &obj ){
	os << "Bureaucrat Name: " << obj.getName() << " - Grade: " << obj.getGrade();
	return (os);
}
