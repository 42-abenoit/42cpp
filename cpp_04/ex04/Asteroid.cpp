#include "Asteroid.hpp"

Asteroid::Asteroid()	{
	this->_name = "Asteroid";
}

Asteroid::Asteroid(Asteroid const &ref)	{
	this->_name = ref.getName();
}

Asteroid::~Asteroid()	{

}

std::string Asteroid::beMined(DeepCoreMiner *miner) const	{
	(void)miner;
	return ("Dragonite");
}

std::string Asteroid::beMined(StripMiner *miner) const	{
	(void)miner;
	return ("Flavium");
}

std::string Asteroid::getName() const	{
	return (this->_name);
}


Asteroid & Asteroid::operator=(Asteroid const &ref)	{
	this->_name = ref.getName();
	return (*this);
}
