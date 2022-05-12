#include "Span.hpp"
#include <algorithm>
#include <limits.h>
#include <iostream>
#include <cstdlib>

Span::Span()	:	_data(0), _it(this->_data.end())
{
}

Span::Span(unsigned int N)	:	_data(N), _it(this->_data.begin())
{
	for (std::vector<int>::iterator it = this->_data.begin();
			it < this->_data.end(); it++)
		*it = 0;
}

Span::Span(Span &ref)	:	_data(ref.getData().size()), _it(this->_data.begin())
{
}

Span::~Span()	{
}

std::vector<int>	&Span::getData()	{
	return (this->_data);
}

void	Span::addNumber(int	n)	{
	if (this->_it != this->_data.end())
	{
		*(this->_it) = n;
		this->_it++;
	}
	else
		throw Span::OutOfRangeException();
}

template< class T >
void				Span::addNumber( T begin, T end)
{
	 T	it_range;
	std::vector<int>::iterator	it_data;

	if (end - begin > static_cast<int>(this->_data.size()))
		throw Span::OutOfRangeException();
	it_data = this->_data.begin();
	for (it_range = begin; it_range < end; it_range++)
	{
		*it_data = *it_range;
		it_data++;
	}
}

void		Span::fillRange(std::vector<int>::iterator begin,
						std::vector<int>::iterator end, int i)
{
	std::vector<int>::iterator	it;

	if (begin < this->_data.begin() || end > this->_data.end())
		throw Span::OutOfRangeException();
	for (it = begin; it < end; it++)
		*it = i;
}

void		Span::fillRangeRand(std::vector<int>::iterator begin,
						std::vector<int>::iterator end)
{
	std::vector<int>::iterator	it;

	if (begin < this->_data.begin() || end > this->_data.end())
		throw Span::OutOfRangeException();
	for (it = begin; it < end; it++)
		*it = std::rand() % 100000;
}

unsigned int	Span::longestSpan()	{
	std::vector<int>::iterator	it_min;
	std::vector<int>::iterator	it_max;

	if (this->_data.size() < 2)
		throw NoSpanToFindException();
	it_min = min_element(this->_data.begin(), this->_data.end());
	it_max = max_element(this->_data.begin(), this->_data.end());
	return (*it_max - *it_min);
}

unsigned int	Span::shortestSpan()	{
	std::vector<int>	sorted(this->_data);
	std::vector<int>::iterator	head_it;
	unsigned int				shortest;
	unsigned int				current;

	if (this->_data.size() < 2)
		throw NoSpanToFindException();
	std::sort(sorted.begin(), sorted.end());
	head_it = sorted.begin();
	shortest = UINT_MAX;
	while (head_it + 1 != sorted.end())
	{
		if (*head_it > *(head_it + 1))
			current = *head_it - *(head_it + 1);
		else
			current = *(head_it + 1) - *head_it;
		if (current < shortest)
			shortest = current;
		head_it++;
	}
	return (shortest);
}

Span & Span::operator=(Span &ref)	{
	this->_data.resize(0);
	this->_data.resize(ref.getData().size());
	this->_it = this->_data.begin();
	return (*this);
}

