#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm( void ): _name("Default"), _signed(false), _signGrade(150), _executeGrade(150){
	std::cout << GREEN "AForm Default Constructor Called" END << std::endl;
}

AForm::AForm( const std::string &name, int signGrade, int executeGrade): _name(name), _signGrade(signGrade), _executeGrade(executeGrade){
	std::cout << GREEN "AForm Constructor Called" END << std::endl;
	this->_signed = false;
	if (this->_signGrade < 1 || this->_executeGrade < 1)
		throw( AForm::GradeTooHighException() );
	else if (this->_signGrade > 150 || this->_executeGrade > 150)
		throw( AForm::GradeTooLowException() );
}

AForm::AForm( const AForm &ref ): _name(ref._name), _signed(ref._signed), _signGrade(ref._signGrade), _executeGrade(ref._executeGrade){
	std::cout << GREEN "AForm Copy Constructor Called" END << std::endl;
}

AForm &AForm::operator=( const AForm &ref ){
	std::cout << GREEN "AForm Copy Assignment Operator Called" END << std::endl;
	if (this != &ref)
	{
		this->_signed = ref.getSign();
	}
	return (*this);
}

AForm::~AForm( void ){
	std::cout << GREEN "AForm Destructor Called" END << std::endl;
}

std::string AForm::getName( void ) const{
	return (this->_name);
}

bool AForm::getSign( void ) const{
	return (this->_signed);
}

int	AForm::getSignGrade( void ) const{
	return (this->_signGrade);
}

int AForm::getExecuteGrade( void ) const{
	return (this->_executeGrade);
}

void	AForm::beSigned( const Bureaucrat &ref ){
	if (ref.getGrade() > this->getSignGrade() )
		throw ( AForm::GradeTooLowException() );
	if (this->_signed == true)
		throw ( AForm::AFormAlreadySigned() );
	this->_signed = true;
}

const char *AForm::GradeTooHighException::what() const throw(){
	return ( RED "AForm: Grade too HIGH!" END );
}

const char *AForm::GradeTooLowException::what() const throw(){
	return ( RED "AForm: Grade too LOW!" END );
}

const char *AForm::AFormAlreadySigned::what() const throw(){
	return ( RED "AForm Already Signed!" END );
}

const char *AForm::AFormNotSigned::what() const throw(){
	return ( RED "AForm Not Signed!" END );
}

std::ostream &operator<<( std::ostream &os, const AForm &obj ){
	os << "AForm Name: " << obj.getName() << " - SignGrade: " \
	<< obj.getSignGrade() << " - ExecuteGrade: " \
	<< obj.getExecuteGrade() << " - Sign: " \
	<< obj.getSign();
	return (os);
}
