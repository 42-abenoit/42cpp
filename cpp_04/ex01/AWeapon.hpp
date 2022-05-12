#ifndef AWEAPON_HPP
# define AWEAPON_HPP

# include <iostream>

class	AWeapon	{
	protected:
		std::string	_name;
		int			_damage;
		int			_apcost;

	public:
		AWeapon();
		AWeapon(std::string const & name, int apcost, int damage);
		AWeapon(AWeapon const &);
		virtual	~AWeapon();
		AWeapon & operator=(AWeapon const &);

		std::string	getName() const;
		int			getDamage() const;
		int			getAPCost() const;

		virtual void	attack() const = 0;
};

#endif
