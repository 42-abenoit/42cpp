#ifndef SHOCK_HPP
# define SHOCK_HPP

# include <iostream>
# include "AMateria.hpp"
# include "ICharacter.hpp"

class Shock	:	public AMateria	{
	public:
		Shock();
		Shock(Shock const & ref);
		virtual ~Shock();

		virtual Shock* clone() const;
		virtual void use(ICharacter& target);

		Shock & operator=(Shock const&);
};

#endif
