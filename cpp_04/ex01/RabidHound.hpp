#ifndef RABIDHOUND_HPP
# define RABIDHOUND_HPP

# include <iostream>
# include "Enemy.hpp"

class	RabidHound	: public Enemy	{
	public:
		RabidHound();
		RabidHound(RabidHound const &);
		virtual	~RabidHound();

		virtual void	takeDamage(int);
};

#endif
