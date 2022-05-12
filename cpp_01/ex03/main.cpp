#include "Zombie.hpp"
#include "ZombieHorde.hpp"

int	main(void)	{
	int	size;

	std::srand(time(NULL));
	size = (std::rand() % 10) + 1;
	ZombieHorde	horde(size);
	return (0);
}
