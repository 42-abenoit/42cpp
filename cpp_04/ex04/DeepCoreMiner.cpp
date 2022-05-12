#include "DeepCoreMiner.hpp"

DeepCoreMiner::DeepCoreMiner()	{
}

DeepCoreMiner::DeepCoreMiner(DeepCoreMiner const &ref)	{
	(void)ref;
}

DeepCoreMiner::~DeepCoreMiner() {
}

void DeepCoreMiner::mine(IAsteroid *target)	{
	std::cout << "* mining deep... got " << target->beMined(this) << "! *" << std::endl;
}


DeepCoreMiner & DeepCoreMiner::operator=(DeepCoreMiner const &ref)	{
	(void)ref;
	return (*this);
}

