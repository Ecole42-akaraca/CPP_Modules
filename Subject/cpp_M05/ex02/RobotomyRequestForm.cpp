#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm( void ): AForm("RobotomyRequestForm", 72, 45), _target("Default"){
	std::cout << GREEN "RobotomyRequestForm Default Constructor Called" END << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm( const std::string &target ): AForm("RobotomyRequestForm", 72, 45), _target(target){
	std::cout << GREEN "RobotomyRequestForm Constructor Called" END << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm( const RobotomyRequestForm &ref ): AForm("RobotomyRequestForm", 72, 45), _target(ref._target){
	std::cout << GREEN "RobotomyRequestForm Copy Constructor Called" END << std::endl;
}

RobotomyRequestForm::~RobotomyRequestForm( void ){
	std::cout << GREEN "RobotomyRequestForm Destructor Called" END << std::endl;
}

RobotomyRequestForm &RobotomyRequestForm::operator=( const RobotomyRequestForm &ref ){
	std::cout << GREEN "RobotomyRequestForm Assignment Operator Called" END << std::endl;
	if (this != &ref)
	{
		this->_signed = ref.getSign();
	}
	return (*this);
}

void RobotomyRequestForm::execute( Bureaucrat const & executor ) const{
	if (this->getSign() == false)
		throw ( AForm::AFormNotSigned() );
	if (this->getExecuteGrade() < executor.getGrade())
		throw ( AForm::GradeTooLowException() );
	
	std::cout << "#some drilling noises#" << std::endl;
	if (std::time(NULL) % 2 == 0)
		std::cout << this->_target << "has been robotomized successfully." << std::endl;
	else
		std::cout << this->_target << "has been failed." << std::endl;
}
