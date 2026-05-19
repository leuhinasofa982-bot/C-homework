#include "input-outputFunctions.h"
#include <vector>
#include <iostream>
#include <fstream>
using namespace std;

void inputStud(const char* fileOfStud, vector<Student> students) {
	ofstream fileOfStudents(fileOfStud);
	for (int i = 0; i < students.size(); i++) {
		fileOfStudents << students[i].getFullStudentInfo() << endl;
	}
}
void inputTeach(const char* fileOfTeach, std::vector<Teacher> teachers) {
	ofstream fileOfTeachers(fileOfTeach);
	for (int i = 0; i < teachers.size(); i++) {
		fileOfTeachers << teachers[i].getFullTeacherInfo() << endl;
	}
}
void outputStud(const char* fileOfStud) {
	ifstream studFromFile(fileOfStud);
	string line;
	while (getline(studFromFile, line)) {
		cout << line << endl;
	}
}
void outputTeach(const char* fileOfTeach) {
	ifstream teachFromFile(fileOfTeach);
	string line;
	while (getline(teachFromFile, line)) {
		cout << line << endl;
	}
}