#ifndef AMATERIA_HPP
# define AMATERIA_HPP

# include <iostream>
class	ICharacter;

class AMateria	{
	protected:
		std::string		_type;
		unsigned int	_xp;

	public:
		AMateria();
		AMateria(std::string const & type);
		AMateria(AMateria const & ref);
		virtual ~AMateria();

		void				setType(std::string const &);
		std::string const & getType() const;//Returns the materia type
		void				setXP(unsigned int const&);
		void				incXP(unsigned int const&);
		unsigned int getXP() const;//Returns the Materia's XP

		virtual AMateria* clone() const = 0;
		virtual void use(ICharacter& target);

		AMateria & operator=(AMateria const&);
};

#endif
