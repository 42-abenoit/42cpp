#ifndef ARRAY_HPP
# define ARRAY_HPP

#include <iostream>

template	< typename T >
class	Array	{
	private:
		T				*_data;
		unsigned int	_size;

	public:
		Array();
		Array(unsigned int n);
		Array(Array &ref);
		virtual	~Array();
		T	&getData(unsigned int index) const;
		unsigned int	size() const;

		Array & operator=(Array &ref);
		T & operator[](unsigned int index);
		T & operator[](unsigned int index) const;
	class	OutOfRangeException : public std::exception	{
		public:
			virtual const char* what() const throw()
			{
				return ("Index out of range");
			}
	};
};

# include "Array.cpp"
#endif
