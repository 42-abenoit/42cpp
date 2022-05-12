#ifndef CENTRALBUREAUCRACY_HPP
# define CENTRALBUREAUCRACY_HPP

class	Bureaucrat;
# include "OfficeBlock.hpp"
# include <iostream>
# include <cstdlib>

class	CentralBureaucracy	{
	private:
		OfficeBlock	_ob[20];
		std::string	*_queue;
		int			_qsize;

	public:
		CentralBureaucracy();
		virtual	~CentralBureaucracy();

		void	feed(Bureaucrat	*ptr);
		void	doBureaucracy();
		void	queueUp(std::string target);
};

#endif
