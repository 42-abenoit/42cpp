#ifndef CHARACTER_HPP
# define CHARACTER_HPP

# include <iostream>
# include "AWeapon.hpp"
# include "Enemy.hpp"

class	Character	{
	private:
		std::string	_name;
		AWeapon		*_weapon;
		int			_ap;

	public:
		Character();
		Character(std::string const & name);
		Character(Character const &);
		~Character();

		Character & operator=(Character const &);

		void	recoverAP();
		void	equip(AWeapon*);
		void	attack(Enemy*);
		void	attack(Enemy **target);
		std::string	getName() const;
		AWeapon		*getWeapon() const;
		void		setWeapon(AWeapon*);
		int			getAP() const;
};

std::ostream & operator<<(std::ostream & o, Character const & charac);

#endif
