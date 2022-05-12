#include "ClapTrap.hpp"
#include <sstream>

ClapTrap::ClapTrap(void)	{
	std::stringstream	stream;
	stream << std::uppercase << std::hex << rand();
	this->_name = "0x" + stream.str();
	this->_hitPoints = 0;
	this->_maxHitPoints = 0;
	this->_energyPoints = 0;
	this->_maxEnergyPoints = 0;
	this->_level = 0;
	this->_meleeAttackDamage = 0;
	this->_rangedAttackDamage = 0 ;
	this->_armorDamageReduction = 0;
	this->_alive = 0;
	std::cout << "\e[35m";
	std::cout << "Un CL4P-TP fait son apparition." << std::endl;
	std::cout << "\e[0m";
}

ClapTrap::~ClapTrap(void)	{
	std::cout << "\e[35m";
	std::cout << "Un CL4P-TP de moins, bon débarras !" << std::endl;
	std::cout << "\e[0m";
}

bool	ClapTrap::isAlive(void)	{
	return (this->_alive);
}

std::string const		ClapTrap::getName(void)	{
	return (this->_name);
}
