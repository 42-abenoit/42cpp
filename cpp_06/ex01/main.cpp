#include <iostream>
#include <stdint.h>
#include "Data.hpp"

uintptr_t serialize(Data* ptr)
{
	return (reinterpret_cast<uintptr_t>(ptr));
}

Data* deserialize(uintptr_t raw)
{
	return (reinterpret_cast<Data*>(raw));
}

int	main(void)
{
	uintptr_t	raw;
	Data		data;
	Data		*ptr;

	raw = serialize(&data);
	ptr = deserialize(raw);
	std::cout << raw << std::endl;
	std::cout << ptr << std::endl;
}
