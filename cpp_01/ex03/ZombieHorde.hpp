#ifndef ZOMBIE_EVENT_HPP
# define ZOMBIE_EVENT_HPP

# include "Zombie.hpp"

class	ZombieHorde	{

	public:
		ZombieHorde(int n);
		~ZombieHorde(void);
		void	announce(void);

	private:
		Zombie	*_horde;
		int		_size;
};

#endif
