#include "MutantStack.hpp"

template <typename T>
MutantStack<T>::MutantStack()	{
}

template <typename T>
MutantStack<T>::MutantStack(MutantStack &ref)	{
	this->c = ref.getC();
}

template <typename T>
MutantStack<T>::~MutantStack()	{
}

template <typename T>
MutantStack<T> & MutantStack<T>::operator=(MutantStack &ref)	{
	this->c = ref.getC();
	return *this;
}
