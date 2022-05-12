#ifndef ICE_HPP
# define ICE_HPP

# include <iostream>
# include "AMateria.hpp"
# include "ICharacter.hpp"

class Ice	:	public AMateria	{
	public:
		Ice();
		Ice(Ice const & ref);
		virtual ~Ice();

		virtual Ice* clone() const;
		virtual void use(ICharacter& target);

		Ice & operator=(Ice const&);
};

#endif
