#include "MutantStack.hpp"
#include <iostream>

int tests_42()
{
	MutantStack<int>    mstack;

	std::cout << "Tests 42:" << std::endl;
	mstack.push(5);
	mstack.push(17);
	std::cout << mstack.top() << std::endl;
	mstack.pop();
	std::cout << mstack.size() << std::endl;
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	mstack.push(0);
	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();
	++it;
	--it;
	while(it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}
	std::stack<int> s(mstack);
	return 0;
}

int	main(void)
{
	MutantStack<std::string>	sstack;
	MutantStack<int>			istack;

	tests_42();
	std::cout << "Others:" << std::endl;
	sstack.push("Salut");
	sstack.push("tu");
	sstack.push("va");
	sstack.push("bien");
	for (MutantStack<std::string>::iterator it = sstack.begin();
		   it < sstack.end(); it++)
		std::cout << *it << std::endl;
	std::cout << std::endl;
	for (MutantStack<std::string>::iterator it = sstack.end() - 1;
		   it >= sstack.begin(); --it)
		std::cout << *it << std::endl;
	std::cout << std::endl;
	istack.push(18);
	istack.push(23);
	istack.push(63);
	istack.push(98);
	for (MutantStack<int>::iterator it = istack.end() - 1;
		   it >= istack.begin(); --it)
		std::cout << *it << std::endl;
	return (0);
}
