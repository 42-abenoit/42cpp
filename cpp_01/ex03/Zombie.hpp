#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <string>
# include <iostream>
# include <cstdlib>

class	Zombie	{
	public:
		Zombie	();
		~Zombie (void);
		std::string	setZombieType(void);
		std::string	randomChump(void);
		void	announce(void);

	private:
		std::string	_name;
		std::string	_type;
};

#endif
