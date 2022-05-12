#ifndef ENEMY_HPP
# define ENEMY_HPP

# include <iostream>

class	Enemy	{
	protected:
		std::string	_type;
		int			_hp;

	public:
		Enemy();
		Enemy(int hp, std::string const & type);
		Enemy(Enemy const &);
		virtual	~Enemy();
		Enemy & operator=(Enemy const &);

		std::string	getType() const;
		void		setType(std::string const&);
		int			getHp() const;
		void		setHp(int);

		virtual void	takeDamage(int);
};

#endif
