#include "Enemy.hpp"

Enemy::Enemy()	{
}

Enemy::Enemy(int hp, std::string const & type)	{
	this->setType(type);
	this->setHp(hp);
}

Enemy::Enemy(Enemy const & src)	{
	this->_type = src.getType();
	this->_hp = src.getHp();
}

Enemy::~Enemy()	{}

Enemy & Enemy::operator=(Enemy const &src)	{
	this->_type = src.getType();
	this->_hp = src.getHp();
	return *this;
}

std::string Enemy::getType() const	{
	return(this->_type);
}

void		Enemy::setType(std::string const &type)	{
	this->_type = type;
}

int		Enemy::getHp() const	{
	return(this->_hp);
}

void		Enemy::setHp(int hp)	{
	this->_hp = hp;
}

void	Enemy::takeDamage(int amount)	{
	if (amount >= 0)
	{
		if (this->_hp - amount < 0)
			this->_hp = 0;
		else
			this->_hp -= amount;
	}
}
