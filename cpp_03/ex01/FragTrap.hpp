#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

# include <iostream>
# include <cstdlib>

class	FragTrap	{
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
		FragTrap(std::string name);
		~FragTrap(void);

		bool	isAlive(void);

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
