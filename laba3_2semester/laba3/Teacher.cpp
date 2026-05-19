#include "Teacher.h"
#include <string>
#include <vector>
using namespace std;

	Teacher::Teacher() : Human(), position(unknown) {}
	Teacher::Teacher(string name, string lastname, string surname, Position pos,
		vector<string> sub) : Human(name, lastname, surname),
		position(pos), subjects(sub) {
	}

	/*инициализация, когда мы пишем в теле ее мы переопределяем,
	то есть у нас сначала заполняются мусором, а потом нужными данными*/
	string Teacher::getPosition() {
		/*аналог цепочки if - else, удобен для enum,
		компилятор подскажет если что - то забудешь*/
		switch (position) {
		case assistant: return "ассистент";
		case seniorLecturer: return "старший преподаватель";
		case associateProfessor: return "доцент";
		case professor: return "профессор";
		default: return "неизвестно"; //аналог else
		}
	}

	void Teacher::addSubject(string newSubject) {
		subjects.push_back(newSubject);
	}
	string Teacher::getShortTeacherInfo() {
		string shortTeacherInfo = getSurnameAndInitials() + " "
			+ getPosition() + ": " + to_string(subjects.size());
		return shortTeacherInfo;
	}
	string Teacher::getFullTeacherInfo() {
		string subjetsInLine = " ";
		for (int i = 0; i < subjects.size(); i++) {
			subjetsInLine = subjetsInLine + subjects[i]
				+ ", ";
		}
		string fullTeacherInfo = getFullName() + " " + getPosition()
			+ ":" + subjetsInLine;
		return fullTeacherInfo;
	}
	int Teacher::getSubAmount() {
		return subjects.size();
	}
	string Teacher::getCertainSub(int index) {
		return subjects[index];
	}