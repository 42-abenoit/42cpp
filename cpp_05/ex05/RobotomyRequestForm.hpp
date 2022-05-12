#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

# include "Form.hpp"

# include <iostream>
# include <fstream>
# include <cstdlib>

class	RobotomyRequestForm	:	public	Form	{
	public:
		RobotomyRequestForm(std::string target);
		RobotomyRequestForm(RobotomyRequestForm & ref);
		virtual	~RobotomyRequestForm();
		virtual void	execute(Bureaucrat const & executor) const;
		virtual Form*	clone(std::string target);
};

#endif
