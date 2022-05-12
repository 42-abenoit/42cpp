#include "Sorcerer.hpp"
#include "WildWizard.hpp"
#include "Victim.hpp"
#include "Peon.hpp"
#include "Peasant.hpp"

int	main(void)
{
	Sorcerer Robert("Robert", "the Magnificent");
	Victim	Jim("Jim");
	Peon	Tim("Tim");
	Peasant	Tom("Tom");
	WildWizard	Jack("Jack", "the Unexpected");

	std::srand(time(NULL));
	std::cout << Robert;
	std::cout << Jim;
	std::cout << Tim;
	std::cout << Tom;
	std::cout << Jack;

	Robert.polymorph(Jim);
	Robert.polymorph(Tim);
	Robert.polymorph(Tom);
	Jack.polymorph(Robert);
	Jack.polymorph(Tim);
	Jack.polymorph(Tom);

	return (0);
}
