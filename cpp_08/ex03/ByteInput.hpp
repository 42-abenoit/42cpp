#ifndef BYTEINPUT_HPP
# define BYTEINPUT_HPP

#include "Turing.hpp"

#include "Instruction.hpp"

class	ByteInput	:	public Instruction	{
	public:
		ByteInput() {};
		//ByteInput(ByteInput &ref) {};
		virtual ~ByteInput() {};
		virtual	void	execute(Turing &data) { data.op(this); };
		virtual Instruction*	clone() const { return (new ByteInput); };

		//ByteInput&	operator=(ByteInput &ref) { return *this; };
};

#endif
