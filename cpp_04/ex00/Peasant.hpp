#ifndef PEASANT_HPP
# define PEASANT_HPP

# include <iostream>
# include "Victim.hpp"

class	Peasant	: public Victim	{
	public:
		Peasant(std::string const &name);
		Peasant(Peasant const &peon);
		Peasant(Victim const &vic);
		virtual	~Peasant(void);

		virtual void		getPolymorphed(void) const;

		Peasant & operator=(Peasant const &peon);
};

std::ostream & operator<<(std::ostream & o, Peasant const & peon);

#endif
