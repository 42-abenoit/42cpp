#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include "Form.hpp"

#include <iostream>
#include <exception>

class	Bureaucrat	{
	private:
		std::string	const	_name;
		int					_grade;

	public:
		Bureaucrat(std::string const &name, int const &grade);
		~Bureaucrat();
		Bureaucrat(Bureaucrat const & ref);

		std::string const	getName(void) const;
		int					getGrade() const;
		void				incGrade();
		void				decGrade();
		void				signForm(Form &ref);


		Bureaucrat & operator=(Bureaucrat const & ref);

	class	GradeTooLowException : public std::exception	{
		public:
			virtual const char* what() const throw()
			{
				return ("Grade too low\n");
			}
	};
	class	GradeTooHighException : public std::exception	{
		public:
			virtual const char* what() const throw()
			{
				return ("Grade too high\n");
			}
	};
};

std::ostream & operator<<(std::ostream & o, Bureaucrat const &ref);

#endif
