#ifndef DATAPTRDEC_HPP
# define DATAPTRDEC_HPP

#include "Turing.hpp"

#include "Instruction.hpp"

class	DataPtrDec	:	public Instruction	{
	public:
		DataPtrDec() {};
		//DataPtrDec(DataPtrDec &ref) {};
		virtual ~DataPtrDec() {};
		virtual	void	execute(Turing &data) { data.op(this); };
		virtual Instruction*	clone() const { return (new DataPtrDec); };

		//DataPtrDec&	operator=(DataPtrDec &ref) { return *this; };
};

#endif
