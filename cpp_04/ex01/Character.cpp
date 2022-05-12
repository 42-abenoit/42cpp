#include "Character.hpp"

Character::Character()	{
}

Character::Character(std::string const & name)	{
	this->_name = name;
	this->_ap = 40;
	this->_weapon = NULL;
}

Character::Character(Character const & src)	{
	this->_name = src.getName();
	this->_ap = 40;
	this->_weapon = NULL;
}

Character::~Character()	{}

Character & Character::operator=(Character const &src)	{
	this->_name = src.getName();
	this->_ap = src.getAP();
	this->_weapon = src.getWeapon();
	return (*this);
}

void	Character::recoverAP()	{
	if (this->_ap + 10 >= 40)
		this->_ap = 40;
	else
		this->_ap += 10;
}

void	Character::equip(AWeapon *ptr)	{
	this->_weapon = ptr;
}

void	Character::attack(Enemy *target)	{
	if (this->_weapon != NULL && target != NULL)
	{
		if (this->getAP() >= this->getWeapon()->getAPCost())
		{
			this->getWeapon()->attack();
			target->takeDamage(this->getWeapon()->getDamage());
			this->_ap -= this->getWeapon()->getAPCost();
			if (target->getHp() <= 0)
			{
				delete target;
			}
		}
	}
}

void	Character::attack(Enemy **target)	{
	if (this->_weapon != NULL && *target != NULL)
	{
		if (this->getAP() >= this->getWeapon()->getAPCost())
		{
			std::cout << this->getName() << " attacks " << (*target)->getType()
						<< " with a " << this->getWeapon()->getName() << std::endl;
			this->getWeapon()->attack();
			(*target)->takeDamage(this->getWeapon()->getDamage());
			this->_ap -= this->getWeapon()->getAPCost();
			if ((*target)->getHp() <= 0)
			{
				delete *target;
				*target = NULL;
			}
		}
	}
}

std::string Character::getName() const	{
	return (this->_name);
}

AWeapon *Character::getWeapon() const	{
	return (this->_weapon);
}

void	Character::setWeapon(AWeapon *ptr)	{
	this->_weapon = ptr;
}

int 	Character::getAP() const	{
	return (this->_ap);
}

std::ostream & operator<<(std::ostream & o, Character const & charac)	{
	if (charac.getWeapon() != NULL)	{
		o << charac.getName() << " has " << charac.getAP() << " AP and wields a "
			<< charac.getWeapon()->getName() << std::endl;
	}
	else	{
		o << charac.getName() << " has " << charac.getAP() << " AP and is unarmed"
			<< std::endl;
	}
	return (o);
}
