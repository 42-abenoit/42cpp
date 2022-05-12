#include <iostream>
#include <fstream>
#include <vector>
#include "Instruction.hpp"
#include "BackwardJump.hpp"
#include "ByteOutput.hpp"
#include "DataPtrInc.hpp"
#include "ForwardJump.hpp"
#include "ByteInput.hpp"
#include "DataPtrDec.hpp"
#include "Decrement.hpp"
#include "Increment.hpp"

#ifdef	BRAINFUCK
# define CHARSET "><+-.,[]"
#else
# define CHARSET "azertyui"
#endif

int	getIndex(const char *haystack, char needle)
{
	int	i;

	i = 0;
	while (haystack[i])
	{			
		if (haystack[i] == needle)
			return (i);
		i++;
	}
	return (-1);
}

Instruction	*InstructionGen(int index)	{
	DataPtrInc	a;
	DataPtrDec	b;
	Increment	c;
	Decrement	d;
	ByteOutput	e;
	ByteInput	f;
	ForwardJump g;
	BackwardJump	h;
	const Instruction	*types[] = { &a, &b, &c, &d, &e, &f, &g, &h }; 

	return (types[index]->clone());
}

int	main(int ac, char **av)
{
	char						buff;
	int							c;
	std::ifstream				file;
	Turing						data(1, 0);

	if (ac != 2)
	{
		std::cout << "Wrong number of arguments." << std::endl;
		return (1);
	}
	file.open(av[1]);
	while (!file.eof())
	{
		file.read(&buff, 1);
		c = getIndex(CHARSET, buff);
		if (c != -1)
			data.feed(InstructionGen(c));
		else if (buff != '\n')
		{
			std::cout << "Invalid character in source file." << std::endl;
			file.close();
			return (1);
		}
	}
	data.execute();
	file.close();
	return (0);
}
