#ifndef FIRE_HPP
# define FIRE_HPP

# include <iostream>
# include "AMateria.hpp"
# include "ICharacter.hpp"

class Fire	:	public AMateria	{
	public:
		Fire();
		Fire(Fire const & ref);
		virtual ~Fire();

		virtual Fire* clone() const;
		virtual void use(ICharacter& target);

		Fire & operator=(Fire const&);
};

#endif
