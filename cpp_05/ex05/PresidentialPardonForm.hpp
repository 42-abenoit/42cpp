#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

# include "Form.hpp"

# include <iostream>
# include <fstream>
# include <cstdlib>

class	PresidentialPardonForm	:	public	Form	{
	public:
		PresidentialPardonForm(std::string target);
		PresidentialPardonForm(PresidentialPardonForm & ref);
		virtual	~PresidentialPardonForm();
		virtual void	execute(Bureaucrat const & executor) const;
		virtual Form*	clone(std::string target);
};

#endif
