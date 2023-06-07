#ifndef SHRUBBERYCREATIONFORM_HPP
 #define SHRUBBERYCREATIONFORM_HPP

#include "AForm.hpp"
#include "Bureaucrat.hpp" // Kütüphanesi ekli olmaz ise methodları göremez.
#include <fstream>

class	Bureaucrat;

class	ShrubberyCreationForm : public AForm{

private:
	const std::string _target;
public:
	/* Constructor & Destructor */
	ShrubberyCreationForm( void );
	ShrubberyCreationForm( const std::string &target );
	ShrubberyCreationForm( const ShrubberyCreationForm &ref );
	~ShrubberyCreationForm( void );

	/* Basic Operators */
	ShrubberyCreationForm &operator=( const ShrubberyCreationForm &ref );

	/* Main Members Functions */
	void	executive( Bureaucrat const & executor ) const;

};

#endif
