#include "classes.hpp"
#include <iomanip>


bool PhoneBook::is_space(std::string input)
{
	for (std::size_t i = 0 ; i < input.length(); i++)
	{
		if (input[i] != ' ' && input[i] != '\t' && input[i] != '\n')
			return (false);
	}
	return (true);
}

int PhoneBook::add(void)
{
	this->set_data();
	PhoneBook::count++;
	if (PhoneBook::count > 7)
	{
		PhoneBook::count = PhoneBook::oldest;
		PhoneBook::oldest++;
		this->flag = true;
		if (PhoneBook::oldest > 7)
			PhoneBook::oldest = 0;
	}

	return(0);
}


/**
 * This Function is a setter, that acces to the 
 * add_field function of each contact. In order to 
 * save the input data.
*/
int PhoneBook::set_data(void)
{
	int j = 0; 
	std::string data;
	
	while (j < 5)
	{
		std::cout << "Please enter contact " << PhoneBook::count + 1 << " " << this->phonebook[this->count].fields[j] << ": ";
		std::getline(std::cin, data);
		while (data.empty() || is_space(data) == true)
			std::getline(std::cin, data);
		this->phonebook[this->count].add_field(data, j);
		j++;
	}
	
	return (0);
}


/**
 * Getter Function for calling a memer function from
 * Contacts Class. 
*/
void PhoneBook::get_data(int index)
{
	this->phonebook[index - 1].display();
}

void PhoneBook::display_g(void)
{
	size_t width = 10;
	std::string text;
	int index;
	 
	if (this->count == 0 && this ->oldest == 0)
	{
		std::cout << "empty list" << std::endl;
		return ;
	}
	std::cout << std::endl;
	for (int i = 0; i < 8; i++)
	{
		if (flag == false && i == this->count && this -> flag == false)
			break;
		std::cout <<std::right<<std::setw(width)<<i+1<<" | " ;
		for (int j = 0; j < 3; j++)
		{
			text = this->phonebook[i].get_info(j);
			if (text.length() > width)
			{
				text[width - 1] = '.';
				text = text.substr(0, 10);
			}
			std::cout <<std::right<<std::setw(width)<<text<<" | " ;
		}
		std::cout << std::endl;
	}
	std::cout<<YELLOW<<"\nInsert index: "<<RESET;
	std::cin >>index;
	if (std::cin.fail()){
		std::cout << "\nInvalid, try again next time"<<std::endl;
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		return ;
	}
	if ((index >count && flag == false) || index > 8 || index < 1)
	{
		std::cin.clear();
		std::cout << "Out of bounds, try again next time."<<std::endl;
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		return ;
	}
	this->get_data(index);
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}