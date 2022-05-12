#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

# include <iostream>
# include <cstdlib>

class	ScavTrap	{
	private:
		int			_hitPoints;
		int			_maxHitPoints;
		int			_energyPoints;
		int			_maxEnergyPoints;
		int			_level;
		std::string	_name;
		int			_meleeAttackDamage;
		int			_rangedAttackDamage;
		int			_armorDamageReduction;
		bool		_alive;

	public:
		ScavTrap(std::string name);
		~ScavTrap(void);

		bool	isAlive(void);

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
