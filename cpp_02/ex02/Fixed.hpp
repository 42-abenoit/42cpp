#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>

class	Fixed	{
	public:
		Fixed(void);
		Fixed(const Fixed &);
		Fixed(const int);
		Fixed(const float);
		~Fixed(void);

		int	getRawBits(void) const;
		void	setRawBits(int const raw);

		float	toFloat(void) const;
		int		toInt(void) const;

		Fixed &	operator=(Fixed const &fixed);
		bool operator<(const Fixed &rhs)const;
		bool operator>(const Fixed &rhs)const;
		bool operator<=(const Fixed &rhs)const;
		bool operator>=(const Fixed &rhs)const;
		bool operator==(const Fixed &rhs)const;
		bool operator!=(const Fixed &rhs)const;

		Fixed operator+(const Fixed &rhs)const;
		Fixed operator-(const Fixed &rhs)const;
		Fixed operator*(const Fixed &rhs)const;
		Fixed operator/(const Fixed &rhs)const;

		Fixed &operator++(void);
		Fixed operator++(int);
		Fixed &operator--(void);
		Fixed operator--(int);

		static Fixed	&min(Fixed &lhs, Fixed &rhs);
		static const Fixed	&min(const Fixed &lhs, const Fixed &rhs);
		static Fixed	&max(Fixed &lhs, Fixed &rhs);
		static const Fixed	&max(const Fixed &lhs, const Fixed &rhs);

	private:
		int			_val;
		static int	_frac;
};

std::ostream & operator<<(std::ostream & o, Fixed const & fixed);

#endif
