#include "Student.h"
#include <vector>
#include <string>
using namespace std;


	Student::Student() : Human() {}
	Student::Student(string name, string lastname, string surname, vector <int> scores)
		: Human(name, lastname, surname) {
		this->scores = scores;
	}

	void Student::addScore(int score) {
		scores.push_back(score);
	}
	double Student::getAverageScore() {
		double averageScore = 0;
		for (int i = 0; i < scores.size(); i++) {
			averageScore += scores[i];
		}
		if (averageScore == 0) {
			return -1;
		}
		return averageScore / scores.size();
	}
	string Student::getShortStudentInfo() {
		string shortStudentInfo = getSurnameAndInitials() + ": "
			+ to_string(getAverageScore());
		return shortStudentInfo;
	}
	string Student::getFullStudentInfo() {
		string scoresInLine = " ";
		for (int i = 0; i < scores.size(); i++) {
			scoresInLine = scoresInLine + to_string(scores[i]) + " ";
		}
		string fullStudentInfo = getFullName() + ":"
			+ scoresInLine + " - " + to_string(getAverageScore());
		return fullStudentInfo;
	}
	int Student::getScoresAmount() {
		return scores.size();
	}
