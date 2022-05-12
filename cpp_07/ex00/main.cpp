#include "whatever.hpp"

int	basic_tests(void)
{
	int a = 2;
	int b = 3;

	std::cout << "Tests basiques" << std::endl;
	::swap( a, b );
	std::cout << "a = " << a << ", b = " << b << std::endl;
	std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
	std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;
	std::string c = "chaine1";
	std::string d = "chaine2";
	::swap(c, d);
	std::cout << "c = " << c << ", d = " << d << std::endl;
	std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
	std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl;
	std::cout << std::endl;
	return 0;
}

int	main(void)
{
	int a = 10;
	int b = 20;
	double	c = 0.24;
	double	d = 13.63;
	std::string	e = "Coucou";
	std::string	f = "Coucou";

	basic_tests();

	std::cout << "Tests supplémentaires" << std::endl;
	std::cout << "a: " << a << std::endl;
	std::cout << "b: " << b << std::endl;
	swap<int>(a, b);
	std::cout << "a: " << a << std::endl;
	std::cout << "b: " << b << std::endl;

	std::cout << "c: " << c << std::endl;
	std::cout << "d: " << d << std::endl;
	swap<double>(c, d);
	std::cout << "c: " << c << std::endl;
	std::cout << "d: " << d << std::endl;

	std::cout << "min: " << min<int>(a, b) << std::endl;
	std::cout << "min: " << min<double>(c, d) << std::endl;

	std::cout << "max: " << max<int>(a, b) << std::endl;
	std::cout << "max: " << max<double>(c, d) << std::endl;

	std::cout << "e: " << &e << std::endl;
	std::cout << "f: " << &f << std::endl;
	std::cout << min<std::string>(e, f) << std::endl;
	std::cout << "min: " << &max<std::string>(e, f) << std::endl;

	std::cout << "e: " << &e << std::endl;
	std::cout << "f: " << &f << std::endl;
	std::cout << max<std::string>(e, f) << std::endl;
	std::cout << "max: " << &max<std::string>(e, f) << std::endl;
}
