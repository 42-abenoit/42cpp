#ifndef FORM_HPP
# define FORM_HPP

class	Bureaucrat;
# include <iostream>

class	Form	{
	private:
		bool	_signed;
		int	const	_reqSign;
		int	const	_reqExec;
		std::string const	_type;

	public:
		Form();
		Form(std::string type, int reqSign, int reqExec);
		Form(Form & ref);
		virtual	~Form();
		int		checkGrade(int reqGrade);
		bool	isSigned() const;
		void	beSigned(int grade);
		std::string getType(void) const;
		int		getSignReq(void) const;
		int		getExecReq(void) const;

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

std::ostream & operator<<(std::ostream & o, Form const &ref);

#endif
