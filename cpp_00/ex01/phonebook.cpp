#include "phonebook.hpp"

void	contact::set_first_name(void)	{
	std::cout << "\e[32m";
	std::cout << "Enter first_name: ";
	std::cout << "\e[0m";
	std::getline (std::cin, this->_first_name);
}

void	contact::set_last_name(void)	{
	std::cout << "\e[32m";
	std::cout << "Enter last_name: ";
	std::cout << "\e[0m";
	std::getline (std::cin, this->_last_name);
}

void	contact::set_nickname(void)	{
	std::cout << "\e[32m";
	std::cout << "Enter nickname: ";
	std::cout << "\e[0m";
	std::getline (std::cin, this->_nickname);
}

void	contact::set_login(void)	{
	std::cout << "\e[32m";
	std::cout << "Enter login: ";
	std::cout << "\e[0m";
	std::getline (std::cin, this->_login);
}

void	contact::set_postal_address(void)	{
	std::cout << "\e[32m";
	std::cout << "Enter postal_address: ";
	std::cout << "\e[0m";
	std::getline (std::cin, this->_postal_address);
}

void	contact::set_email_address(void)	{
	std::cout << "\e[32m";
	std::cout << "Enter email_address: ";
	std::cout << "\e[0m";
	std::getline (std::cin, this->_email_address);
}

void	contact::set_phone_number(void)	{
	std::cout << "\e[32m";
	std::cout << "Enter phone_number: ";
	std::cout << "\e[0m";
	std::getline (std::cin, this->_phone_number);
}

void	contact::set_birthday_date(void)	{
	std::cout << "\e[32m";
	std::cout << "Enter birthday_date: ";
	std::cout << "\e[0m";
	std::getline (std::cin, this->_birthday_date);
}

void	contact::set_favorite_meal(void)	{
	std::cout << "\e[32m";
	std::cout << "Enter favorite_meal: ";
	std::cout << "\e[0m";
	std::getline (std::cin, this->_favorite_meal);
}

void	contact::set_underwear_color(void)	{
	std::cout << "\e[32m";
	std::cout << "Enter underwear_color: ";
	std::cout << "\e[0m";
	std::getline (std::cin, this->_underwear_color);
}

void	contact::set_darkest_secret(void)	{
	std::cout << "\e[32m";
	std::cout << "Enter darkest_secret: ";
	std::cout << "\e[0m";
	std::getline (std::cin, this->_darkest_secret);
}

void	contact::set_contact (void)	{
	set_first_name();
	set_last_name();
	set_nickname();
	set_login();
	set_postal_address();
	set_email_address();
	set_phone_number();
	set_birthday_date();
	set_favorite_meal();
	set_underwear_color();
	set_darkest_secret();
}

std::string	contact::get_first_name(void)	{
	std::string	buffer;

	if (this->_first_name.size() > 10)
	{
		buffer = this->_first_name.substr(0,9);
		buffer += '.';
	}
	else
	{
		buffer = this->_first_name;
		while (buffer.size() < 10)
			buffer += ' ';
	}
	return (buffer);
}

std::string	contact::get_last_name(void)	{
	std::string	buffer;

	if (this->_last_name.size() > 10)
	{
		buffer = this->_last_name.substr(0,9);
		buffer += '.';
	}
	else
	{
		buffer = this->_last_name;
		while (buffer.size() < 10)
			buffer += ' ';
	}
	return (buffer);
}

std::string	contact::get_nickname(void)	{
	std::string	buffer;

	if (this->_nickname.size() > 10)
	{
		buffer = this->_nickname.substr(0,9);
		buffer += '.';
	}
	else
	{
		buffer = this->_nickname;
		while (buffer.size() < 10)
			buffer += ' ';
	}
	return (buffer);
}

