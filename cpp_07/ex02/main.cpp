#include "Array.hpp"
#include <cstdlib>

#ifndef MAX_VAL
# define MAX_VAL 10
#endif

int	tests(void)
{
    Array<int> numbers(MAX_VAL);
    int* mirror = new int[MAX_VAL];
    srand(time(NULL));
    for (int i = 0; i < MAX_VAL; i++)
    {
        const int value = rand();
        numbers[i] = value;
        mirror[i] = value;
    }
    //SCOPE
    {
        Array<int> tmp = numbers;
        Array<int> test(tmp);
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        if (mirror[i] != numbers[i])
        {
            std::cerr << "didn't save the same value!!" << std::endl;
            return 1;
        }
		else
			std::cout << "Well done !" << std::endl;
    }
    try
    {
        numbers[-2] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    try
    {
        numbers[MAX_VAL] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        numbers[i] = rand();
    }
    delete [] mirror;//
    return 0;
}

int	main(void)
{
	Array<int> arr(5);
	Array<int> cpy(3);
	Array<std::string> str_arr(3);

	std::cout << std::endl;
	std::cout << "My tests" << std::endl;
	for (int i = 0; i < 5; i++)
	{
		arr[i] = i;
		std::cout << "arr: " << arr[i] << std::endl;
	}
	std::cout << "cpy = arr" << std::endl;
	cpy = arr;
	for (int i = 0; i < 5; i++)
	{
		arr[i] += i;
		std::cout << "arr: " << arr[i] << std::endl;
	}
	for (int i = 0; i < 5; i++)
	{
		std::cout << "cpy: " << cpy[i] << std::endl;
	}
	str_arr[0] = "Hello";
	str_arr[1] = "World";
	str_arr[2] = "!";
	std::cout << "str_arr: ";
	for (int i = 0; i < 3; i++)
	{
		std::cout << str_arr[i] << " ";
	}
	std::cout << std::endl;
	Array<std::string>	str_cpy(str_arr);
	std::cout << "str_cpy: ";
	for (int i = 0; i < 3; i++)
	{
		std::cout << str_arr[i] << " ";
	}
	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << "42 tests: " << std::endl;
	tests();
	return (0);
}
