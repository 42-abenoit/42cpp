#include "Span.hpp"
#include <vector>
#include <iostream>
#include <algorithm>
#include <cstdlib>


void	print(int ref)
{
	std::cout << ref << " ";
}

int	main()
{
	Span	sp(5);

	std::srand(time(NULL));
	try
	{
		sp.addNumber(10);
		sp.addNumber(1);
		sp.addNumber(3);
		sp.addNumber(25);
		sp.addNumber(6);
	}
	catch (std::exception &e)
	{
		std::cout << e.what();
	}
	try
	{
		std::cout << "long: " << sp.longestSpan() << std::endl;
		std::cout << "short: " << sp.shortestSpan() << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what();
	}
	std::for_each(sp.getData().begin(), sp.getData().end(), print);
	std::cout << std::endl;
	Span	big(100000);

	big.fillRangeRand(big.getData().begin(), big.getData().end());
//	std::for_each(big.getData().begin(), big.getData().end(), print);
//	std::cout << std::endl;
	try
	{
		
		std::cout << "min = " << *(min_element(big.getData().begin(), big.getData().end())) << std::endl;
		std::cout << "max = " << *(max_element(big.getData().begin(), big.getData().end())) << std::endl;
		std::cout << "long = " << big.longestSpan() << std::endl;
		std::cout << "short = " << big.shortestSpan() << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what();
	}
	std::vector<int>	range(10000, 10);
	Span				test(10000);
	
	test.addNumber(range.begin(), range.end());
//	std::for_each(test.getData().begin(), test.getData().end(), print);
//	std::cout << std::endl;
	try
	{
		
		std::cout << "min = " << *(min_element(test.getData().begin(), test.getData().end())) << std::endl;
		std::cout << "max = " << *(max_element(test.getData().begin(), test.getData().end())) << std::endl;
		std::cout << "long = " << test.longestSpan() << std::endl;
		std::cout << "short = " << test.shortestSpan() << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what();
	}
	return (0);
}
