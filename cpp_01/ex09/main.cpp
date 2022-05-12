#include "Logger.hpp"
#include <iostream>

int	main(void)	{
	Logger	log("log.output");

	log.log("Console", "plop");
	log.log("File", "plop");
}
