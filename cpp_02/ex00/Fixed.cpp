#include "Fixed.hpp"
#include<iostream>

int Fixed::_frac = 8;

Fixed::Fixed(void)	{
	std::cout << "Default constructor called" << std::endl;
	this->_val = 0;
}

Fixed::Fixed(const Fixed &fixed)	{
	std::cout << "Copy constructor called" << std::endl;
	*this = fixed;
}

Fixed::~Fixed(void)	{
	std::cout << "Destructor called" << std::endl;
}

int	Fixed::getRawBits(void) const	{
	std::cout << "getRawBits member function called" << std::endl;
	return (this->_val);
}

void	Fixed::setRawBits(int const raw)	{
	std::cout << "setRawBits member function called" << std::endl;
	this->_val = raw;
}

Fixed &	Fixed::operator=(Fixed const &fixed)	{
	std::cout << "Assignation operator called" << std::endl;
	this->_val = fixed.getRawBits();
	return *this;
}
