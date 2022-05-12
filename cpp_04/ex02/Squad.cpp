#include "Squad.hpp"

Squad::Squad()	{
	this->_ptr = NULL;
	this->_size = 0;
}

Squad::Squad(Squad const &ref)	{
	ISpaceMarine	*cpy;
	ISpaceMarine	**tmp = new ISpaceMarine*[ref.getCount()];

	this->_size = ref.getCount();
	for (int i = 0; i < this->_size; i++)
	{
		cpy = ref.getUnit(i + 1)->clone();
		tmp[i] = cpy;
	}
	this->_ptr = tmp;
}

Squad::~Squad()	{
	if (this->_ptr != NULL)
	{
		for (int i = 0; i < this->_size; i++)
			delete this->_ptr[i];
		delete [] this->_ptr;
	}
}

int	Squad::getCount() const	{
	return (this->_size);
}

ISpaceMarine	*Squad::getUnit(int	index) const	{
	if (index > 0 && index < this->_size + 1)
		return (this->_ptr[index - 1]);
	else
		return (NULL);
}

int	Squad::push(ISpaceMarine *ptr)	{
	int				i;
	ISpaceMarine	**tmp = new ISpaceMarine*[this->_size + 1];

	i = 0;
	while (i < this->_size)
	{
		if (ptr == NULL || ptr == this->_ptr[i])
		{
			delete [] tmp;
			return (this->_size);
		}
		tmp[i] = (this->_ptr)[i];
		i++;
	}
	tmp[i] = ptr;
	if (this->_ptr != NULL)
		delete [] this->_ptr;
	this->_ptr = tmp;
	this->_size += 1;
	return (this->_size);
}

Squad & Squad::operator=(Squad const &ref)	{
	ISpaceMarine	*cpy;
	ISpaceMarine	**tmp = new ISpaceMarine*[ref.getCount()];

	if (this->_ptr != NULL)
	{
		for (int i = 0; i < this->_size; i++)
			delete this->_ptr[i];
		delete [] this->_ptr;
	}
	this->_size = ref.getCount();
	for (int i = 0; i < this->_size; i++)
	{
		cpy = ref.getUnit(i + 1)->clone();
		tmp[i] = cpy;
	}
	this->_ptr = tmp;
	return (*this);
}
