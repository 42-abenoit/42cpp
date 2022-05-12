#ifndef FIXED_HPP
# define FIXED_HPP

class	Fixed	{
	public:
		Fixed(void);
		Fixed(const Fixed &);
		~Fixed(void);

		int	getRawBits(void) const;
		void	setRawBits(int const raw);

		Fixed &	operator=(Fixed const &fixed);

	private:
		int			_val;
		static int	_frac;
};

#endif
