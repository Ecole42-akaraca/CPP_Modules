#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm( void ): AForm("PresidentialPardonForm", 25, 5), _target("Default"){
	std::cout << GREEN "PresidentialPardonForm Default Constructor Called" END << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm( const std::string &target ): AForm("PresidentialPardonForm", 25, 5), _target(target){
	std::cout << GREEN "PresidentialPardonForm Constructor Called" END << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm( const PresidentialPardonForm &ref ): AForm("PresidentialPardonForm", 25, 5), _target(ref._target){
	std::cout << GREEN "PresidentialPardonForm Copy Constructor Called" END << std::endl;
}

PresidentialPardonForm::~PresidentialPardonForm( void ){
	std::cout << GREEN "PresidentialPardonForm Destructor Called" END << std::endl;
}

PresidentialPardonForm &PresidentialPardonForm::operator=( const PresidentialPardonForm &ref ){
	std::cout << GREEN "PresidentialPardonForm Assignment Operator Called" END << std::endl;
	if (this != &ref )
	{
		this->_signed = ref.getSign();
	}
	return (*this);
}

void PresidentialPardonForm::execute( Bureaucrat const & executor ) const{
	if (this->getSign() == false)
		throw ( AForm::AFormNotSigned() );
	if (this->getExecuteGrade() < executor.getGrade())
		throw ( AForm::GradeTooLowException() );

	std::cout << this->_target <<" has been pardoned by Zaphod Beeblebrox." << std::endl;
}
