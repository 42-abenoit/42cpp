#include "SuperTrap.hpp"

SuperTrap::SuperTrap(std::string name)	{
	std::string const	lines[] = { "\"Admirez mon aura mortelle.\"",
									"\"Je suis le feu, je suis la mort.\"",
									"\"Le robot des glaces débarque.\"",
									"\"Le champion fait son apparition.\"",
									"\"Je m'appelle Trap, Super Trap, zéro zéro Trap.\"" };

	this->_name = name;
	this->_hitPoints = 100;
	this->_maxHitPoints = 100;
	this->_energyPoints = 120;
	this->_maxEnergyPoints = 120;
	this->_level = 1;
	this->_meleeAttackDamage = 60;
	this->_rangedAttackDamage = 20 ;
	this->_armorDamageReduction = 5;
	this->_alive = 1;
	std::cout << "SUP3R-TP " << this->_name << ": ";
	std::cout << lines[std::rand() % 5] << std::endl;
}

SuperTrap::~SuperTrap(void)	{
	std::string const	lines[] = { "\"Je me pendrais a ma pierre tombale\"",
									"\"Brzzzt.. Krwzt ..Sprtrtrrzzz\"" };


	std::cout << "\e[31m";
	std::cout << "SUP3R-TP " << this->_name << " a cramé ses circuits." << std::endl;
	std::cout << "\e[0m";
	std::cout << "SUP3R-TP " << this->_name << ": ";
	std::cout << lines[std::rand() % 2] << std::endl;
}

void	SuperTrap::rangedAttack(std::string const & target)	{
/*
	std::string const	lines[] = { "\"Dans ta face.\"", "\"Tu vas crever !\"",
									"\"En plein dans le mille, héhé.\"",
									"\"Quel magnifique tir !\"",
									"\"Je m'attends à ce que tu meurs.\"",
									"\"Je suis une tempête de mort et de balles.\"",
									"\"Et pan !\"" };

	std::cout << "\e[32m";
	std::cout << "SUP3R-TP " << this->_name << " attaque " << target 
				<< " à distance, causant " << this->_rangedAttackDamage
				<< " points de dégâts !" << std::endl;
	std::cout << "\e[0m";
	std::cout << "SUP3R-TP " << this->_name << ": ";
	std::cout << lines[std::rand() % 7] << std::endl;
*/
	FragTrap::rangedAttack(target);
}

void	SuperTrap::meleeAttack(std::string const & target)	{
/*
	std::string const	lines[] = { "\"Prends ça, et ça et puis ça aussi.\"",
									"\"Prends ça !\"",
									"\"Ah Ya !\"",
									"\"Les dégâts rapprochés, ya que ça de vrai.\"" };

	std::cout << "\e[32m";
	std::cout << "SUP3R-TP " << this->_name << " attaque " << target 
				<< " au corp à corp, causant " << this->_meleeAttackDamage
				<< " points de dégâts !" << std::endl;
	std::cout << "\e[0m";
	std::cout << "SUP3R-TP " << this->_name << ": ";
	std::cout << lines[std::rand() % 4] << std::endl;
*/
	NinjaTrap::meleeAttack(target);
}

void	SuperTrap::takeDamage(unsigned int amount)	{
	std::string const	lines[] = { "\"Toutes ces balles en un seul tir.\"",
									"\"Vas-y, éblouis moi.\"",
									"\"Donne tout c'que t'as.\"",
									"\"HEY J'AVAIS PAS COMMANDÉ UN MILK-SHAKE AU PLOMB\"" };

	if ((int)(amount - this->_armorDamageReduction) >= 0)
	{
		if ((int)(this->_hitPoints - (amount - this->_armorDamageReduction)) <= 0)
		{
			std::cout << "\e[31m";
			std::cout << "SUP3R-TP " << this->_name << " reçoit " << amount - this->_armorDamageReduction
						<< " dégats." << std::endl;
			std::cout << "\e[0m";
			this->_hitPoints = 0;
			this->_alive = 0;
		}
		else
		{
			std::cout << "\e[31m";
			this->_hitPoints -= (amount - this->_armorDamageReduction);
			std::cout << "SUP3R-TP " << this->_name << " reçoit " << amount - this->_armorDamageReduction
						<< " dégats." << std::endl;
			std::cout << "\e[0m";
			std::cout << "SUP3R-TP " << this->_name << ": ";
			std::cout << lines[std::rand() % 4] << std::endl;
		}
	}
	else
	{
		std::cout << "\e[31m";
		std::cout << "SUP3R-TP " << this->_name << " reçoit " << 0
						<< " dégats." << std::endl;
		std::cout << "\e[0m";
		std::cout << "SUP3R-TP " << this->_name << ": ";
		std::cout << "Je suis invincible !" << std::endl;
	}
}

