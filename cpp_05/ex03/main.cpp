#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"
#include <cstdlib>

int main(void)
{
	Bureaucrat	Tom("Tom", 1);
	Bureaucrat	Tim("Tim", 75);
	Bureaucrat	Bob("Bob", 150);
	Intern		Jim;
	Form		*ptr;

	std::srand(time(NULL));
	try
	{
		ptr = NULL;
		ptr = Jim.makeForm("PresidentialPardonForm", "Jack");
		Tom.signForm(*ptr);
		Tom.executeForm(*ptr);
		if (ptr != NULL)
			delete ptr;
	}
	catch (std::exception &e)
	{
		std::cout << "Coudn't create form: " << e.what();
	}
	try
	{
		ptr = NULL;
		ptr = Jim.makeForm("RobotomyRequestForm", "Jack");
		Tom.signForm(*ptr);
		Tom.executeForm(*ptr);
		if (ptr != NULL)
			delete ptr;
	}
	catch (std::exception &e)
	{
		std::cout << "Coudn't create form: " << e.what();
	}
	try
	{
		ptr = NULL;
		ptr = Jim.makeForm("ShrubberyCreationForm", "Jack");
		Tom.signForm(*ptr);
		Tom.executeForm(*ptr);
		if (ptr != NULL)
			delete ptr;
	}
	catch (std::exception &e)
	{
		std::cout << "Coudn't create form: " << e.what();
	}
	try
	{
		ptr = NULL;
		ptr = Jim.makeForm("ExecutiveOrderForm", "Jack");
		Tom.signForm(*ptr);
		Tom.executeForm(*ptr);
		if (ptr != NULL)
			delete ptr;
	}
	catch (std::exception &e)
	{
		std::cout << "Coudn't create form: " << e.what();
	}
}
