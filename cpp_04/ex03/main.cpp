#include "AMateria.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include "Fire.hpp"
#include "Shock.hpp"
#include "ICharacter.hpp"
#include "Character.hpp"
#include "IMateriaSource.hpp"
#include "MateriaSource.hpp"

int	main(void)
{
	Ice				*ice = new Ice;
	Cure			*cure = new Cure;
	Fire			*fire = new Fire;
	Shock			*shock = new Shock;
	MateriaSource	source;
	Character		Cloud("Cloud");

	source.learnMateria(ice);
	source.learnMateria(cure);
	source.learnMateria(fire);
	source.learnMateria(shock);
	std::cout << ice->getType() << " xp: " << ice->getXP() << std::endl;
	ice->use(Cloud);
	std::cout << ice->getType() << " xp: " << ice->getXP() << std::endl;
	ice->use(Cloud);
	std::cout << ice->getType() << " xp: " << ice->getXP() << std::endl;
	ice->use(Cloud);
	std::cout << ice->getType() << " xp: " << ice->getXP() << std::endl;
	cure->use(Cloud);
	std::cout << cure->getType() << " xp: " << cure->getXP() << std::endl;
	Cloud.equip(new Ice);
	Cloud.equip(new Cure);
	Character	Sephiroth(Cloud);
	Cloud.use(0, Sephiroth);
	Sephiroth.use(1, Cloud);
	Sephiroth.equip(source.createMateria("fire"));
	Sephiroth.use(2, Cloud);
	Sephiroth.use(3, Cloud);
	Sephiroth.equip(source.createMateria("shock"));
	Sephiroth.use(3, Cloud);
}
