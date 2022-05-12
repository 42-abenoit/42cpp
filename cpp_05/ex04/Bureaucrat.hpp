#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

class	Form;

# include <iostream>
# include "IException.hpp"

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
		void				executeForm(Form const & form);


		Bureaucrat & operator=(Bureaucrat const & ref);

	class	GradeTooLowException : public IException	{
		public:
			virtual const char* what() const throw()
			{
				return ("Grade too low\n");
			}
			virtual void	raise() { throw (*this); }
	};
	class	GradeTooHighException : public IException	{
		public:
			virtual const char* what() const throw()
			{
				return ("Grade too high\n");
			}
			virtual void	raise() { throw (*this); }
	};
};

std::ostream & operator<<(std::ostream & o, Bureaucrat const &ref);

#endif
