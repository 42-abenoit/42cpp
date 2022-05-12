#include "Pony.hpp"

void	ponyOnTheStack(void)
{
	pony	tony;

	while (tony.health_check())
		tony.aging();
}

void	ponyOnTheHeap(void)
{
	pony	*tony;

	tony = new pony;
	while (tony->health_check())
		tony->aging();
	delete tony;
}

int	main(void)
{
	ponyOnTheStack();
	ponyOnTheHeap();
	return (0);
}
