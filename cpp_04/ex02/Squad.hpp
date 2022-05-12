#ifndef	SQUAD_HPP
# define	SQUAD_HPP

#include <iostream>
#include "ISquad.hpp"

class	Squad	:	public ISquad	{
	private:
		ISpaceMarine	**_ptr;
		int				_size;

	public:
		Squad();
		Squad(Squad const&);
		virtual	~Squad();

		virtual	int	getCount() const;
		virtual	ISpaceMarine* getUnit(int) const;
		virtual	int	push(ISpaceMarine*);

		Squad & operator=(Squad const&);
};

#endif
