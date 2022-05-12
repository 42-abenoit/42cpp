#ifndef DATA_HPP
# define DATA_HPP

# include <iostream>

struct	Data
{
	uint64_t	_raw;
};

std::ostream & operator<<(std::ostream & o, Data const *ref)
{
	o << reinterpret_cast<uintptr_t>(ref);
	return o;
}

#endif
