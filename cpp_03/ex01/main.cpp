#include "FragTrap.hpp"
#include "ScavTrap.hpp"

void	FragLife(void)	{
	const std::string	names[] = {"Bob",
		"Bill", "Jim", "Kate", "Kim", "Doug",
		"James", "Tom", "Ellen", "Jack", "Cindy",
		"Pete", "Sam", "Meg"};
	FragTrap	Frag(names[rand() % 14]);

	while (Frag.isAlive())	{
		if (rand() % 2 == 1)
			Frag.passives((unsigned int)(rand() % 100));
		else
			Frag.attacks(names[rand() % 14]);
	}
}

void	ScavLife(void)	{
	const std::string	names[] = {"Bob",
		"Bill", "Jim", "Kate", "Kim", "Doug",
		"James", "Tom", "Ellen", "Jack", "Cindy",
		"Pete", "Sam", "Meg"};
	ScavTrap	Scav(names[rand() % 14]);

	while (Scav.isAlive())	{
		if (rand() % 2 == 1)
			Scav.passives((unsigned int)(rand() % 100));
		else
			Scav.attacks(names[rand() % 14]);
	}
}

int main(void)	{
	std::srand(time(NULL));
	FragLife();
	ScavLife();
}
