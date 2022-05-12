#ifndef SUPERTRAP_HPP
# define SUPERTRAP_HPP

# include <iostream>
# include <cstdlib>
#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "NinjaTrap.hpp"

class	SuperTrap	: virtual public FragTrap, virtual public NinjaTrap	{
	public:
		SuperTrap(std::string name);
		~SuperTrap(void);

		void	rangedAttack(std::string const & target);
		void	meleeAttack(std::string const & target);
		void	takeDamage(unsigned int amount);
		void	beRepaired(unsigned int amount);
		void	vault_hunter_dot_exe(std::string const & target);
		void	ninjaShoebox(ClapTrap & target);
		void	ninjaShoebox(FragTrap & target);
		void	ninjaShoebox(ScavTrap & target);
		void	ninjaShoebox(NinjaTrap & target);
		void	ninjaShoebox(SuperTrap & target);

		void	passives(unsigned int amount);
		void	attacks(std::string const &name);
};

	typedef void(SuperTrap::* attackFuncSuper) (std::string const&);
	typedef void(SuperTrap::* passiveFuncSuper) (unsigned int);

#endif
