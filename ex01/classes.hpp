#ifndef CLASSES_H
#define CLASSES_H
#define GREEN   "\x1b[32m"
#define YELLOW "\x1b[33m"
#define RESET   "\x1b[0m"
#include <iostream>
#include <limits>


class Contacts {

public:

	int add_field(std::string data, int index);
	std::string fields[5];
	void display(void);
	std::string get_info(int index);
	Contacts() : fields(){
	fields[0] = std::string("First Name");
	fields[1] = std::string("Last Name");
	fields[2] = std::string("Nickname");
	fields[3] = std::string("Phone Number");
	fields[4] = std::string("Darkest Secret");
	}

private:

	std::string data[5];
};

class PhoneBook {

public: 
	int set_data(void);
	void get_data(int index);
	bool is_space(std::string input);
	void display_g(void);
	int add(void);
	PhoneBook() : count(0), oldest(0), flag(false){}

private:
	Contacts phonebook[8];
	int count;
	int oldest;
	bool flag;

};

#endif