#ifndef DECREMENT_HPP
# define DECREMENT_HPP

#include "Turing.hpp"

#include "Instruction.hpp"

class	Decrement	:	public Instruction	{
	public:
		Decrement() {};
		//Decrement(Decrement &ref) {};
		virtual ~Decrement() {};
		virtual	void	execute(Turing &data) { data.op(this); };
		virtual Instruction*	clone() const { return (new Decrement); };

		//Decrement&	operator=(Decrement &ref) { return *this; };
};

#endif
