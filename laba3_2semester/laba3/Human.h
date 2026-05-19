#pragma once
#include <string>

class Human {
protected:
	std::string name;
	std::string lastname;
	std::string surname;
public:
	Human();
	Human(std::string name, std::string lastname, std::string surname);
	std::string getSurnameAndInitials();
	std::string getFullName();
};