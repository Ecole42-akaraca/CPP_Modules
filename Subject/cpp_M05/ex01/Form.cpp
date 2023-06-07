#include "Form.hpp"

Form::Form( void ): _name("Default"), _signed(false), _signGrade(150), _executeGrade(150){
	std::cout << GREEN "Form Default Constructor Called" END << std::endl;
}

Form::Form( const std::string &name, int signGrade, int executeGrade): _name(name), _signGrade(signGrade), _executeGrade(executeGrade){
	std::cout << GREEN "Form Constructor Called" END << std::endl;
	this->_signed = false;
	if (this->_signGrade < 1 || this->_executeGrade < 1)
		throw( Form::GradeTooHighException() );
	else if (this->_signGrade > 150 || this->_executeGrade > 150)
		throw( Form::GradeTooLowException() );
}

Form::Form( const Form &ref ): _name(ref._name), _signed(ref._signed), _signGrade(ref._signGrade), _executeGrade(ref._executeGrade){
	std::cout << GREEN "Form Copy Constrcutor Called" END << std::endl;
}

Form::~Form( void ){
	std::cout << GREEN "Form Destructor Called" END << std::endl;
}

Form &Form::operator=( const Form &ref ){
	std::cout << GREEN "Form Copy Assignment Operator Called" END << std::endl;
	if (this != &ref)
	{
		this->_signed = ref.getSign();
	}
	return (*this);
}

std::string Form::getName( void ) const{
	return (this->_name);
}

bool	Form::getSign( void ) const{
	return (this->_signed);
}

int	Form::getSignGrade( void ) const{
	return (this->_signGrade);
}

int	Form::getExecuteGrade( void ) const{
	return (this->_executeGrade);
}

/*
	Bürokratın yetki seviyesine/formun durumuna göre istisna döndürülür/döndürülmez.
*/
void	Form::beSigned( const Bureaucrat &ref ){
	if (ref.getGrade() > this->getSignGrade())
		throw ( Form::GradeTooLowException() );
	if (this->_signed == true)
		throw ( Form::FormAlreadySigned() );
	this->_signed = true;
}

const char *Form::GradeTooHighException::what() const throw(){
	return ( RED "Form: Grade too HIGH!" END );
}

const char *Form::GradeTooLowException::what() const throw(){
	return ( RED "Form: Grade too LOW!" END );
}

const char *Form::FormAlreadySigned::what() const throw(){
	return ( RED "Form Already Signed!" END );
}

std::ostream &operator<<( std::ostream &os, const Form &obj ){
	os << "Form Name: " << obj.getName() << " - SignGrade: " \
	<< obj.getSignGrade() << " - ExecuteGrade: " \
	<< obj.getExecuteGrade() << " - Sign: " \
	<< obj.getSign();
	return (os);
}
