#ifndef CURE_HPP
# define CURE_HPP

# include <iostream>
# include "AMateria.hpp"
# include "ICharacter.hpp"

class Cure	:	public AMateria	{
	public:
		Cure();
		Cure(Cure const & ref);
		virtual ~Cure();

		virtual Cure* clone() const;
		virtual void use(ICharacter& target);

		Cure & operator=(Cure const&);
};

#endif
