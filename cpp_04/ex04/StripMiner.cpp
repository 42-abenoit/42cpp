#include "StripMiner.hpp"

StripMiner::StripMiner()	{
}

StripMiner::StripMiner(StripMiner const &ref)	{
	(void)ref;
}

StripMiner::~StripMiner() {
}

void StripMiner::mine(IAsteroid *target)	{
	std::cout << "* strip mining... got " << target->beMined(this) << "! *" << std::endl;
	target->beMined(this);
}


StripMiner & StripMiner::operator=(StripMiner const &ref)	{
	(void)ref;
	return (*this);
}