void	contact::print(void)	{
	std::cout << "\e[31m";
	std::cout << "First_name: ";
	std::cout << "\e[0m";
	std::cout << this->_first_name << std::endl;
	std::cout << "\e[31m";
	std::cout << "Last_name: ";
	std::cout << "\e[0m";
	std::cout << this->_last_name << std::endl;
	std::cout << "\e[31m";
	std::cout << "Nickname: ";
	std::cout << "\e[0m";
	std::cout << this->_nickname << std::endl;
	std::cout << "\e[31m";
	std::cout << "Login: ";
	std::cout << "\e[0m";
	std::cout << this->_login << std::endl;
	std::cout << "\e[31m";
	std::cout << "Postal_address: ";
	std::cout << "\e[0m";
	std::cout << this->_postal_address << std::endl;
	std::cout << "\e[31m";
	std::cout << "Email_address: ";
	std::cout << "\e[0m";
	std::cout << this->_email_address << std::endl;
	std::cout << "\e[31m";
	std::cout << "Phone_number: ";
	std::cout << "\e[0m";
	std::cout << this->_phone_number << std::endl;
	std::cout << "\e[31m";
	std::cout << "Birthday_date: ";
	std::cout << "\e[0m";
	std::cout << this->_birthday_date << std::endl;
	std::cout << "\e[31m";
	std::cout << "Favorite_meal: ";
	std::cout << "\e[0m";
	std::cout << this->_favorite_meal << std::endl;
	std::cout << "\e[31m";
	std::cout << "Underwear_color: ";
	std::cout << "\e[0m";
	std::cout << this->_underwear_color << std::endl;
	std::cout << "\e[31m";
	std::cout << "Darkest_secret: ";
	std::cout << "\e[0m";
	std::cout << this->_darkest_secret << std::endl;
}

contact::contact (void)	{
	this->_first_name.empty();
	this->_last_name.empty();
	this->_nickname.empty();
	this->_login.empty();
	this->_postal_address.empty();
	this->_email_address.empty();
	this->_phone_number.empty();
	this->_birthday_date.empty();
	this->_favorite_meal.empty();
	this->_underwear_color.empty();
	this->_darkest_secret.empty();
}

contact::~contact (void)	{

}

int	main(void)
{
	int			i;
	int			tmp;
	std::string	buffer;
	contact		cool[8];

	i = 0;
	while (1)
	{
		std::cout << "\e[32m";
		std::getline (std::cin, buffer);
		std::cout << "\e[0m";
		if (buffer == "EXIT")
			exit (EXIT_SUCCESS);
		else if (buffer == "ADD")
		{
			if (i < 8)
			{
				cool[i].set_contact();
				i++;
			}
			else
			{
				std::cout << "\e[31m";
				std::cout << "No more room in phonebook" << std::endl;
				std::cout << "\e[0m";
			}
		}
		else if (buffer == "SEARCH")
		{
			std::cout << "\e[31m";
			std::cout << "|===========================================|" << std::endl
					<< "|"
					<< "  index   " << "|"
					<< "first name" << "|"
					<< "last name " << "|"
					<< " nickname " << "|" << std::endl
					<< "|===========================================|" << std::endl;
			for (int j = 0; j < i; j++)
			{
				std::cout << "|  "; 
				std::cout << j;
				std::cout << "       |"; 
				std::cout << cool[j].get_first_name();
				std::cout << "|"; 
				std::cout << cool[j].get_last_name();
				std::cout << "|"; 
				std::cout << cool[j].get_nickname();
				std::cout << "|"; 
				std::cout << std::endl;
			}
			if (i > 0)
				std::cout << "|===========================================|" << std::endl;
			std::cout << "\e[0m";
			std::cout << "\e[32m";
			std::cout << "Print entry number: #";
			std::getline (std::cin, buffer);
			std::cout << "\e[0m";
			tmp = std::atoi(buffer.c_str());
			if (tmp >= 0 && tmp < i)
				cool[tmp].print();
			else
			{
				std::cout << "\e[31m";
				std::cout << "Invalid Input" << std::endl;
				std::cout << "\e[0m";
			}
		}
	}
	return (0);
}
