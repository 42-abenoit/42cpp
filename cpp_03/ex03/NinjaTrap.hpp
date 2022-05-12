#ifndef NINJATRAP_HPP
# define NINJATRAP_HPP

# include <iostream>
# include <cstdlib>
# include "ClapTrap.hpp"
# include "FragTrap.hpp"
# include "ScavTrap.hpp"

class	NinjaTrap	: public ClapTrap	{
	public:
		NinjaTrap(std::string name);
		~NinjaTrap(void);

		void	rangedAttack(std::string const & target);
		void	meleeAttack(std::string const & target);
		void	takeDamage(unsigned int amount);
		void	beRepaired(unsigned int amount);
		void	ninjaShoebox(ClapTrap & target);
		void	ninjaShoebox(FragTrap & target);
		void	ninjaShoebox(ScavTrap & target);
		void	ninjaShoebox(NinjaTrap & target);

		void	passives(unsigned int amount);
		void	attacks(std::string const &name);
};

	typedef void(NinjaTrap::* attackFuncNinja) (std::string const&);
	typedef void(NinjaTrap::* passiveFuncNinja) (unsigned int);

#endif
