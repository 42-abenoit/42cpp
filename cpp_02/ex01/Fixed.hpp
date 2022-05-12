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

	private:
		int			_val;
		static int	_frac;
};

std::ostream & operator<<(std::ostream & o, Fixed const & fixed);

#endif
