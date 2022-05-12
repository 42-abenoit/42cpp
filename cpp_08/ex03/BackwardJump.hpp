#ifndef BACKWARDJUMP_HPP
# define BACKWARDJUMP_HPP

#include "Turing.hpp"

#include "Instruction.hpp"

class	BackwardJump	:	public Instruction	{
	public:
		BackwardJump() {};
		//BackwardJump(BackwardJump &ref) {};
		virtual ~BackwardJump() {};
		virtual	void	execute(Turing &data) { data.op(this); };
		virtual Instruction*	clone() const { return (new BackwardJump); };

		//BackwardJump&	operator=(BackwardJump &ref) { return *this; };
};

#endif
