#ifndef ROBOTOMYREQUESTFORM_HPP
 #define ROBOTOMYREQUESTFORM_HPP

#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include <ctime>

class	Bureaucrat;

class	RobotomyRequestForm : public AForm{

private:
	const std::string _target;
public:
	/* Constrcutor & Destructor */
	RobotomyRequestForm( void );
	RobotomyRequestForm( const std::string &target );
	RobotomyRequestForm( const RobotomyRequestForm &ref );
	~RobotomyRequestForm( void );

	/* Basic Operators */
	RobotomyRequestForm &operator=( const RobotomyRequestForm &ref );

	/* Main Member Functions */
	void	executive( Bureaucrat const & executor ) const;

};

#endif
