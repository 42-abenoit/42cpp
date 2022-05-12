#ifndef VICTIM_HPP
# define VICTIM_HPP

# include <iostream>

class	Victim	{
	public:
		Victim() {};
		Victim(std::string const &name);
		Victim(Victim const &vic);
		virtual	~Victim(void);

		std::string	getName(void) const;
		void		setName(std::string const &name);
		std::string	introduce(void) const;

		virtual void		getPolymorphed(void) const;

		Victim & operator=(Victim const &vic);

	protected:
		std::string	_name;
};

std::ostream & operator<<(std::ostream & o, Victim const & vic);

#endif
