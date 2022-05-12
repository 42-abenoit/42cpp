#include "MiningBarge.hpp"
#include "DeepCoreMiner.hpp"
#include "StripMiner.hpp"
#include "Asteroid.hpp"
#include "Comet.hpp"

int	main(void)
{
	MiningBarge		junk;
	DeepCoreMiner	deep;
	StripMiner		strip;
	Asteroid		asteroid;
	Comet			comet;

	std::cout << "Equiping DeepMiner in slot 1" << std::endl;
	junk.equip(&deep);
	std::cout << "Mining Asteroid" << std::endl;
	junk.mine(&asteroid);
	std::cout << "Equiping StripMiner in slot 2" << std::endl;
	junk.equip(&strip);
	std::cout << "Mining Asteroid" << std::endl;
	junk.mine(&asteroid);
	std::cout << "Equiping DeepMiner in slot 3" << std::endl;
	junk.equip(&deep);
	std::cout << "Mining Asteroid" << std::endl;
	junk.mine(&asteroid);
	std::cout << "Equiping StripMiner in slot 4" << std::endl;
	junk.equip(&strip);
	std::cout << "Mining Comet" << std::endl;
	junk.mine(&comet);
	std::cout << "Equiping StripMiner in slot 5" << std::endl;
	junk.equip(&strip);
	std::cout << "Mining Comet" << std::endl;
	junk.mine(&comet);
}
