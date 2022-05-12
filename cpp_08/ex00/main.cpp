#include "easyfind.hpp"
#include <vector>
#include <list>
#include <deque>

#ifndef SIZE
# define SIZE 10
#endif

void	print(int ref)
{
	std::cout << ref << " ";
}

int main(void)
{
	int					target;
	std::string			buffer;
	std::vector<int>	vec(SIZE);
	std::vector<int>::iterator	vec_it;
	std::list<int>		lst;
	std::list<int>::iterator	lst_it;
	std::deque<int>				deque;
	std::deque<int>::iterator	deque_it;

	std::srand(time(NULL));
	for (int i = 0; i < SIZE; i++)
	{
		vec[i] = std::rand() % 100;
		lst.push_back(std::rand() % 100);
		deque.push_back(std::rand() % 100);
	}

	std::cout << "vec: ";
	std::for_each(vec.begin(), vec.end(), print);
	std::cout << std::endl;

	std::cout << "lst: ";
	std::for_each(lst.begin(), lst.end(), print);
	std::cout << std::endl;

	std::cout << "deque: ";
	std::for_each(deque.begin(), deque.end(), print);
	std::cout << std::endl;

	std::cout << "target in vec: ";
	std::getline(std::cin, buffer);
	target = atoi(buffer.c_str());
	vec_it = easyfind(vec, target);
	if (vec_it != vec.end())
		std::cout << "Found target: \"" << target << "\" at address: "
			<< &vec_it << std::endl;
	else
		std::cout << "Target not found" << std::endl;

	std::cout << "target in lst: ";
	std::getline(std::cin, buffer);
	target = atoi(buffer.c_str());
	lst_it = easyfind(lst, target);
	if (lst_it != lst.end())
		std::cout << "Found target: \"" << target << "\" at address: "
			<< &lst_it << std::endl;
	else
		std::cout << "Target not found" << std::endl;

	std::cout << "target in deque: ";
	std::getline(std::cin, buffer);
	target = atoi(buffer.c_str());
	deque_it = easyfind(deque, target);
	if (deque_it != deque.end())
		std::cout << "Found target: \"" << target << "\" at address: "
			<< &deque_it << std::endl;
	else
		std::cout << "Target not found" << std::endl;
	return (0);
}
