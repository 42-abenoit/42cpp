#include "Turing.hpp"
#include "BackwardJump.hpp"
#include "ForwardJump.hpp"
#include <iostream>
#include <cstdio>

Turing::~Turing() {
	this->_it = this->_cmd.begin();
	while (this->_it < this->_cmd.end())
	{
		delete *(this->_it);
		this->_it++;
	}
}

void	Turing::feed(Instruction *ptr)	{
	this->_cmd.push_back(ptr);
}

void	Turing::execute()	{
	this->_it = this->_cmd.begin();
	while (this->_it < this->_cmd.end())
	{
		(*(this->_it))->execute(*this);
		this->_it++;
	}
}

void	Turing::op(BackwardJump*) {
	int	end;
	int	depth;

	end = 0;
	depth = 0;
	if (*(this->_head) != 0)
	{
		while (this->_it != this->_cmd.begin() && end == 0)
		{
			this->_it--;
			if (dynamic_cast<ForwardJump*>(*(this->_it)))
			{
				if (depth == 0)
				{
					end = 1;
					break ;
				}
				else
					depth -= 1;
			}
			else if (dynamic_cast<BackwardJump*>(*(this->_it)))
				depth += 1;
		}
	}
	if (this->_it == this->_cmd.begin())
		return ;
}

#ifdef	NUM_OUT
void	Turing::op(ByteOutput*) {
	std::cout << static_cast<char>(*(this->_head) + 48);
}
# else
void	Turing::op(ByteOutput*) {
	std::cout << *(this->_head);
}
#endif

void	Turing::op(DataPtrInc*) {
	int	tmp;

	tmp = this->_head - this->begin();
	if (this->_head + 1 >= this->end())
		this->push_back(0);
	this->_head = this->begin() + tmp + 1;
}

void	Turing::op(ForwardJump*) {
	int	end;
	int	depth;

	end = 0;
	depth = 0;
	if (*(this->_head) == 0)
	{
		while (this->_it != this->_cmd.end() && end == 0)
		{
			this->_it++;
			if (dynamic_cast<ForwardJump*>(*(this->_it)))
				depth += 1;
			else if (dynamic_cast<BackwardJump*>(*(this->_it)))
			{
				if (depth == 0)
				{
					end = 1;
					break ;
				}
				else
					depth -= 1;
			}
		}
	}
	if (this->_it == this->_cmd.end())
		return;
}

#ifdef	NUM_OUT
void	Turing::op(ByteInput*) {
	char	c;

	c = std::getchar();
	if (c >= '0' && c <= '9')
		*(this->_head) = c - 48;
	else
		*(this->_head) = 0;
}
# else
void	Turing::op(ByteInput*) {
	*(this->_head) = std::getchar();
}
#endif

void	Turing::op(DataPtrDec*) {
	if (this->_head - 1 >= this->begin())
		this->_head--;
}

void	Turing::op(Decrement*) {
	*(this->_head) -= 1;
}

void	Turing::op(Increment*) {
	*(this->_head) += 1;
}
