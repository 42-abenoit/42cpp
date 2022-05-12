#ifndef	COMET_HPP
# define COMET_HPP

class	IMiningLaser;
class	DeepCoreMiner;
class	StripMiner;
# include "IAsteroid.hpp"

class	Comet	:	public	IAsteroid	{
	private:
		std::string	_name;
	public:
		Comet();
		Comet(Comet const&);
		virtual	~Comet();
		virtual	std::string beMined(DeepCoreMiner *) const;
		virtual	std::string beMined(StripMiner *) const;
		virtual	std::string getName() const;

		Comet & operator=(Comet const&);
};

#endif
