#include "ScavTrap.hpp"

ScavTrap::ScavTrap(std::string name)	{
	std::string const	lines[] = { "\"Admirez mon aura mortelle.\"",
									"\"Je suis le feu, je suis la mort.\"",
									"\"Le robot des glaces débarque.\"",
									"\"Le champion fait son apparition.\"",
									"\"Je m'appelle Trap, Scav Trap, zéro zéro Trap.\"" };

	this->_name = name;
	this->_hitPoints = 100;
	this->_maxHitPoints = 100;
	this->_energyPoints = 50;
	this->_maxEnergyPoints = 50;
	this->_level = 1;
	this->_meleeAttackDamage = 20;
	this->_rangedAttackDamage = 15 ;
	this->_armorDamageReduction = 3;
	this->_alive = 1;
	std::cout << "SC4V-TP " << this->_name << ": ";
	std::cout << lines[std::rand() % 5] << std::endl;
}

ScavTrap::~ScavTrap(void)	{
	std::string const	lines[] = { "\"Je me pendrais a ma pierre tombale\"",
									"\"Brzzzt.. Krwzt ..Sprtrtrrzzz\"" };


	std::cout << "\e[31m";
	std::cout << "SC4V-TP " << this->_name << " a cramé ses circuits." << std::endl;
	std::cout << "\e[0m";
	std::cout << "SC4V-TP " << this->_name << ": ";
	std::cout << lines[std::rand() % 2] << std::endl;
}

void	ScavTrap::rangedAttack(std::string const & target)	{
	std::string const	lines[] = { "\"Dans ta face.\"", "\"Tu vas crever !\"",
									"\"En plein dans le mille, héhé.\"",
									"\"Quel magnifique tir !\"",
									"\"Je m'attends à ce que tu meurs.\"",
									"\"Je suis une tempête de mort et de balles.\"",
									"\"Et pan !\"" };

	std::cout << "\e[32m";
	std::cout << "SC4V-TP " << this->_name << " attaque " << target 
				<< " à distance, causant " << this->_rangedAttackDamage
				<< " points de dégâts !" << std::endl;
	std::cout << "\e[0m";
	std::cout << "SC4V-TP " << this->_name << ": ";
	std::cout << lines[std::rand() % 7] << std::endl;
}

void	ScavTrap::meleeAttack(std::string const & target)	{
	std::string const	lines[] = { "\"Prends ça, et ça et puis ça aussi.\"",
									"\"Prends ça !\"",
									"\"Ah Ya !\"",
									"\"Les dégâts rapprochés, ya que ça de vrai.\"" };

	std::cout << "\e[32m";
	std::cout << "SC4V-TP " << this->_name << " attaque " << target 
				<< " au corp à corp, causant " << this->_meleeAttackDamage
				<< " points de dégâts !" << std::endl;
	std::cout << "\e[0m";
	std::cout << "SC4V-TP " << this->_name << ": ";
	std::cout << lines[std::rand() % 4] << std::endl;
}

void	ScavTrap::takeDamage(unsigned int amount)	{
	std::string const	lines[] = { "\"Toutes ces balles en un seul tir.\"",
									"\"Vas-y, éblouis moi.\"",
									"\"Donne tout c'que t'as.\"",
									"\"HEY J'AVAIS PAS COMMANDÉ UN MILK-SHAKE AU PLOMB\"" };

	if ((int)(amount - this->_armorDamageReduction) >= 0)
	{
		if ((int)(this->_hitPoints - (amount - this->_armorDamageReduction)) <= 0)
		{
			std::cout << "\e[31m";
			std::cout << "SC4V-TP " << this->_name << " reçoit " << amount - this->_armorDamageReduction
						<< " dégats." << std::endl;
			std::cout << "\e[0m";
			this->_hitPoints = 0;
			this->_alive = 0;
		}
		else
		{
			std::cout << "\e[31m";
			this->_hitPoints -= (amount - this->_armorDamageReduction);
			std::cout << "SC4V-TP " << this->_name << " reçoit " << amount - this->_armorDamageReduction
						<< " dégats." << std::endl;
			std::cout << "\e[0m";
			std::cout << "SC4V-TP " << this->_name << ": ";
			std::cout << lines[std::rand() % 4] << std::endl;
		}
	}
	else
	{
		std::cout << "\e[31m";
		std::cout << "SC4V-TP " << this->_name << " reçoit " << 0
						<< " dégats." << std::endl;
		std::cout << "\e[0m";
		std::cout << "SC4V-TP " << this->_name << ": ";
		std::cout << "Je suis invincible !" << std::endl;
	}
}

void	ScavTrap::beRepaired(unsigned int amount)	{
	std::string const	lines[] = { "\"Ça va picoter un peu.\"",
									"\"C'est l'heure de la mise au point.\"",
									"\"Hahaha, hahaha, je ressuscite.\"",
									"\"C'est reparti.\"",
									"\"La chance, c'est encore mieux que le talent.\"",
									"\"Défenses optimisées.\"" };

	if (this->_hitPoints == this->_maxHitPoints)
	{
		std::cout << "\e[36m";
		std::cout << "SC4V-TP " << this->_name << " est deja en pleine forme !" << std::endl;
		std::cout << "\e[0m";
	}
	else if ((int)(this->_hitPoints + amount) > this->_maxHitPoints)
	{
		std::cout << "\e[36m";
		std::cout << "SC4V-TP " << this->_name << " répare " << this->_maxHitPoints - this->_hitPoints
					<< " dégats." << std::endl;
		std::cout << "\e[0m";
		this->_hitPoints = this->_maxHitPoints;
	}
	else
	{
		std::cout << "\e[36m";
		std::cout << "SC4V-TP " << this->_name << " répare " << amount
					<< " dégats." << std::endl;
		std::cout << "\e[0m";
		this->_hitPoints += amount;
	}
	std::cout << "SC4V-TP " << this->_name << ": ";
	std::cout << lines[std::rand() % 6] << std::endl;
}

void	ScavTrap::challengeNewcomer(std::string const & target)	{
	int					i = std::rand() % 5;
	std::string const	lines[]	= { "\"Vous n'êtes pas prêts !\"",
									"\"Bwaaaaaaaaaaaaaaah ! \"",
									"\"Vous, vous êtes soit incroyablement courageux, soit immensément con !\"",
									"\"J'avais besoin d'une nouvelle tête pour mon manège, la tienne sera parfaite...\"",
									"\"Je veux te voir de l'intérieur !\"" };

	if (this->_energyPoints - 25 < 0)
	{
		std::cout << "SC4V-TP " << this->_name << ": ";
		std::cout << "\"Je suis a plat !\"" << std::endl;
	}
	else
	{
		this->_energyPoints -= 25;
		std::cout << "\e[33m";
		std::cout << "SC4V-TP " << this->_name << " provoque " << target << std::endl;
		std::cout << "\e[0m";
		std::cout << "SC4V-TP " << this->_name << ": ";
		std::cout << lines[i] << std::endl;
	}
}

void	ScavTrap::passives(unsigned int amount)	{
	passiveFuncScav	passive[] = { &ScavTrap::takeDamage, &ScavTrap::beRepaired };

	(this->*passive[rand() % 2])(amount);
}

void	ScavTrap::attacks(std::string const &name)	{
	attackFuncScav	attack[] = { &ScavTrap::rangedAttack, &ScavTrap::meleeAttack,
								&ScavTrap::challengeNewcomer };

	(this->*attack[rand() % 3])(name);
}
