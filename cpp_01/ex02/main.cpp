#include "Zombie.hpp"
#include "ZombieEvent.hpp"

int	main(void)	{
	Zombie		*ptr;
	ZombieEvent	event;

	std::srand(time(NULL));
	for (int i = 0; i < 10; i++)
	{
		ptr = event.randomChump();
		delete ptr;
	}
	return (0);
}
