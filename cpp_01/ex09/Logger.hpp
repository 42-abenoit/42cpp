#ifndef LOGGER_HPP
# define LOGGER_HPP

#include <string>

class	Logger	{
	public:
		Logger(std::string fileName);
		~Logger(void);
		void	log(std::string const &dest, std::string const &message);

	private:
		std::string	_fileName;
		void		logToConsole(std::string msg);
		void		logToFile(std::string msg);
static		std::string	makeLogEntry(std::string msg);

};

	typedef void(Logger::* funcPtr) (std::string const);

#endif
