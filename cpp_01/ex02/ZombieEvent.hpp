#ifndef ZOMBIE_EVENT_HPP
# define ZOMBIE_EVENT_HPP

# include "Zombie.hpp"

class	ZombieEvent	{

	public:
		ZombieEvent(void);
		~ZombieEvent(void);

		static std::string	setZombieType(void);
		Zombie		*newZombie(std::string name);
		Zombie		*randomChump(void);
};

#endif
