#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

# include <iostream>
# include <cstdlib>
#include "ClapTrap.hpp"

class	FragTrap	: public ClapTrap	{
	public:
		FragTrap(std::string name);
		~FragTrap(void);

		void	rangedAttack(std::string const & target);
		void	meleeAttack(std::string const & target);
		void	vault_hunter_dot_exe(std::string const & target);
		void	takeDamage(unsigned int amount);
		void	beRepaired(unsigned int amount);

		void	passives(unsigned int amount);
		void	attacks(std::string const &name);
};

	typedef void(FragTrap::* attackFuncFrag) (std::string const&);
	typedef void(FragTrap::* passiveFuncFrag) (unsigned int);

#endif
