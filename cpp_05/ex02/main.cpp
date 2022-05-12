#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <cstdlib>

int main(void)
{
	Bureaucrat Tom("Tom", 1);
	Bureaucrat Tim("Tim", 75);
	Bureaucrat Bob("Bob", 150);
	ShrubberyCreationForm	shrub("HQ");
	RobotomyRequestForm		robo("Bob");
	PresidentialPardonForm	pardon("Tom");

	std::srand(time(NULL));
	Bob.signForm(shrub);
	Tom.executeForm(shrub);
	std::cout << shrub;
	Tim.signForm(shrub);
	std::cout << shrub;
	Tom.signForm(shrub);
	std::cout << shrub;
	Bob.executeForm(shrub);
	Tom.executeForm(shrub);
	Bob.signForm(robo);
	Tom.signForm(robo);
	Tom.executeForm(robo);
	Tom.signForm(pardon);
	Tom.executeForm(pardon);
}
