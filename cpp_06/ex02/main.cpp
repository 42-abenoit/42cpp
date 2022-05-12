#include <cstdlib>
#include <iostream>
#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base * generate(void)
{
	int	base;

	base = rand() % 3;
	if (base == 0)
	{
		std::cout << "Generating instance of type A" << std::endl;
		return (new A);
	}
	else if (base == 1)
	{
		std::cout << "Generating instance of type B" << std::endl;
		return (new B);
	}
	else
	{
		std::cout << "Generating instance of type C" << std::endl;
		return (new C);
	}
}

void identify(Base* p)
{
	if (dynamic_cast<A*>(p))
		std::cout << "A" << std::endl;
	else if (dynamic_cast<B*>(p))
		std::cout << "B" << std::endl;
	else
		std::cout << "C" << std::endl;
}

void identify(Base& p)
{
	try
	{
		static_cast<void>(dynamic_cast<A&>(p));
		std::cout << "A" << std::endl;
	}
	catch (std::exception & e)
	{
		try
		{
			static_cast<void>(dynamic_cast<B&>(p));
			std::cout << "B" << std::endl;
		}
		catch (std::exception &e)
		{
		std::cout << "C" << std::endl;
		}
	}
}

int	main(void)
{
	Base	*a = new A;
	Base	*b = new B;
	Base	*c = new C;
	Base	*ptr;

	std::srand(time(NULL));
	identify(a);
	identify(*a);
	identify(b);
	identify(*b);
	identify(c);
	identify(*c);
	ptr = generate();
	identify(ptr);
	identify(*ptr);
}
