#include "Human.hpp"
#include <string>
#include <iostream>

void	Human::meleeAttack(std::string const & target)	{
	std::cout << "Attacking " << target << std::endl;
}

void	Human::rangedAttack(std::string const & target)	{
	std::cout << "Firing at " << target << std::endl;
}

void	Human::intimidatingShout(std::string const & target)	{
	std::cout << "Shouting at " << target << std::endl;
}

void	Human::action(std::string const & action_name, std::string const & target)	{
	std::string	indexTable[] = {"meleeAttack", "rangedAttack", "intimidatingShout"};
	funcPtr	funcTable[3] = {&Human::meleeAttack, &Human::rangedAttack, &Human::intimidatingShout};

	for (int i = 0; i < 3; i++)
	{
		if (indexTable[i].compare(action_name) == 0)
			(this->*funcTable[i])(target);
	}
	

}