void	SuperTrap::beRepaired(unsigned int amount)	{
	std::string const	lines[] = { "\"Ça va picoter un peu.\"",
									"\"C'est l'heure de la mise au point.\"",
									"\"Hahaha, hahaha, je ressuscite.\"",
									"\"C'est reparti.\"",
									"\"La chance, c'est encore mieux que le talent.\"",
									"\"Défenses optimisées.\"" };

	if (this->_hitPoints == this->_maxHitPoints)
	{
		std::cout << "\e[36m";
		std::cout << "SUP3R-TP " << this->_name << " est deja en pleine forme !" << std::endl;
		std::cout << "\e[0m";
	}
	else if ((int)(this->_hitPoints + amount) > this->_maxHitPoints)
	{
		std::cout << "\e[36m";
		std::cout << "SUP3R-TP " << this->_name << " répare " << this->_maxHitPoints - this->_hitPoints
					<< " dégats." << std::endl;
		std::cout << "\e[0m";
		this->_hitPoints = this->_maxHitPoints;
	}
	else
	{
		std::cout << "\e[36m";
		std::cout << "SUP3R-TP " << this->_name << " répare " << amount
					<< " dégats." << std::endl;
		std::cout << "\e[0m";
		this->_hitPoints += amount;
	}
	std::cout << "SUP3R-TP " << this->_name << ": ";
	std::cout << lines[std::rand() % 6] << std::endl;
}

void	SuperTrap::vault_hunter_dot_exe(std::string const & target)	{
	int					i = rand() % 5;
	std::string const	lines[]	= { "\"Saisi à point.\"",
									"\"Des eeeeex-plosions.\"",
									"\"Brisons un peu la glace.\"",
									"\"Zap ! Psit ! Hop-là !\"",
									"\"Ça va tous les faire fondre.\"" };
	std::string const	types[]	= { " dégats de feu",
									" dégats explosifs",
									" dégats de glaces",
									" dégats de foudre",
									" dégats d'acide" };

	if (this->_energyPoints - 25 < 0)
	{
		std::cout << "\e[33m";
		std::cout << "SUP3R-TP " << this->_name << " n'a pas assez d'énergie." << std::endl;
		std::cout << "\e[0m";
		std::cout << "SUP3R-TP " << this->_name << ": ";
		std::cout << "\"Je suis a plat !\"" << std::endl;
	}
	else
	{
		this->_energyPoints -= 25;
		std::cout << "\e[33m";
		std::cout << "SUP3R-TP " << this->_name << " utilise son réacteur a improbabilite et inflige " 
					<< rand() % 50 << types[i] << " à " << target << std::endl;
		std::cout << "\e[0m";
		std::cout << "SUP3R-TP " << this->_name << ": ";
		std::cout << lines[i] << std::endl;
	}
}

void	SuperTrap::ninjaShoebox(ClapTrap & target)	{
	const std::string	names[] = {"Bob",
		"Bill", "Jim", "Kate", "Kim", "Doug",
		"James", "Tom", "Ellen", "Jack", "Cindy",
		"Pete", "Sam", "Meg"};

	if (this->_energyPoints - 25 < 0)
	{
		std::cout << "\e[33m";
		std::cout << "SUP3R-TP " << this->_name << " n'a pas assez d'énergie." << std::endl;
		std::cout << "\e[0m";
		std::cout << "SUP3R-TP " << this->_name << ": ";
		std::cout << "\"Je suis a plat !\"" << std::endl;
	}
	else
	{
		this->_energyPoints -= 25;
		std::cout << "\e[33m";
		std::cout << "CL4P-TP " << target.getName() << " fait un exposé sur la sedimentation de la faune Limougeaude."
					<< std::endl;
		std::cout << "SUP3R-TP " << this->_name << " en profite pour assassiner "
					<< names[std::rand() % 14] << std::endl;
		std::cout << "\e[0m";
		std::cout << "SUP3R-TP " << this->_name << ": You can't see me !" << std::endl;
	}
}

