#ifndef BUREAUCRAT_HPP
 #define BUREAUCRAT_HPP

#include "Form.hpp"
#include "Color.hpp"
#include <iostream>

class	Form;

class Bureaucrat{

private:
	std::string const	_name;
	int					_grade;

public:
	/* Constructors & Destructors */
	Bureaucrat();
	Bureaucrat( const std::string &name, int grade );
	Bureaucrat( const Bureaucrat &ref );
	~Bureaucrat();

	/* Basic Operators */
	Bureaucrat &operator=( const Bureaucrat &ref );

	/* Getters & Setters */
	std::string getName() const;
	int			getGrade() const;

	/* Main Member Functions */
	void	upGrade( void );
	void	downGrade( void );
	void	signForm( Form &ref );

	/* Exceptions */
	class GradeTooHighException : public std::exception{
		public:
			virtual const char *what(void) const throw();
	};

	class GradeTooLowException : public std::exception{
		public:
			virtual const char *what(void) const throw();
	};
};

std::ostream &operator<<( std::ostream &os, const Bureaucrat &obj );

#endif
