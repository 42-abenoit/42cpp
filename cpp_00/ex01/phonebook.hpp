#include <string>
#include <iostream>
#include <iomanip>

class	contact	{

public	:
	contact (void);
	~contact (void);

	void	set_first_name(void);
	void	set_last_name(void);
	void	set_nickname(void);
	void	set_login(void);
	void	set_postal_address(void);
	void	set_email_address(void);
	void	set_phone_number(void);
	void	set_birthday_date(void);
	void	set_favorite_meal(void);
	void	set_underwear_color(void);
	void	set_darkest_secret(void);
	void	set_contact(void);

	std::string	get_first_name(void);
	std::string	get_last_name(void);
	std::string	get_nickname(void);

	void	print(void);

private	:
	std::string		_first_name;
	std::string		_last_name;
	std::string		_nickname;
	std::string		_login;
	std::string		_postal_address;
	std::string		_email_address;
	std::string		_phone_number;
	std::string		_birthday_date;
	std::string		_favorite_meal;
	std::string		_underwear_color;
	std::string		_darkest_secret;
};
