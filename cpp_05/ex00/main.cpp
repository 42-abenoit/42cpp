#include "Bureaucrat.hpp"

int main(void)
{
	Bureaucrat Tom("Tom", 1);
	Bureaucrat Bob("Bob", 150);

	try
	{
		Bob.decGrade();
	}
	catch (std::exception & e)
	{
		std::cout << e.what();
	}
	std::cout << Tom;
	Tom.decGrade();
	std::cout << Tom;
	for (int i=0; i < 20; i++)
	{
		std::cout << "Company's shares are dropping, Tom's position is degrading!" << std::endl;
		Tom.decGrade();
		std::cout << Tom;
	}
	for (int i=0; i < 151; i++)
	{
		std::cout << "Bob caught the eyes of important people, he's a rising star!" << std::endl;
		try
		{
			Bob.incGrade();
		}
		catch (std::exception & e)
		{
			std::cout << e.what();
		}
		std::cout << Bob;
	}
	try
	{
		Bureaucrat Jim("Jim", 154);
	}
	catch (std::exception & e)
	{
		std::cout << "Cannot create Bureaucrat :" << e.what();
	}
	try
	{
		Bureaucrat Joe("Joe", 0);
	}
	catch (std::exception & e)
	{
		std::cout << "Cannot create Bureaucrat :" << e.what();
	}
	//Bureaucrat Joe("Joe", 0);
}
