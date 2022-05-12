#include "FragTrap.hpp"

int main(void)	{
	FragTrap	Bob("Bob");
	const std::string	names[] = {"Bob",
		"Bill", "Jim", "Kate", "Kim", "Doug",
		"James", "Tom", "Ellen", "Jack", "Cindy",
		"Pete", "Sam", "Meg"};

	std::srand(time(NULL));
	while (Bob.isAlive())	{
		if (rand() % 2 == 1)
			Bob.passives((unsigned int)(rand() % 100));
		else
			Bob.attacks(names[rand() % 14]);
	}
}
