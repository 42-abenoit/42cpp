#ifndef FORWARDJUMP_HPP
# define FORWARDJUMP_HPP

#include "Turing.hpp"

#include "Instruction.hpp"

class	ForwardJump	:	public Instruction	{
	public:
		ForwardJump() {};
		//ForwardJump(ForwardJump &ref) {};
		virtual ~ForwardJump() {};
		virtual	void	execute(Turing &data) { data.op(this); };
		virtual Instruction*	clone() const { return (new ForwardJump); };

		//ForwardJump&	operator=(ForwardJump &ref) { return *this; };
};

#endif
