#include "ISpaceMarine.hpp"
#include "TacticalMarine.hpp"
#include "AssaultTerminator.hpp"
#include "ISquad.hpp"
#include "Squad.hpp"
#include <cstdlib>

int	main(void)	{
	int				end;
	ISpaceMarine	*marine;
	ISpaceMarine	*ptr;
	Squad			*squad = new Squad;

	end = 5;
	std::srand(time(NULL));
	for (int i = 0; i < end; i++)
	{
		if (rand() % 2 == 0)
			marine = new TacticalMarine;
		else
			marine = new AssaultTerminator;
		squad->push(marine);
		std::cout << "\e[36m";
		std::cout << "One more marine joined our forces, we are now "
					<< squad->getCount() << ", behold!" << std::endl;
		std::cout << "\e[0m";
		ptr = squad->getUnit(i + 1);
		ptr->battleCry();
		ptr->meleeAttack();
		ptr->rangedAttack();
	}
	std::cout << "\e[36m";
	std::cout << "An army of clones appears" << std::endl;
	std::cout << "\e[0m";
	Squad *squad2 = new Squad(*squad);
	for (int i = 0; i < end; i++)
	{
		ptr = squad2->getUnit(i + 1);
		ptr->battleCry();
		ptr->meleeAttack();
		ptr->rangedAttack();
	}
	std::cout << "\e[31m";
	std::cout << "Our first squad as been wiped, they shall be avenged!" << std::endl;
	std::cout << "\e[0m";
	delete squad;
	std::cout << "\e[36m";
	std::cout << "Some other clone squad arrives out of the blue" << std::endl;
	std::cout << "\e[0m";
	Squad squad3;
	squad3 = *squad2;
	for (int i = 0; i < end; i++)
	{
		if (i == (end / 2))
		{
			delete squad2;
			std::cout << "\e[31m";
			std::cout << "Another squad was destroyed, fight for your life brothers!" << std::endl;
			std::cout << "\e[0m";
		}
		ptr = squad3.getUnit(i + 1);
		ptr->battleCry();
		ptr->meleeAttack();
		ptr->rangedAttack();
	}
}
