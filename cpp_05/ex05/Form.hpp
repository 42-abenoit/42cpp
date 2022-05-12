#ifndef FORM_HPP
# define FORM_HPP

class	Bureaucrat;
# include <iostream>

class	Form	{
	private:
		bool	_signed;
		int const	_reqSign;
		int const	_reqExec;
		std::string	const _type;
		std::string	_target;

	public:
		Form();
		Form(std::string type, int reqSign, int reqExec, std::string target);
		Form(Form const & ref);
		virtual	~Form();
		int	checkGrade(int Grade);
		void	setSign(bool sign);
		bool	isSigned() const;
		void	beSigned(Bureaucrat & ref);
		std::string getType(void) const;
		std::string getTarget(void) const;
		int		getSignReq(void) const;
		int		getExecReq(void) const;
		virtual void	execute(Bureaucrat const & executor) const;
		virtual Form*	clone(std::string target);

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
	class	FormNotSignedException : public std::exception	{
		public:
			virtual const char* what() const throw()
			{
				return ("Form is not signed\n");
			}
	};
	class	FormAlreadySignedException : public std::exception	{
		public:
			virtual const char* what() const throw()
			{
				return ("Form is already signed\n");
			}
	};
};

std::ostream & operator<<(std::ostream & o, Form const &ref);

#endif
