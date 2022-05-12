#include "MateriaSource.hpp"

MateriaSource::MateriaSource()	{
	for (int i = 0; i < 4; i++)
		this->_inventory[i] = NULL;
}

MateriaSource::MateriaSource(MateriaSource const &ref)	{
	for (int i = 0; i < 4; i++)
	{
		if (ref._inventory[i] != NULL)
			this->_inventory[i] = ref._inventory[i]->clone();
		else
			this->_inventory[i] = NULL;
	}
}

MateriaSource::~MateriaSource() {
	for (int i = 0; i < 4; i++)
	{
		if (this->_inventory[i] != NULL)
			delete this->_inventory[i];
	}
}

void MateriaSource::learnMateria(AMateria *m)	{
	int	i;

	i = 0;
	while (i < 4 && this->_inventory[i] != NULL)
		i++;
	if (i < 4)
		this->_inventory[i] = m;
}

AMateria* MateriaSource::createMateria(std::string const & type)	{
	for (int i = 0; i < 4; i++)
	{
		if (this->_inventory[i] != NULL)
		{
			if (this->_inventory[i]->getType() == type)
				return (this->_inventory[i]->clone());
		}
	}
	return (NULL);
}


MateriaSource & MateriaSource::operator=(MateriaSource const &ref)	{
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

