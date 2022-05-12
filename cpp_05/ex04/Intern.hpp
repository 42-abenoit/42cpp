#ifndef INTERN_HPP
# define INTERN_HPP

class	Form;
# include <iostream>
# include "IException.hpp"

class	Intern	{
	private:
		Form	*_knownForm[4];

	public:
		Intern();
		Intern(Intern const&);
		virtual ~Intern();
		void learnForm(Form*);
		Form* makeForm(std::string const & type, std::string const target);

		Intern & operator=(Intern const&);

	class	FormNotKnownException : public IException	{
		public:
			virtual const char* what() const throw()
			{
				return ("This useless intern doesn't know this Form type.\n");
			}
			virtual void	raise() { throw (*this); }
	};
};

#endif
