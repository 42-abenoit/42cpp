#ifndef WILDWIZARD_HPP
# define WILDWIZARD_HPP

# include <iostream>
# include <cstdlib>
# include "Sorcerer.hpp"
# include "Victim.hpp"
# include "Peon.hpp"

class	WildWizard	:	public Sorcerer	{
	public:
		WildWizard(std::string const &name, std::string const &title);
		WildWizard(WildWizard const &wiz);
		WildWizard(Sorcerer const &sorc);
		virtual ~WildWizard(void);

		virtual void		polymorph(Victim const &) const;
		void		polymorph(Sorcerer const &) const;

		WildWizard & operator=(WildWizard const &wiz);
};

#endif
