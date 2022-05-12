#include "Logger.hpp"
#include <string>
#include <sstream>
#include <fstream>
#include <iostream>
#include <ctime>

Logger::Logger(std::string fileName)	{
	this->_fileName = fileName;
}

Logger::~Logger(void)	{
}

void		Logger::log(std::string const &dest, std::string const &message)	{
	std::string	indexTable[] = {"File", "Console"};
	funcPtr		funcTable[] = {&Logger::logToFile, &Logger::logToConsole};

	for (int i = 0; i < 2; i++)
	{
		if (indexTable[i].compare(dest) == 0)
			(this->*funcTable[i])(Logger::makeLogEntry(message));
	}
}

void		Logger::logToConsole(std::string msg)	{
	std::cout << msg << std::endl;
}

void		Logger::logToFile(std::string msg)	{
	std::ofstream file(this->_fileName.c_str());

	file << msg << std::endl;
}

std::string	Logger::makeLogEntry(std::string msg)	{
	std::time_t now = time(0);
	std::stringstream	str;
	std::string			buff;

	str << ctime(&now);
	std::getline(str, buff);
	return (buff + "\b: " + msg);

}
