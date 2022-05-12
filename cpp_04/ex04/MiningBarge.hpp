#ifndef	MININGBARGE_HPP
# define MININGBARGE_HPP

# include <iostream>
# include "IAsteroid.hpp"
# include "IMiningLaser.hpp"

class	MiningBarge	{
	private:
		IMiningLaser	*_slots[4];

	public:
		MiningBarge();
		MiningBarge(MiningBarge const&);
		~MiningBarge();
		void equip(IMiningLaser*);
		void mine(IAsteroid*) const;

		MiningBarge & operator=(MiningBarge const&);
};

#endif
