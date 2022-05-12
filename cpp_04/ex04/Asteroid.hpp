#ifndef	ASTEROID_HPP
# define ASTEROID_HPP

class	IMiningLaser;
class	DeepCoreMiner;
class	StripMiner;
# include "IAsteroid.hpp"

class	Asteroid	:	public	IAsteroid	{
	private:
		std::string	_name;
	public:
		Asteroid();
		Asteroid(Asteroid const&);
		virtual	~Asteroid();
		virtual	std::string beMined(DeepCoreMiner *) const;
		virtual	std::string beMined(StripMiner *) const;
		virtual	std::string getName() const;

		Asteroid & operator=(Asteroid const&);
};

#endif
