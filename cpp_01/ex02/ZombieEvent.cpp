#include "ZombieEvent.hpp"
#include <string>

ZombieEvent::ZombieEvent(void)	{
}

ZombieEvent::~ZombieEvent(void)	{
}

std::string	ZombieEvent::setZombieType(void)	{
	const std::string types[] = {"Braindead", "Infected", "Rotten"};

	return (types[std::rand() % 3]);
}

Zombie	*ZombieEvent::newZombie(std::string name)	{
	Zombie	*ptr = new Zombie(name, ZombieEvent::setZombieType());

	return (ptr);
}

Zombie	*ZombieEvent::randomChump(void)	{
	const std::string	names[] = {"Bob",
		"Bill", "Jim", "Kate", "Kim", "Doug",
		"James", "Tom", "Ellen", "Jack", "Cindy",
		"Pete", "Sam", "Meg"};
	
	return (newZombie(names[std::rand() % 14]));
}
