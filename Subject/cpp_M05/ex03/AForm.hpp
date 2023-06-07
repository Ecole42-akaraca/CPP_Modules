#ifndef AFORM_HPP
 #define AFORM_HPP

#include <iostream>
#include "Bureaucrat.hpp"
#include "Color.hpp"

class	Bureaucrat;

class	AForm{

protected:
	const std::string _name;
	bool _signed;
	const int _signGrade;
	const int _executeGrade;

public:
	/* Constructor & Destructor */
	AForm( void ); // default constructor 
	AForm( const std::string &name, int signGrade, int executeGrade ); // constructor
	AForm( const AForm &ref ); // copy constructor
	virtual ~AForm( void ); // virtual destructor

	/* Basic Operators */
	AForm &operator=( const AForm &ref ); // copy assignment operator overload.

	/* Getters & Setters */
	std::string getName() const;
	bool		getSign() const;
	int			getSignGrade() const;
	int			getExecuteGrade() const;

	/* Main Memeber Functions */
	void		beSigned( const Bureaucrat &ref );
	virtual void	executive( Bureaucrat const & executor ) const = 0;

	/* Exceptions */
	class GradeTooHighException : public std::exception{
		public:
			virtual const char *what(void) const throw();
	};

	class GradeTooLowException : public std::exception{
		public:
			virtual const char *what(void) const throw();
	};

	class AFormAlreadySigned : public std::exception{
		public:
			virtual const char *what(void) const throw();
	};

	class AFormNotSigned : public std::exception{
		public:
			virtual const char *what(void) const throw();
	};

};

std::ostream &operator<<( std::ostream &os, const AForm &obj );

#endif
