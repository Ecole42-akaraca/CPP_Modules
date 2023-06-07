#ifndef FORM_HPP
 #define FORM_HPP

#include "Bureaucrat.hpp"
#include "Color.hpp"
#include <iostream>

class Bureaucrat;

class Form{

private:
	const std::string _name;
	bool _signed;
	const int _signGrade;
	const int _executeGrade;

public:
	/* Constructor & Destructors */
	Form( void );
	Form( const std::string &name, int signGrade, int executeGrade );
	Form( const Form &ref );
	~Form( void );

	/* Basic Operators */
	Form &operator=( const Form &ref );

	/* Getters & Setters */
	std::string	getName() const;
	bool		getSign() const;
	int			getSignGrade() const;
	int			getExecuteGrade() const;

	/* Main Member Functions */
	void	beSigned( const Bureaucrat &ref );

	/* Exceptions */
	class GradeTooHighException : public std::exception{
		public:
			virtual const char *what(void) const throw();
	};

	class GradeTooLowException : public std::exception{
		public:
			virtual const char *what(void) const throw();
	};
	
	class FormAlreadySigned : public std::exception{
		public:
			virtual const char *what(void) const throw();
	};
};

std::ostream &operator<<( std::ostream &os, const Form &obj );

#endif
