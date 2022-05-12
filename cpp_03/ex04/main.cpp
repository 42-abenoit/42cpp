#include "ClapTrap.hpp"
#include "FragTrap.hpp"
#include "ScavTrap.hpp"
#include "NinjaTrap.hpp"
#include "SuperTrap.hpp"

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

void	NinjaLife(void)	{
	int					action;
	int					mate;
	const std::string	names[] = {"Bob",
		"Bill", "Jim", "Kate", "Kim", "Doug",
		"James", "Tom", "Ellen", "Jack", "Cindy",
		"Pete", "Sam", "Meg"};
	NinjaTrap	Ninja(names[rand() % 14]);
	ClapTrap	Clap;
	NinjaTrap	Mate(names[std::rand() % 14]);
	ScavTrap	Scav(names[std::rand() % 14]);
	FragTrap	Frag(names[std::rand() % 14]);

	while (Ninja.isAlive())	{
		if ((action = rand() % 3) == 1)
			Ninja.passives((unsigned int)(rand() % 100));
		else if (action == 2)
		{
			mate = std::rand() % 4;
			if (mate == 0)
				Ninja.ninjaShoebox(Clap);
			else if (mate == 1)
				Ninja.ninjaShoebox(Mate);
			else if (mate == 2)
				Ninja.ninjaShoebox(Frag);
			else
				Ninja.ninjaShoebox(Scav);
		}
		else
			Ninja.attacks(names[rand() % 14]);
	}
}

void	SuperLife(void)	{
	int					action;
	int					mate;
	const std::string	names[] = {"Bob",
		"Bill", "Jim", "Kate", "Kim", "Doug",
		"James", "Tom", "Ellen", "Jack", "Cindy",
		"Pete", "Sam", "Meg"};
	SuperTrap	Super(names[std::rand() % 14]);
	ClapTrap	Clap;
	NinjaTrap	Ninja(names[rand() % 14]);
	ScavTrap	Scav(names[std::rand() % 14]);
	FragTrap	Frag(names[std::rand() % 14]);

	while (Super.isAlive())	{
		if ((action = rand() % 3) == 1)
			Super.passives((unsigned int)(rand() % 100));
		else if (action == 2)
		{
			mate = std::rand() % 4;
			if (mate == 0)
				Super.ninjaShoebox(Clap);
			else if (mate == 1)
				Super.ninjaShoebox(Ninja);
			else if (mate == 2)
				Super.ninjaShoebox(Frag);
			else
				Super.ninjaShoebox(Scav);
		}
		else
			Super.attacks(names[rand() % 14]);
	}
}

int main(void)	{
	std::srand(time(NULL));
	FragLife();
	ScavLife();
	NinjaLife();
	SuperLife();
}
