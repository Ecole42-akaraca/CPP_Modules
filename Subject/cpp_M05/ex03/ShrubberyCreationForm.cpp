#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm( void ): AForm("ShrubberyCreationForm", 145, 137), _target("Default"){
	std::cout << GREEN "ShrubberyCreationForm Default Constructor Called" END << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm( const std::string &target ): AForm("ShrubberyCreationForm", 145, 137), _target(target){
	std::cout << GREEN "ShrubberyCreationForm Constructor Called" END << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm( const ShrubberyCreationForm &ref ): AForm("ShrubberyCreationFrom", 145, 137), _target(ref._target){
	std::cout << GREEN "ShrubberyCreationForm Copy Constructor Called" END << std::endl;
}

ShrubberyCreationForm::~ShrubberyCreationForm( void ){
	std::cout << GREEN "ShrubberyCreationForm Destructor Called" END << std::endl;
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=( const ShrubberyCreationForm &ref ){
	std::cout << GREEN "ShrubberyCreationForm Assignment Operator Called" END << std::endl;
	if (this != &ref)
	{
		this->_signed = ref.getSign();
	}
	return (*this);
}

/*
	https://ascii.co.uk/art/shrubbery
*/
void ShrubberyCreationForm::executive( Bureaucrat const & executor ) const{
	if (this->getSign() == false)
		throw ( AForm::AFormNotSigned() );
	if (this->getExecuteGrade() < executor.getGrade())
		throw ( AForm::GradeTooLowException() );

	std::string fileName = this->_target + "_shrubbery";

	std::ofstream file(fileName.c_str());
	file << "             .o00o" << std::endl;
	file << "           o000000oo"  << std::endl;
	file << "          00000000000o"  << std::endl;
	file << "         00000000000000"  << std::endl;
	file << "      oooooo  00000000  o88o"  << std::endl;
	file << "   ooOOOOOOOoo  ```''  888888"  << std::endl;
	file << " OOOOOOOOOOOO'.qQQQQq. `8888'"  << std::endl;
	file << "oOOOOOOOOOO'.QQQQQQQQQQ/.88'"  << std::endl;
	file << "OOOOOOOOOO'.QQQQQQQQQQ/ /q"  << std::endl;
	file << " OOOOOOOOO QQQQQQQQQQ/ /QQ"  << std::endl;
	file << "   OOOOOOOOO `QQQQQQ/ /QQ'"  << std::endl;
	file << "     OO:F_P:O `QQQ/  /Q'"  << std::endl;
	file << "        \\. \\ |  // |"  << std::endl;
	file << "        d\\ \\\\|_////"  << std::endl;
	file << "        qP| \\ _' `|Ob"  << std::endl;
	file << "           \\  / \\  \\Op"  << std::endl;
	file << "           |  | O| |"  << std::endl;
	file << "   _       /\\. \\_/ /\\"  << std::endl;
	file << "    `---__/|_\\   //|  __"  << std::endl;
	file << "          `-'  `-'`-'-'"  << std::endl;
	file.close();
}
