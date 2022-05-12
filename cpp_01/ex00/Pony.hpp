#include <iostream>
#include <string>
#include <cstdlib>

class	pony
{
public:
	pony(void);
	~pony(void);

void	aging(void);
int		health_check(void);

private:
	bool		alive;
	int			age;
	std::string	name;
};
