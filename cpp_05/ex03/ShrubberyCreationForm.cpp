#include "ShrubberyCreationForm.hpp"
#include "Bureaucrat.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(std::string target)	:
	Form("ShrubberyCreationForm", 145, 127, target)
{
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm & ref)	:
	Form(ref.getType(), ref.getSignReq(), ref.getExecReq(), ref.getTarget())
{
	this->setSign(ref.isSigned());
}

ShrubberyCreationForm::~ShrubberyCreationForm()	{

}

void	ShrubberyCreationForm::execute(Bureaucrat const & executor) const	{
	std::ofstream	shrub;
	const char 		*tree[] = {TREE_1, TREE_2, TREE_3};

	Form::execute(executor);
	shrub.open((this->getTarget() + "_shrubbery").c_str());
	shrub << tree[std::rand() % 3];
}

Form	*ShrubberyCreationForm::clone(std::string target)	{
	return (new ShrubberyCreationForm(target));
}
