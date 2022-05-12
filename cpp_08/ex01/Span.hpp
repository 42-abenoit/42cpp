#ifndef SPAN_HPP
# define SPAN_HPP

#include <vector>

class	Span	{
	private:
		std::vector<int>	_data;
		std::vector<int>::iterator	_it;

	public:
		Span();
		Span(unsigned int N);
		Span(Span &ref);
		virtual	~Span();

		std::vector<int>	&	getData();
		void				addNumber(int n);

template< class T >
void				addNumber( T begin, T end);
		void				fillRange(std::vector<int>::iterator,
										std::vector<int>::iterator, int i);
		void				fillRangeRand(std::vector<int>::iterator,
										std::vector<int>::iterator);

		Span & operator=(Span &ref);

		unsigned int	longestSpan();
		unsigned int	shortestSpan();

	class	OutOfRangeException : public std::exception	{
		public:
			virtual const char* what() const throw()
			{
				return ("Index is out of range.\n");
			}
	};
	class	NoSpanToFindException : public std::exception	{
		public:
			virtual const char* what() const throw()
			{
				return ("No span to find: array is empty or contains single element.\n");
			}
	};
};

#include "Span.cpp"
#endif
