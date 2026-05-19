#pragma once
#include "Human.h"
#include <vector>
#include <string>

class Student : public Human {
private:
	std::vector<int> scores;
public:
	Student();
	Student(std::string name, std::string lastname, std::string surname, std::vector <int> scores);
	void addScore(int score);
	double getAverageScore();
	std::string getShortStudentInfo();
	std::string getFullStudentInfo();
	int getScoresAmount();
};
