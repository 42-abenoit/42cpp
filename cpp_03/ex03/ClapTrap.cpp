#include "ClapTrap.hpp"
#include <sstream>

ClapTrap::ClapTrap(void)	{
	std::stringstream	stream;
	stream << std::uppercase << std::hex << rand();
	this->_name = "0x" + stream.str();
	this->_hitPoints = 0;
	this->_maxHitPoints = 0;
	this->_energyPoints = 0;
	this->_maxEnergyPoints = 0;
	this->_level = 0;
	this->_meleeAttackDamage = 0;
	this->_rangedAttackDamage = 0 ;
	this->_armorDamageReduction = 0;
	this->_alive = 0;
	std::cout << "\e[35m";
	std::cout << "Un CL4P-TP fait son apparition." << std::endl;
	std::cout << "\e[0m";
}

ClapTrap::~ClapTrap(void)	{
	std::cout << "\e[35m";
	std::cout << "Un CL4P-TP de moins, bon débarras !" << std::endl;
	std::cout << "\e[0m";
}

bool	ClapTrap::isAlive(void)	{
	return (this->_alive);
}

std::string const		ClapTrap::getName(void)	{
	return (this->_name);
}

void	ClapTrap::rangedAttack(std::string const & target)	{
	std::string const	lines[] = { "\"Dans ta face.\"", "\"Tu vas crever !\"",
									"\"En plein dans le mille, héhé.\"",
									"\"Quel magnifique tir !\"",
									"\"Je m'attends à ce que tu meurs.\"",
									"\"Je suis une tempête de mort et de balles.\"",
									"\"Et pan !\"" };

	std::cout << "\e[32m";
	std::cout << "CL4P-TP " << this->_name << " attaque " << target 
				<< " à distance, causant " << this->_rangedAttackDamage
				<< " points de dégâts !" << std::endl;
	std::cout << "\e[0m";
	std::cout << "CL4P-TP " << this->_name << ": ";
	std::cout << lines[std::rand() % 7] << std::endl;
}

void	ClapTrap::meleeAttack(std::string const & target)	{
	std::string const	lines[] = { "\"Prends ça, et ça et puis ça aussi.\"",
									"\"Prends ça !\"",
									"\"Ah Ya !\"",
									"\"Les dégâts rapprochés, ya que ça de vrai.\"" };

	std::cout << "\e[32m";
	std::cout << "CL4P-TP " << this->_name << " attaque " << target 
				<< " au corp à corp, causant " << this->_meleeAttackDamage
				<< " points de dégâts !" << std::endl;
	std::cout << "\e[0m";
	std::cout << "CL4P-TP " << this->_name << ": ";
	std::cout << lines[std::rand() % 4] << std::endl;
}

void	ClapTrap::takeDamage(unsigned int amount)	{
	std::string const	lines[] = { "\"Toutes ces balles en un seul tir.\"",
									"\"Vas-y, éblouis moi.\"",
									"\"Donne tout c'que t'as.\"",
									"\"HEY J'AVAIS PAS COMMANDÉ UN MILK-SHAKE AU PLOMB\"" };

	if ((int)(amount - this->_armorDamageReduction) >= 0)
	{
		if ((int)(this->_hitPoints - (amount - this->_armorDamageReduction)) <= 0)
		{
			std::cout << "\e[31m";
			std::cout << "CL4P-TP " << this->_name << " reçoit " << amount - this->_armorDamageReduction
						<< " dégats." << std::endl;
			std::cout << "\e[0m";
			this->_hitPoints = 0;
			this->_alive = 0;
		}
		else
		{
			std::cout << "\e[31m";
			this->_hitPoints -= (amount - this->_armorDamageReduction);
			std::cout << "CL4P-TP " << this->_name << " reçoit " << amount - this->_armorDamageReduction
						<< " dégats." << std::endl;
			std::cout << "\e[0m";
			std::cout << "CL4P-TP " << this->_name << ": ";
			std::cout << lines[std::rand() % 4] << std::endl;
		}
	}
	else
	{
		std::cout << "\e[31m";
		std::cout << "CL4P-TP " << this->_name << " reçoit " << 0
						<< " dégats." << std::endl;
		std::cout << "\e[0m";
		std::cout << "CL4P-TP " << this->_name << ": ";
		std::cout << "Je suis invincible !" << std::endl;
	}
}

void	ClapTrap::beRepaired(unsigned int amount)	{
	std::string const	lines[] = { "\"Ça va picoter un peu.\"",
									"\"C'est l'heure de la mise au point.\"",
									"\"Hahaha, hahaha, je ressuscite.\"",
									"\"C'est reparti.\"",
									"\"La chance, c'est encore mieux que le talent.\"",
									"\"Défenses optimisées.\"" };

	if (this->_hitPoints == this->_maxHitPoints)
	{
		std::cout << "\e[36m";
		std::cout << "CL4P-TP " << this->_name << " est deja en pleine forme !" << std::endl;
		std::cout << "\e[0m";
	}
	else if ((int)(this->_hitPoints + amount) > this->_maxHitPoints)
	{
		std::cout << "\e[36m";
		std::cout << "CL4P-TP " << this->_name << " répare " << this->_maxHitPoints - this->_hitPoints
					<< " dégats." << std::endl;
		std::cout << "\e[0m";
		this->_hitPoints = this->_maxHitPoints;
	}
	else
	{
		std::cout << "\e[36m";
		std::cout << "CL4P-TP " << this->_name << " répare " << amount
					<< " dégats." << std::endl;
		std::cout << "\e[0m";
		this->_hitPoints += amount;
	}
	std::cout << "CL4P-TP " << this->_name << ": ";
	std::cout << lines[std::rand() % 6] << std::endl;
}
