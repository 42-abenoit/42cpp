#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"
#include "OfficeBlock.hpp"
#include <cstdlib>

void	doStuff(OfficeBlock &ob, std::string form, std::string target)
{
	try
	{
		ob.doBureaucracy(form, target);
	}
		catch (Form::GradeTooLowException &e)
		{
			std::cout << ob.getSigner()->getName() << " couldn't sign this Form because: " << e.what();
		}
		catch (Form::GradeTooHighException &e)
		{
			std::cout << "Cannot create Form: " << e.what();
		}
		catch (Form::FormNotSignedException &e)
		{
			std::cout << ob.getSigner()->getName() << " couldn't execute this Form because: " << e.what();
		}
		catch (Form::FormAlreadySignedException &e)
		{
			std::cout << ob.getSigner()->getName() << " couldn't sign this Form because: " << e.what();
		}
		catch (Intern::FormNotKnownException &e)
		{
			std::cout << "Coudn't create form: " << e.what();
		}
		catch (Bureaucrat::GradeTooLowException &e)
		{
			std::cout << "Cannot create Bureaucrat :" << e.what();
		}
		catch (Bureaucrat::GradeTooHighException &e)
		{
			std::cout << "Cannot create Bureaucrat :" << e.what();
		}
		catch (OfficeBlock::IncompleteTeam &e)
		{
			std::cout << e.what();
		}
}

int main(void)
{
	Bureaucrat	Tom("Tom", 1);
	Bureaucrat	Tim("Tim", 75);
	Bureaucrat	Joe("Joe", 22);
	Intern		Jim;
	OfficeBlock	ob(&Jim, &Tim, &Tom);
	OfficeBlock ob2;

	std::srand(time(NULL));
	doStuff(ob2, "ShrubberyCreationForm", "Reunion_room");
	doStuff(ob, "ShrubberyCreationForm", "Reunion_room");
	doStuff(ob, "RobotomyRequestForm", "intern");
	ob.setSigner(&Joe);
	doStuff(ob, "PresidentialPardonForm", "Jack");
}


