#include <fstream>
#include <string>
#include <iostream>

int	main(int ac, char **av)
{
	size_t			pos;
	size_t			offset;
	std::string		name;
	std::string		s1;
	std::string		s2;
	std::string		buff;
	std::ifstream	fileInput;
	std::ofstream	fileOutput;

	if (ac != 4)
		return (1);
	name = av[1];
	s1 = av[2];
	s2 = av[3];
	fileInput.open(name.c_str());
	buff = name + ".replace";
	fileOutput.open(buff.c_str());
	while (!fileInput.eof())
	{
		offset = 0;
		std::getline(fileInput, buff);
		while ((pos = buff.find(s1, offset)) != std::string::npos)
		{
			buff.replace(pos, s1.size(), s2);
			offset = pos + s2.size();
		}
		fileOutput << buff;
		if (!fileInput.eof())
			fileOutput << std::endl;
	}
	fileInput.close();
	fileOutput.close();
	return (0);
}
