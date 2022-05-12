#ifndef	STRIPMINER_HPP
# define STRIPMINER_HPP

# include "IAsteroid.hpp"
# include "IMiningLaser.hpp"

class	StripMiner	:	public	IMiningLaser	{
	public:
		StripMiner();
		StripMiner(StripMiner const &);
		virtual	~StripMiner();
		virtual void mine(IAsteroid *);

		StripMiner & operator=(StripMiner const &);
};

#endif
