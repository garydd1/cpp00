#include "classes.hpp"



int main (void)
{
	PhoneBook my_phonebook;
	std::string input;

	while (42)
	{
		std::cout <<GREEN<< "\nPhonebook running, please insert what you want: " <<RESET;
		std::getline(std::cin, input); 
		if (input == "ADD")
			my_phonebook.add();
		if (input == "SEARCH")
			my_phonebook.display_g();
		if (input == "EXIT")
			break ; 
	}
	return (0);
}