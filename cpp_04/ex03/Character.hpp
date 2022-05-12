#ifndef CHARACTER_HPP
# define CHARACTER_HPP

# include "AMateria.hpp"
# include "ICharacter.hpp"

class	Character	: public ICharacter	{
	private:
		int			_hp;
		std::string	_name;
		AMateria	*_inventory[4];

	public:
		Character(std::string const &);
		Character(Character const &);
		virtual ~Character();
		virtual std::string const & getName() const;
		virtual void equip(AMateria* m);
		virtual void unequip(int idx);
		virtual void use(int idx, ICharacter& target);

		virtual void takeDamage(int amount);

		Character & operator=(Character const&);
};

#endif
