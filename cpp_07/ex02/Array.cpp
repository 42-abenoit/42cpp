#include "Array.hpp"

template	< typename T >
Array<T>::Array()	{
	this->_data = NULL;
	this->_size = 0;
}

template	< typename T >
Array<T>::Array(unsigned int n)	{
	this->_data = new T[n];
	for (unsigned int i = 0; i < n; i++)
		this->_data[i] = 0;
	this->_size = n;
}

template	<>
Array<std::string>::Array(unsigned int n)	{
	this->_data = new std::string[n];
	for (unsigned int i = 0; i < n; i++)
		this->_data[i] = "";
	this->_size = n;
}

template	< typename T >
Array<T>::Array(Array &ref)	{
	this->_size = ref.size();
	this->_data = new T[this->_size];
	for (unsigned int i = 0; i < this->_size; i++)
		this->_data[i] = ref.getData(i);
}

template	< typename T >
Array<T>::~Array()	{
	delete [] this->_data;
}

template	< typename T >
T	&Array<T>::getData(unsigned int index) const {
	if (index < this->_size)
		return (this->_data[index]);
	else
		throw Array<T>::OutOfRangeException();
}

template	< typename T >
unsigned int	Array<T>::size() const	{
	return (this->_size);
}

template	< typename T >
Array<T> & Array<T>::operator=(Array &ref)	{
	delete [] this->_data;
	this->_size = ref.size();
	this->_data = new T[this->_size];
	for (unsigned int i = 0; i < this->_size; i++)
		this->_data[i] = ref.getData(i);
	return (*this);
}

template	< typename T >
T & Array<T>::operator[](unsigned int index)	{
	return (getData(index));
}

template	< typename T >
T & Array<T>::operator[](unsigned int index) const	{
	return (getData(index));
}
