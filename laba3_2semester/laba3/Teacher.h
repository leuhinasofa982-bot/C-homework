#pragma once
#include "Human.h"
#include <vector>
#include <string>

class Teacher : public Human {
public:
	enum Position {
		unknown,
		assistant,
		seniorLecturer,
		associateProfessor,
		professor
	};
private:
	Position position;
	std::vector<std::string> subjects;
public:
	Teacher();
	Teacher(std::string name, std::string lastname, std::string surname, Position pos,
		std::vector<std::string> sub);
	std::string getPosition();
	void addSubject(std::string newSubject);
	std::string getShortTeacherInfo();
	std::string getFullTeacherInfo();
	int getSubAmount();
	std::string getCertainSub(int index);
};