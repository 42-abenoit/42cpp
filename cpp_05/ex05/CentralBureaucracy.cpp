#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "Intern.hpp"
#include "CentralBureaucracy.hpp"

CentralBureaucracy::CentralBureaucracy()	{
	for (int i = 0; i < 20; i++)
	{
		this->_ob[i].setIntern(NULL);
		this->_ob[i].setSigner(NULL);
		this->_ob[i].setExecutor(NULL);
	}
	this->_queue = NULL;
	this->_qsize = 0;
}

CentralBureaucracy::~CentralBureaucracy()	{
	for (int i = 0; i < 20; i++)
	{
		if (this->_ob[i].getIntern() != NULL)
			delete (this->_ob[i].getIntern());
	}
	delete [] this->_queue;
}

void	CentralBureaucracy::feed(Bureaucrat *ptr)	{
	Intern	*internGenerator;

	for (int i = 0; i < 20; i++)
	{
		if (this->_ob[i].getSigner() == NULL)
		{
			internGenerator = new Intern;
			this->_ob[i].setIntern(internGenerator);
			this->_ob[i].setSigner(ptr);
			std::cout << "Greetings to " << ptr->getName()
						<< ", the new signer of Office Block "
						<< i << "." << std::endl;
			return ;
		}
		else if (this->_ob[i].getExecutor() == NULL)
		{
			this->_ob[i].setExecutor(ptr);
			std::cout << "Greetings to " << ptr->getName()
						<< ", the new executor of Office Block "
						<< i << "." << std::endl;
			return ;
		}
	}
	std::cout << "We don't have any use for you " << ptr->getName()
				<< ". Have you considered an internship in our company?"
				<< std::endl;
}

void	CentralBureaucracy::doBureaucracy()
{
	const std::string	form[] = { "ShrubberyCreationForm", "RobotomyRequestForm",
							"PresidentialPardonForm", "CrappyRequestForm" };

	for (int i = 0; i < this->_qsize; i++)
	{
		try
		{
			std::cout << "\e[36m";
			std::cout << "Office Block " << i % 20 << " is handling " << this->_queue[i]
						<< "'s request" << std::endl;
			std::cout << "\e[0m";
			this->_ob[i % 20].doBureaucracy(form[std::rand() % 4], this->_queue[i]);
		}
		catch (Form::GradeTooLowException &e)
		{
			std::cout << this->_ob[i % 20].getSigner()->getName() << " couldn't sign this Form because: " << e.what();
		}
		catch (Form::GradeTooHighException &e)
		{
			std::cout << "Cannot create Form: " << e.what();
		}
		catch (Form::FormNotSignedException &e)
		{
			std::cout << this->_ob[i % 20].getSigner()->getName() << " couldn't execute this Form because: " << e.what();
		}
		catch (Form::FormAlreadySignedException &e)
		{
			std::cout << this->_ob[i % 20].getSigner()->getName() << " couldn't sign this Form because: " << e.what();
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
}

void	CentralBureaucracy::queueUp(std::string target)	{
	int			i;
	std::string	*tmp;

	i = 0;
	tmp = new std::string[this->_qsize + 1];
	while (i < this->_qsize)
	{
		tmp[i] = this->_queue[i];
		i++;
	}
	tmp[i] = target;
	this->_qsize += 1;
	delete [] this->_queue;
	this->_queue = tmp;
}
