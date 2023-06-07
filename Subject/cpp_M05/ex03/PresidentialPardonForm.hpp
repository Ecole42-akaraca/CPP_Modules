#ifndef PRESIDENTIALPARDONFORM_HPP
 #define PRESIDENTIALPARDONFORM_HPP

#include "AForm.hpp"
#include "Bureaucrat.hpp"

class	Bureaucrat;

class	PresidentialPardonForm : public AForm{

private:
	const std::string _target;
public:
	/* Constructor & Destructor */
	PresidentialPardonForm( void );
	PresidentialPardonForm( const std::string &target );
	PresidentialPardonForm( const PresidentialPardonForm &ref );
	~PresidentialPardonForm( void );

	/* Basic Operators */
	PresidentialPardonForm &operator=( const PresidentialPardonForm &ref );
	
	/* Main Members Functions */
	void	executive( Bureaucrat const & executor ) const;
};

#endif
