#ifndef EASYFIND_HPP
# define EASYFIND_HPP

#include <iostream>
#include <algorithm>

template< template <typename, typename> class T >
typename T<int, std::allocator<int> >::iterator
	easyfind(T<int, std::allocator<int> > &container, int target)
{
	typename T<int, std::allocator<int> >::iterator	ret;

	ret = std::find(container.begin(), container.end(), target);
	return (ret);
}

#endif
