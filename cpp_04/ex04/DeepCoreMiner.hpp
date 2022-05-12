#ifndef	DEEPCOREMINER_HPP
# define DEEPCOREMINER_HPP

# include "IAsteroid.hpp"
# include "IMiningLaser.hpp"

class	DeepCoreMiner	:	public	IMiningLaser	{
	public:
		DeepCoreMiner();
		DeepCoreMiner(DeepCoreMiner const &);
		virtual	~DeepCoreMiner();
		virtual void mine(IAsteroid *);

		DeepCoreMiner & operator=(DeepCoreMiner const &);
};

#endif
