#ifndef INSTRUCTION_HPP
# define INSTRUCTION_HPP

class Turing;

class	Instruction	{
	public:
		Instruction() {};
		//Instruction(Instruction &ref) {};
		virtual ~Instruction() {};
		virtual	void	execute(Turing &data) = 0;
		virtual Instruction*	clone() const = 0;

		//Instruction&	operator=(Instruction &ref) { return *this; };
};

#endif
