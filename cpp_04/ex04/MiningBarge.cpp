#include "MiningBarge.hpp"

MiningBarge::MiningBarge()	{
	for (int i = 0; i < 4; i++)
		this->_slots[i] = NULL;
}

MiningBarge::MiningBarge(MiningBarge const &ref)	{
	for (int i = 0; i < 4; i++)
		this->_slots[i] = ref._slots[i];
}

MiningBarge::~MiningBarge()	{
}

void MiningBarge::equip(IMiningLaser *laser)	{
	int	i;

	i = 0;
	while (i < 4 && this->_slots[i] != NULL)
		i++;
	if (i < 4)
		this->_slots[i] = laser;
}

void MiningBarge::mine(IAsteroid *target) const	{
	for (int i = 0; i < 4; i++)
	{
		if (this->_slots[i] != NULL)
			this->_slots[i]->mine(target);
	}
}


MiningBarge & MiningBarge::operator=(MiningBarge const &ref)	{
	for (int i = 0; i < 4; i++)
		this->_slots[i] = ref._slots[i];
	return (*this);
}
