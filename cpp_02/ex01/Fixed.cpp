#include "Fixed.hpp"
#include <cmath>

int Fixed::_frac = 8;

Fixed::Fixed(void)	{
	std::cout << "Default constructor called" << std::endl;
	this->_val = 0;
}

Fixed::Fixed(const Fixed &fixed)	{
	std::cout << "Copy constructor called" << std::endl;
	*this = fixed;
}

Fixed::Fixed(const int val)	{
	std::cout << "Int constructor called" << std::endl;
	this->setRawBits(0);
	this->_val = val << this->_frac;
}

Fixed::Fixed(const float val)	{
	std::cout << "Float constructor called" << std::endl;
	this->_val = roundf(val * pow(2, this->_frac));
}

Fixed::~Fixed(void)	{
	std::cout << "Destructor called" << std::endl;
}

int	Fixed::getRawBits(void) const	{
	std::cout << "getRawBits member function called" << std::endl;
	return (this->_val);
}

float	Fixed::toFloat(void) const	{
	return (this->_val / pow(2, this->_frac));
}


int		Fixed::toInt(void) const	{
	return (this->_val >> this->_frac);
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

std::ostream & operator<<(std::ostream & o, Fixed const & fixed)	{
	o << fixed.toFloat();
	return (o);
}
