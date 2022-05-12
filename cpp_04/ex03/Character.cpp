#include "Character.hpp"

Character::Character(std::string const &name)	{
	this->_name = name;
	this->_hp = 100;
	for (int i = 0; i < 4; i++)
		this->_inventory[i] = NULL;
}

Character::Character(Character const &ref)	{
	this->_name = ref.getName();
	this->_hp = ref._hp;
	for (int i = 0; i < 4; i++)
	{
		if (ref._inventory[i] != NULL)
			this->_inventory[i] = ref._inventory[i]->clone();
		else
			this->_inventory[i] = NULL;
	}
}

Character::~Character() {
	for (int i = 0; i < 4; i++)
	{
		if (this->_inventory[i] != NULL)
			delete this->_inventory[i];
	}
}

std::string const & Character::getName() const	{
	return (this->_name);
}

void Character::equip(AMateria* m)	{
	int	i;

	i = 0;
	while (i < 4 && this->_inventory[i] != NULL)
		i++;
	if (i < 4)
		this->_inventory[i] = m;
}

void Character::unequip(int idx)	{
	if (this->_inventory[idx] != NULL)
		this->_inventory[idx] = NULL;
}

void Character::use(int idx, ICharacter& target)	{
	if (this->_inventory[idx] != NULL)
		this->_inventory[idx]->use(target);
}

void Character::takeDamage(int amount)	{
	this->_hp -= amount;
}

Character & Character::operator=(Character const &ref)	{
	this->_name = ref.getName();
	this->_hp = ref._hp;
	for (int i = 0; i < 4; i++)
	{
		if (this->_inventory[i] != NULL)
			delete this->_inventory[i];
		if (ref._inventory[i] != NULL)
				this->_inventory[i] = ref._inventory[i]->clone();
		else
			this->_inventory[i] = NULL;
	}
	return (*this);
}
