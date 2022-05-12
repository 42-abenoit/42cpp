#include "Comet.hpp"

Comet::Comet()	{
	this->_name = "Comet";
}

Comet::Comet(Comet const &ref)	{
	this->_name = ref.getName();
}

Comet::~Comet()	{

}

std::string Comet::beMined(DeepCoreMiner *miner) const	{
	(void)miner;
	return ("Meium");
}

std::string Comet::beMined(StripMiner *miner) const	{
	(void)miner;
	return ("Tartarite");
}

std::string Comet::getName() const	{
	return (this->_name);
}


Comet & Comet::operator=(Comet const &ref)	{
	this->_name = ref.getName();
	return (*this);
}
