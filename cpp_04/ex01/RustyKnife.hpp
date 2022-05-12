#ifndef RUSTYKNIFE_HPP
# define RUSTYKNIFE_HPP

# include <iostream>
# include "AWeapon.hpp"

class	RustyKnife : public AWeapon	{
	public:
		RustyKnife();
		virtual	~RustyKnife();

		virtual void	attack() const	;
};

#endif
