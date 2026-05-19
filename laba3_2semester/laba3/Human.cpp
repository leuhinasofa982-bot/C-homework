#include "Human.h"
using namespace std;

	Human::Human() {
		name = "Неизвестно";
		lastname = "Неизвестно";
		surname = "Неизвестно";
	}
	Human::Human(string name, string lastname, string surname) {
		this->name = name;
		this->lastname = lastname;
		this->surname = surname;
	}

	string Human::getSurnameAndInitials() {
		string surnameAndInitials = lastname + " " + name[0] + "." + surname[0] + ".";
		return surnameAndInitials;
	}
	string Human::getFullName() {
		string fullName = lastname + " " + name + " " + surname;
		return fullName;
	}