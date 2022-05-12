#ifndef BYTEOUTPUT_HPP
# define BYTEOUTPUT_HPP

#include "Turing.hpp"

#include "Instruction.hpp"

class	ByteOutput	:	public Instruction	{
	public:
		ByteOutput() {};
		//ByteOutput(ByteOutput &ref) {};
		virtual ~ByteOutput() {};
		virtual	void	execute(Turing &data) { data.op(this); };
		virtual Instruction*	clone() const { return (new ByteOutput); };

		//ByteOutput&	operator=(ByteOutput &ref) { return *this; };
};

#endif
