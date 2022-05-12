#include "iter.hpp"
#include <iostream>

template < typename T >
void	decrement(T &ref)
{
	ref -= 1;
}

template < typename T >
void	print(T const &ref)
{
	std::cout << ref << std::endl;
}

void	increment(int &nb)
{
	nb += 1;
}

void	capitalize(char &c)
{
	if (c >= 'a' && c <= 'z')
		c -= ('a' - 'A');
}

void	round(float	&nb)
{
	nb -= nb - static_cast<int>(nb);
}

int	main(void)
{
	int		tab[] = { 1, 2, 3, 4 };
	char	str[] = "hello world!";
	float	array[] = { 12.235, 87124.83752, 135.2415, 231.245, 1.543 };

	std::cout << "Before iter" << std::endl;

	std::cout << "str: ";
	std::cout << str << std::endl;

	std::cout << "tab: ";
	iter(tab, 5, print);

	std::cout << "array: ";
	iter(array, 5, print);

	iter<int>(tab, 4, increment);
	iter<char>(str, 12, capitalize);
	iter<float>(array, 5, round);

	std::cout << "After iter" << std::endl;
	std::cout << "str: ";
	std::cout << str << std::endl;
	std::cout << "tab: ";
	iter(tab, 5, print);
	std::cout << "array: ";
	iter(array, 5, print);

	std::cout << "Function template: " << std::endl;

	iter<int>(tab, 4, decrement);
	iter<char>(str, 12, decrement);
	iter<float>(array, 5, decrement);

	std::cout << "str: ";
	std::cout << str << std::endl;

	std::cout << "tab: ";
	iter(tab, 5, print);

	std::cout << "array: ";
	iter(array, 5, print);
	return (0);
}
