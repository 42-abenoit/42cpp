#ifndef	IEXCEPTION_HPP
# define IEXCEPTION_HPP

# include <exception>

class	IException	:	std::exception	{
	public:
		virtual void	raise() = 0;
};

#endif
