#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

# include "Form.hpp"

# include <iostream>
# include <fstream>
# include <cstdlib>

# define TREE_1 \
"......O.....\n" \
".O....\\*.O*.\n" \
".*\\_*.\\../O.\n" \
"...O\\.\\|/*..\n" \
".....| |....\n" \
"..../ /.....\n" \
"..__|~|_....\n" \
"..\\-----/...\n" \
"...\\___/....\n" \

# define TREE_2 \
"............\n" \
".......Y....\n" \
".....Y/.....\n" \
"...Y.|...Y..\n" \
"...\\|..Y/...\n" \
"....\\./.....\n" \
".....||.....\n" \
"...__||__...\n" \
"...\\____/...\n" \

# define TREE_3 \
"............\n" \
"............\n" \
"...%°.°O*...\n" \
"..*OO.*Y°O..\n" \
"..O*\\./°*...\n" \
"...._Y_.....\n" \
".../~~~\\....\n" \
"..(~~~~~)...\n" \
"...\\___/....\n" \

class	ShrubberyCreationForm	:	public	Form	{
	public:
		ShrubberyCreationForm(std::string target);
		ShrubberyCreationForm(ShrubberyCreationForm & ref);
		virtual	~ShrubberyCreationForm();
		virtual void	execute(Bureaucrat const & executor) const;
};

#endif
