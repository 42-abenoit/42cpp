#ifndef DATAPTRINC_HPP
# define DATAPTRINC_HPP

#include "Turing.hpp"

#include "Instruction.hpp"

class	DataPtrInc	:	public Instruction	{
	public:
		DataPtrInc() {};
		//DataPtrInc(DataPtrInc &ref) {};
		virtual ~DataPtrInc() {};
		virtual	void	execute(Turing &data) { data.op(this); };
		virtual Instruction*	clone() const { return (new DataPtrInc); };

		//DataPtrInc&	operator=(DataPtrInc &ref) { return *this; };
};

#endif
