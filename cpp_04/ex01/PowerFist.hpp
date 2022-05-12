#ifndef POWERFIST_HPP
# define POWERFIST_HPP

# include <iostream>
# include "AWeapon.hpp"

class	PowerFist : public AWeapon	{
	public:
		PowerFist();
		virtual	~PowerFist();

		virtual void	attack() const	;
};

#endif
