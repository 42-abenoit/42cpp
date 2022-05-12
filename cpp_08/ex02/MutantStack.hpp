#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

# include <stack>

template <typename T>
class	MutantStack	:	public std::stack<T>	{
	public:
		MutantStack();
		MutantStack(MutantStack &ref);
		virtual	~MutantStack();
		MutantStack & operator=(MutantStack &ref);
		typedef typename std::deque<T>::iterator iterator;

		iterator	begin() { return (this->c.begin()); }
		iterator	end() { return (this->c.end()); }

};

# include "MutantStack.cpp"
#endif
