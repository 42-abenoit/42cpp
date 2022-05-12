#include "Brain.hpp"
#include <sstream>

Brain::Brain(void)	{}
Brain::~Brain(void)	{}

std::string	Brain::identify(void)	{
	std::stringstream stream;
	stream << std::hex << this;

	std::string	addr(stream.str());
	return (addr);
}
