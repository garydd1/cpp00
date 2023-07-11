#include "classes.hpp"

int Contacts::add_field(std::string data, int index)
{
	this->data[index] = data;
	return 0;
}

void Contacts::display(void)
{
	for (int i = 0; i < 5; i++)
	{
		std::cout << this->fields[i] <<":"<< this->data[i] <<std::endl;
	}
}

std::string Contacts::get_info(int index)
{
	return (this->data[index]);
}