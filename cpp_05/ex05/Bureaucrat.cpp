#include "Bureaucrat.hpp"
#include "Form.hpp"


Bureaucrat::Bureaucrat(std::string const &name, int const &grade):	_name(name)	{
	if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
	else if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
	this->_grade = grade;
}

Bureaucrat::~Bureaucrat()	{
}

Bureaucrat::Bureaucrat(Bureaucrat const & ref):	_name(ref.getName())	{
	if (ref.getGrade() < 1)
		throw Bureaucrat::GradeTooHighException();
	if (ref.getGrade() > 150)
		throw Bureaucrat::GradeTooLowException();
	this->_grade = ref.getGrade();
}

std::string const	Bureaucrat::getName(void) const	{
	return (this->_name);
}

int					Bureaucrat::getGrade() const	{
	return (this->_grade);
}

void				Bureaucrat::incGrade()	{
	if (this->_grade - 1 < 1)
		throw Bureaucrat::GradeTooHighException();
	this->_grade -= 1;
}

void				Bureaucrat::decGrade()	{
	if (this->_grade + 1 > 150)
		throw Bureaucrat::GradeTooLowException();
	this->_grade += 1;
}

void				Bureaucrat::signForm(Form &ref)	{
	try
	{
		ref.beSigned(*this);
	}
	catch (std::exception &e)
	{
		std::cout << this->getName() << " cannot sign " << ref.getType() << " because " << e.what();
	}
}

void				Bureaucrat::executeForm(Form const & form)	{
	try
	{
		form.execute(*this);
	}
	catch (std::exception &e)
	{
		std::cout << this->getName() << " cannot execute " << form.getType() << " because " << e.what();
	}
}

Bureaucrat & Bureaucrat::operator=(Bureaucrat const & ref)	{
	if (ref.getGrade() < 1)
		throw Bureaucrat::GradeTooHighException();
	if (ref.getGrade() > 150)
		throw Bureaucrat::GradeTooLowException();
	this->_grade = ref.getGrade();
	return (*this);
}

std::ostream & operator<<(std::ostream & o, Bureaucrat const &ref){
	o << ref.getName() << ", bureaucrat grade "
		<< ref.getGrade() << "." << std::endl;
	return (o);
}
