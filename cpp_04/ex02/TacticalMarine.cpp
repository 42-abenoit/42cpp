#include "TacticalMarine.hpp"

TacticalMarine::TacticalMarine()	{
	std::cout << "Tactical Marine ready for battle!" << std::endl;
}

TacticalMarine::TacticalMarine(TacticalMarine const &ref)	{
	(void)ref;
	std::cout << "Tactical Marine ready for battle!" << std::endl;
}

TacticalMarine::~TacticalMarine()	{
	std::cout << "Aaargh..." << std::endl;
}

ISpaceMarine*	TacticalMarine::clone() const	{
	ISpaceMarine	*ptr = new TacticalMarine;
	return (ptr);
}

void	TacticalMarine::battleCry() const	{
	std::cout << "For the holy PLOT!" << std::endl;
}

void	TacticalMarine::rangedAttack() const	{
	std::cout << "* attacks with a bolter *" << std::endl;
}

void	TacticalMarine::meleeAttack() const	{
	std::cout << "* attacks with a chainsword *" << std::endl;
}

TacticalMarine & TacticalMarine::operator=(TacticalMarine const& ref)	{
	(void)ref;
	return (*this);
}