void	SuperTrap::ninjaShoebox(FragTrap & target)	{
	const std::string	names[] = {"Bob",
		"Bill", "Jim", "Kate", "Kim", "Doug",
		"James", "Tom", "Ellen", "Jack", "Cindy",
		"Pete", "Sam", "Meg"};

	if (this->_energyPoints - 25 < 0)
	{
		std::cout << "\e[33m";
		std::cout << "SUP3R-TP " << this->_name << " n'a pas assez d'énergie." << std::endl;
		std::cout << "\e[0m";
		std::cout << "SUP3R-TP " << this->_name << ": ";
		std::cout << "\"Je suis a plat !\"" << std::endl;
	}
	else
	{
		this->_energyPoints -= 25;
		std::cout << "\e[33m";
		std::cout << "FR4G-TP " << target.getName() << " danse la rumba."
					<< std::endl;
		std::cout << "SUP3R-TP " << this->_name << " en profite pour assassiner "
					<< names[std::rand() % 14] << std::endl;
		std::cout << "\e[0m";
		std::cout << "SUP3R-TP " << this->_name << ": You can't see me !" << std::endl;
	}

}

void	SuperTrap::ninjaShoebox(ScavTrap & target)	{
	const std::string	names[] = {"Bob",
		"Bill", "Jim", "Kate", "Kim", "Doug",
		"James", "Tom", "Ellen", "Jack", "Cindy",
		"Pete", "Sam", "Meg"};

	if (this->_energyPoints - 25 < 0)
	{
		std::cout << "\e[33m";
		std::cout << "SUP3R-TP " << this->_name << " n'a pas assez d'énergie." << std::endl;
		std::cout << "\e[0m";
		std::cout << "SUP3R-TP " << this->_name << ": ";
		std::cout << "\"Je suis a plat !\"" << std::endl;
	}
	else
	{
		this->_energyPoints -= 25;
		std::cout << "\e[33m";
		std::cout << "SC4V-TP " << target.getName() << " chante un air d'opéra."
					<< std::endl;
		std::cout << "SUP3R-TP " << this->_name << " en profite pour assassiner "
					<< names[std::rand() % 14] << std::endl;
		std::cout << "\e[0m";
		std::cout << "SUP3R-TP " << this->_name << ": You can't see me !" << std::endl;
	}
}

void	SuperTrap::ninjaShoebox(NinjaTrap & target)	{
	const std::string	names[] = {"Bob",
		"Bill", "Jim", "Kate", "Kim", "Doug",
		"James", "Tom", "Ellen", "Jack", "Cindy",
		"Pete", "Sam", "Meg"};

	if (this->_energyPoints - 25 < 0)
	{
		std::cout << "\e[33m";
		std::cout << "SUP3R-TP " << this->_name << " n'a pas assez d'énergie." << std::endl;
		std::cout << "\e[0m";
		std::cout << "SUP3R-TP " << this->_name << ": ";
		std::cout << "\"Je suis a plat !\"" << std::endl;
	}
	else
	{
		this->_energyPoints -= 25;
		std::cout << "\e[33m";
		std::cout << "N1NJ4-TP " << target.getName() << " lance un débat sur la vaccination."
					<< std::endl;
		std::cout << "SUP3R-TP " << this->_name << " en profite pour assassiner "
					<< names[std::rand() % 14] << std::endl;
		std::cout << "\e[0m";
		std::cout << "SUP3R-TP " << this->_name << ": You can't see me !" << std::endl;
	}
}

void	SuperTrap::ninjaShoebox(SuperTrap & target)	{
	const std::string	names[] = {"Bob",
		"Bill", "Jim", "Kate", "Kim", "Doug",
		"James", "Tom", "Ellen", "Jack", "Cindy",
		"Pete", "Sam", "Meg"};

	if (this->_energyPoints - 25 < 0)
	{
		std::cout << "\e[33m";
		std::cout << "SUP3R-TP " << this->_name << " n'a pas assez d'énergie." << std::endl;
		std::cout << "\e[0m";
		std::cout << "SUP3R-TP " << this->_name << ": ";
		std::cout << "\"Je suis a plat !\"" << std::endl;
	}
	else
	{
		this->_energyPoints -= 25;
		std::cout << "\e[33m";
		std::cout << "SUP3R-TP " << target.getName() << " fait un numéro de natation synchronisée."
					<< std::endl;
		std::cout << "SUP3R-TP " << this->_name << " en profite pour assassiner "
					<< names[std::rand() % 14] << std::endl;
		std::cout << "\e[0m";
		std::cout << "SUP3R-TP " << this->_name << ": You can't see me !" << std::endl;
	}
}

void	SuperTrap::passives(unsigned int amount)	{
	passiveFuncSuper	passive[] = { &SuperTrap::takeDamage, &SuperTrap::beRepaired };

	(this->*passive[rand() % 2])(amount);
}

void	SuperTrap::attacks(std::string const &name)	{
	attackFuncSuper	attack[] = { &SuperTrap::rangedAttack, &SuperTrap::meleeAttack,
								&SuperTrap::vault_hunter_dot_exe };

	(this->*attack[rand() % 3])(name);
}
