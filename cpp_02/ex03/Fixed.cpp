#include "Fixed.hpp"
#include <cmath>

int Fixed::_frac = 8;

Fixed::Fixed(void)	{
	this->_val = 0;
}

Fixed::Fixed(const Fixed &fixed)	{
	*this = fixed;
}

Fixed::Fixed(const int val)	{
	this->setRawBits(0);
	this->_val = val << this->_frac;
}

Fixed::Fixed(const float val)	{
	this->_val = roundf(val * pow(2, this->_frac));
}

Fixed::~Fixed(void)	{
}

int	Fixed::getRawBits(void) const	{
	return (this->_val);
}

float	Fixed::toFloat(void) const	{
	return (this->_val / pow(2, this->_frac));
}


int		Fixed::toInt(void) const	{
	return (this->_val >> this->_frac);
}

void	Fixed::setRawBits(int const raw)	{
	this->_val = raw;
}

Fixed &	Fixed::operator=(Fixed const &fixed)	{
	this->_val = fixed.getRawBits();
	return *this;
}

bool Fixed::operator<(const Fixed &rhs)	const {
	return (this->_val > rhs._val ? 0 : 1);
}

bool Fixed::operator>(const Fixed &rhs)	const {
	return (rhs < *this);
}

bool Fixed::operator<=(const Fixed &rhs)	const {
	return (!(*this > rhs));
}

bool Fixed::operator>=(const Fixed &rhs)	const {
	return (!(*this < rhs));
}

bool Fixed::operator==(const Fixed &rhs)	const	{
	return (this->_val == rhs._val ? 1 : 0);
}

bool Fixed::operator!=(const Fixed &rhs)	const	{
	return (!(*this == rhs));
}

Fixed Fixed::operator+(const Fixed &rhs)	const	{
	Fixed	ret;

	ret._val = this->_val + rhs._val;
	return (ret);
}

Fixed Fixed::operator-(const Fixed &rhs)const	{
	Fixed	ret;

	ret._val = this->_val - rhs._val;
	return (ret);
}

Fixed Fixed::operator*(const Fixed &rhs)const	{
	Fixed	ret(this->toFloat() * rhs.toFloat());

	return (ret);
}

Fixed Fixed::operator/(const Fixed &rhs)const	{
	Fixed	ret(this->toFloat() / rhs.toFloat());

	return (ret);
}

Fixed &Fixed::operator++(void)	{
	this->_val += 0x00000001;
	return (*this);
}

Fixed Fixed::operator++(int)	{
	Fixed tmp = *this;

	++*this;
	return (tmp);
}
Fixed &Fixed::operator--(void)	{
	this->_val -= 0x00000001;
	return (*this);
}

Fixed Fixed::operator--(int)	{
	Fixed tmp = *this;

	--*this;
	return (tmp);
}

Fixed	&Fixed::min(Fixed &lhs, Fixed & rhs) {
	return (lhs > rhs ? rhs : lhs);
}

const Fixed	&Fixed::min(const Fixed &lhs, const Fixed & rhs) {
	return (lhs > rhs ? rhs : lhs);
}

Fixed	&Fixed::max(Fixed &lhs, Fixed & rhs)	{
	return (lhs > rhs ? lhs : rhs);
}

const Fixed	&Fixed::max(const Fixed &lhs, const Fixed & rhs)	{
	return (lhs > rhs ? lhs : rhs);
}

std::ostream & operator<<(std::ostream & o, Fixed const & fixed)	{
	o << fixed.toFloat();
	return (o);
}
