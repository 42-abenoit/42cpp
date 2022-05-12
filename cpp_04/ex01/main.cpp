#include <cstdlib>
#include "AWeapon.hpp"
#include "PlasmaRifle.hpp"
#include "PowerFist.hpp"
#include "RustyKnife.hpp"
#include "SuperMutant.hpp"
#include "RabidHound.hpp"
#include "RadScorpion.hpp"
#include "Character.hpp"

int		encounter(Character &me)	{
	int		pick;
	Enemy	*ptr;

	if ((pick = rand() % 10) > 7)
		ptr = new RadScorpion;
	else if (pick > 3)
		ptr = new RabidHound;
	else
		ptr = new SuperMutant;

	std::cout << "\e[36m";
	std::cout << "You bump into a " << ptr->getType() << std::endl;
	std::cout << "\e[0m";
	if (me.getWeapon() == NULL)
	{
		std::cout << "\e[31m";
		std::cout << "You should have brought a weapon! Too bad, you're dead now..."
					<< std::endl;
		std::cout << "\e[0m";
		delete ptr;
		return (1);
	}
	while (ptr && ptr->getHp() > 0)
	{
		me.attack((Enemy**)&ptr);
		if (ptr == NULL)
			return (0);
		if (me.getAP() < me.getWeapon()->getAPCost() && ptr != NULL && ptr->getHp() != 0)
		{
			std::cout << "\e[31m";
			std::cout << "You are too tired, " << ptr->getType()
						<< " got the best of you!" << std::endl;
			std::cout << "\e[0m";
			delete ptr;
			ptr = NULL;
			return (1);
		}
	}
	return (0);
}

void	recoverWeapon(Character &me)
{
	int		pick;
	AWeapon *ptr;
	std::string	buf;

	if ((pick = rand() % 10) > 8)
		ptr = new PlasmaRifle;
	else if (pick > 1)
		ptr = new RustyKnife;
	else
		ptr = new PowerFist;
	std::cout << "\e[36m";
	std::cout << "You find a " << ptr->getName() << " an old stash." << std::endl;
	std::cout << "Do you want to equip it?(y/N)";
	std::cout << "\e[0m";
	std::getline(std::cin, buf);
	if (buf == "y")
	{
		if (me.getWeapon() != NULL)
			delete me.getWeapon();
		me.setWeapon(ptr);
	}
	else
		delete ptr;
	
}

void	recover(Character &me)	{
	if (rand() % 2 == 0)
	{
		me.recoverAP();
		std::cout << "\e[32m";
		std::cout << "You settle for the night, your APs are recovered" << std::endl;
		std::cout << "\e[0m";
	}
	else
		recoverWeapon(me);
}

int	main(void)	{
	Character	me("Jim");
	int			pos;
	int			town;
	
	pos = 0;
	std::srand(time(NULL));
	town = ((rand() % 10) + 1) + ((rand() % 10) + 1);
	std::cout << "You are stranded in the Wasteland. According to your map, there should be a town "
				<< town << "km away from your position." << std::endl;
	while (pos < town)
	{
		std::cout << me;
		if (rand() % 10 > 5)
		{
			if (encounter(me))
			{
				if (me.getWeapon() != NULL)
					delete me.getWeapon();
				return (0);
			}
		}
		else
			recover(me);
		pos += 1;
	}
	std::cout << "\e[32m";
	std::cout << "You manage to find shelter in a small town. You are safe, at least for now!"
				<< std::endl;
	std::cout << "\e[0m";
	if (me.getWeapon() != NULL)
		delete me.getWeapon();
	return (0);
}
