#ifndef SORCERER_HPP
# define SORCERER_HPP

# include <iostream>
# include "Victim.hpp"
# include "Peon.hpp"

class	Sorcerer	{
	public:
		Sorcerer() {};
		Sorcerer(std::string const &name, std::string const &title);
		Sorcerer(Sorcerer const &sorc);
		virtual ~Sorcerer(void);

		std::string	getName(void) const;
		void		setName(std::string const &name);
		std::string	getTitle(void) const;
		void		setTitle(std::string const &title);
		std::string	introduce(void) const;

		virtual void		polymorph(Victim const &) const;
		void				getPolymorphed(void) const;

		Sorcerer & operator=(Sorcerer const &sorc);

	protected:
		std::string	_name;
		std::string	_title;
};

std::ostream & operator<<(std::ostream & o, Sorcerer const & sorc);

#endif
