#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form() :
	_reqSign(150),
	_reqExec(150),
	_type("Form")
{
	this->_signed = 0;
}

Form::Form(std::string type, int reqSign, int reqExec)	:
	_reqSign(checkGrade(reqSign)),
	_reqExec(checkGrade(reqExec)),
	_type(type)
{
	this->_signed = 0;
}

Form::Form(Form & ref)	:
	_signed(checkGrade(ref.isSigned())),
	_reqSign(checkGrade(ref.getSignReq())),
	_reqExec(checkGrade(ref.getExecReq())),
	_type(ref.getType())
{
}

Form::~Form()	{

}

int	Form::checkGrade(int Grade)
{
	if (Grade < 1)
		throw Form::GradeTooHighException();
	else if (Grade > 150)
		throw Form::GradeTooLowException();
	return (Grade);
}

bool	Form::isSigned()	const	{
	return (this->_signed);
}

std::string	Form::getType()	const	{
	return (this->_type);
}

void	Form::beSigned(int grade)	{
	if (grade <= this->_reqSign)
		this->_signed = 1;
	else
		throw Form::GradeTooLowException();
}

int		Form::getSignReq(void)	const	{
	return (this->_reqSign);
}

int		Form::getExecReq(void)	const	{
	return (this->_reqExec);
}

std::ostream & operator<<(std::ostream & o, Form const &ref)	{
	std::string	status;

	status = (ref.isSigned() ? "signed" : "unsigned");
	o << ref.getType() << " requires grade " << ref.getSignReq() 
		<< " for signature and grade " << ref.getExecReq()
		<< " for execution and is currently " << status << "." << std::endl;
	return (o);
}
