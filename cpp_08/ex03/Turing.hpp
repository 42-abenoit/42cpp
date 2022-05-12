#ifndef TURING_HPP
# define TURING_HPP

class BackwardJump;
class ByteOutput;
class DataPtrInc;
class ForwardJump;
class ByteInput;
class DataPtrDec;
class Decrement;
class Increment;

#include "Instruction.hpp"
#include <vector>

class	Turing	: public std::vector<char>	{
	private:
		std::vector<char>::iterator	_head;
		std::vector<Instruction*>	_cmd;
		std::vector<Instruction*>::iterator	_it;

	public:
		Turing() { this->_head = this->begin(); };
		Turing(int N, char val) : std::vector<char>(N, val) { this->_head = this->begin(); };
		//Turing(Turing &ref) {};
		virtual ~Turing();

		void	feed(Instruction*);
		void	execute();

		void	op(BackwardJump*);
		void	op(ByteOutput*);
		void	op(DataPtrInc*);
		void	op(ForwardJump*);
		void	op(ByteInput*);
		void	op(DataPtrDec*);
		void	op(Decrement*);
		void	op(Increment*);

		//Turing&	operator=(Turing &ref) { return *this; };
};

#endif
