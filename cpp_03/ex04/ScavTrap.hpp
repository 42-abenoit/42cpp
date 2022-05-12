#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

# include <iostream>
# include <cstdlib>
#include "ClapTrap.hpp"

class	ScavTrap	: public ClapTrap	{
	public:
		ScavTrap(std::string name);
		~ScavTrap(void);

		void	rangedAttack(std::string const & target);
		void	meleeAttack(std::string const & target);
		void	challengeNewcomer(std::string const & target);
		void	takeDamage(unsigned int amount);
		void	beRepaired(unsigned int amount);

		void	passives(unsigned int amount);
		void	attacks(std::string const &name);
};

	typedef void(ScavTrap::* attackFuncScav) (std::string const&);
	typedef void(ScavTrap::* passiveFuncScav) (unsigned int);

#endif
