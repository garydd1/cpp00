#include <iostream>

int main (int argc, char **argv){
	
	int i = 1;
	int k = 0;

	if(argc == 1){
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
		return 0;
	}
	std::string str;
	while(argv[i]){
		str = argv[i];
		k = 0;
		while (str[k])
		{
			str[k] = std::toupper(str[k]);
			k++;
		}				
		std::cout << str;
		if (argc > 2)
			std::cout << " ";
		i++;
	}
	std::cout << std::endl;
	return (0);
}