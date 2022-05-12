#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP

# include "AMateria.hpp"
# include "IMateriaSource.hpp"

class	MateriaSource	:	public	IMateriaSource	{
	private:
		AMateria	*_inventory[4];

	public:
		MateriaSource();
		MateriaSource(MateriaSource const&);
		virtual ~MateriaSource();
		virtual void learnMateria(AMateria*);
		virtual AMateria* createMateria(std::string const & type);

		MateriaSource & operator=(MateriaSource const&);
};

#endif
