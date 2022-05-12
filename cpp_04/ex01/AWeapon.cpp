#include "AWeapon.hpp"

AWeapon::AWeapon()	{
}

AWeapon::AWeapon(std::string const & name, int apcost, int damage)	{
	this->_name = name;
	this->_damage = damage;
	this->_apcost = apcost;
}

AWeapon::AWeapon(AWeapon const & src)	{
	this->_name = src.getName();
	this->_damage = src.getDamage();
	this->_apcost = src.getAPCost();
}

AWeapon::~AWeapon()	{}

AWeapon & AWeapon::operator=(AWeapon const &src)	{
	this->_name = src.getName();
	this->_damage = src.getDamage();
	this->_apcost = src.getAPCost();
	return *this;
}

std::string AWeapon::getName() const	{
	return(this->_name);
}

int		AWeapon::getDamage() const	{
	return(this->_damage);
}

int		AWeapon::getAPCost() const	{
	return(this->_apcost);
}
