#include "Bureaucrat.hpp"
#include "Form.hpp"

int main(void)
{
	Bureaucrat Tom("Tom", 1);
	Bureaucrat Tim("Tim", 75);
	Bureaucrat Bob("Bob", 150);
	Form	easyForm("easyForm", 150, 150);
	Form	mediumForm("mediumForm", 75, 75);
	Form	hardForm("hardForm", 1, 1);

	try
	{
		Form	invForm1("invForm", 151, 150);
	}
	catch	(std::exception &e)
	{
		std::cout << "Cannot create Form: " << e.what();
	}
	try
	{
		Form	invForm2("invForm", 51, 0);
	}
	catch	(std::exception &e)
	{
		std::cout << "Cannot create Form: " << e.what();
	}
	std::cout << "An easyForm just arrived!" << std::endl;
	std::cout << easyForm;
	Bob.signForm(easyForm);
	std::cout << easyForm;
	std::cout << "A mediumForm just arrived!" << std::endl;
	std::cout << mediumForm;
	Bob.signForm(mediumForm);
	std::cout << mediumForm;
	Tim.signForm(mediumForm);
	std::cout << mediumForm;
	std::cout << "An HardForm just arrived!" << std::endl;
	std::cout << hardForm;
	Tim.signForm(hardForm);
	std::cout << hardForm;
	Tom.signForm(hardForm);
	std::cout << hardForm;
}
