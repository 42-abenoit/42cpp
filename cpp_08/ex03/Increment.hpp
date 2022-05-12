#ifndef INCREMENT_HPP
# define INCREMENT_HPP

#include "Turing.hpp"

#include "Instruction.hpp"

class	Increment	:	public Instruction	{
	public:
		Increment() {};
		//Increment(Increment &ref) {};
		virtual ~Increment() {};
		virtual	void	execute(Turing &data) { data.op(this); };
		virtual Instruction*	clone() const { return (new Increment); };

		//Increment&	operator=(Increment &ref) { return *this; };
};

#endif
