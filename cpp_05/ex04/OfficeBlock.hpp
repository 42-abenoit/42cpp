#ifndef _HPP
# define _HPP

#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "Intern.hpp"
# include <iostream>

class	OfficeBlock	{
	private:
		Intern		*_intern;
		Bureaucrat	*_signer;
		Bureaucrat	*_executor;

	public:
		OfficeBlock();
		OfficeBlock(Intern *intern, Bureaucrat *signer, Bureaucrat *executor);
		virtual	~OfficeBlock();

		Intern	*getIntern();
		void	setIntern(Intern *intern);
		Bureaucrat	*getSigner();
		void	setSigner(Bureaucrat *signer);
		Bureaucrat	*getExecutor();
		void	setExecutor(Bureaucrat *executor);
		void	doBureaucracy(std::string form, std::string target);

	class	IncompleteTeam : public IException	{
		public:
			virtual const char* what() const throw()
			{
				return ("Can't do that, we're missing members.\n");
			}
			virtual void	raise() { throw (*this); }
	};
};

#endif
