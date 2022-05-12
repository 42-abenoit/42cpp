#ifndef PEON_HPP
# define PEON_HPP

# include <iostream>
# include "Victim.hpp"

class	Peon	: public Victim	{
	public:
		Peon(std::string const &name);
		Peon(Peon const &peon);
		Peon(Victim const &vic);
		virtual	~Peon(void);

		virtual void		getPolymorphed(void) const;

		Peon & operator=(Peon const &peon);
};

std::ostream & operator<<(std::ostream & o, Peon const & peon);

#endif
