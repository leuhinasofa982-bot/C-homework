#include <iostream>
#include <string>
#include <vector>
#include <ctime>
#include <algorithm>
#include <fstream>
#include "Figure.h"
#include "Circle.h"
#include "Rectangle.h"
#include "Triangle.h"
#include "Parallelogramm.h"
#include "Animal.h"
#include "Fish.h"
#include "Bird.h"
#include "FlyingBird.h"
#include "Human.h"
#include "Student.h"
#include "Teacher.h"
#include "input-outputFunctions.h"
#include "Summator.h"
#include "SquareSummator.h"
#include "CubeSummator.h"
using namespace std;

const char* fileOfStud = "Students.txt";
const char* fileOfTeach = "Teachers.txt";
vector<string> names = { "Иван", "Олег", "Андрей", "Максим", "Николай", "Сергей",
		"Кирилл", "Виктор", "Владислав", "Михаил", "Роман", "Даниил", "Вячеслав",
		"Артем", "Давид" };
vector<string> surnames = { "Иванович", "Олегович", "Андреевич", "Максимович",
	"Николаевич", "Сергеевич", "Кириллович", "Викторович", "Владиславович",
	"Михайлович", "Романович", "Даниилович", "Вячеславович",
	"Артемович", "Анатольевич" };
vector<string> lastnames = { "Петров", "Сидоров", "Иванов", "Галенко", "Воевода",
	"Алексеев", "Тимофеев", "Матвеев", "Зиновьев", "Ершов", "Архипенко",
	"Тисин", "Тарасов", "Новиков", "Смирных" };
vector<string> subjects = { "Алгебра", "История", "Информатика", "ОС",
	"Языки программирования", "Математический анализ", "Физика", "Иностранный язык",
	"Обучение служению", "Обществознание" };

int main()
{
	setlocale(LC_ALL, "ru");

	//1 задание
	Figure* cylinderBase = nullptr;
	cout << "Введите высоту цилиндра: ";
	double height;
	cin >> height;
	cout << "Введите фигуру, которая будет находиться в основании цилиндра\n"
		<< "(1 - круг, 2 - квадрат, 3 - треугольник, 4 - параллелограмм)\n";
	int typeOfFigure;
	cin >> typeOfFigure;
	if (typeOfFigure == 1) {
		cout << "Введите радиус круга: ";
		double radius;
		cin >> radius;
		cylinderBase = new Circle(radius);
		cout << "Объем цилиндра: " << cylinderBase->cylinderVolume(height) << endl;
	}
	else if (typeOfFigure == 2) {
		cout << "Введите длину и ширину квадрата: ";
		double lenght, width;
		cin >> lenght >> width;
		cylinderBase = new Rectangle(lenght, width);
		cout << "Объем цилиндра: " << cylinderBase->cylinderVolume(height) << endl;
	}
	else if (typeOfFigure == 3) {
		cout << "Введите величину основания и высоту треугольника: ";
		double triangleBase, triangleHeight;
		cin >> triangleBase >> triangleHeight;
		cylinderBase = new Triangle(triangleBase, triangleHeight);
		cout << "Объем цилиндра: " << cylinderBase->cylinderVolume(height) << endl;
	}
	else if (typeOfFigure == 4) {
		cout << "Введите величину основания и высоту параллелограмма: ";
		double paralBase, paralHeight;
		cin >> paralBase >> paralHeight;
		cylinderBase = new Parallelogramm(paralBase, paralHeight);
		cout << "Объем цилиндра: " << cylinderBase->cylinderVolume(height) << endl;
	}
	else {
		cout << "Некорректный ввод!" << endl;
	}
	delete cylinderBase;

	//2 задание
	cout << "Ранее связывание(птица)\n";
	FlyingBird a;
	a.eat();
	a.fly();
	cout << endl;
	 
	cout << "Позднее связывание(птица и рыба)\n";
	Animal* pet = nullptr;
	pet = new Bird(); //вызываем конструктор
	pet->breathe();
	delete pet;
	pet = new Fish();
	pet->breathe();
	delete pet; //косвенный вызов деструктора


	//3 задание
	vector<Student> students;
	vector<Teacher> teachers;

	srand(time(nullptr));
	for (int i = 1; i <= 10; i++) {
		int randName = rand() % 15;
		int randSurname = rand() % 15;
		int randLastname = rand() % 15;

		vector<int> scores;
		int randAmountScores = rand() % 10 + 1;
		for (int j = 0; j <= randAmountScores; j++) {
			int randScore = rand() % 4 + 2;
			scores.push_back(randScore);
		}

		Student student(names[randName], lastnames[randLastname],
			surnames[randSurname], scores);
		students.push_back(student);
	}
	for (int i = 1; i <= 10; i++) {
		int randName = rand() % 15;
		int randSurname = rand() % 15;
		int randLastname = rand() % 15;
		int randPosition = rand() % 3 + 1;
		
		vector<string> subj;
		int randAmountSub = rand() % 4 + 1;
		for (int j = 0; j <= randAmountSub; j++) { 
			int randSub = rand() % 10;
			string potentialSub = subjects[randSub];
			if (find(subj.begin(), subj.end(), potentialSub) == subj.end()) {
				subj.push_back(subjects[randSub]);
			}
			else {
				j--;
			}
		}
		Teacher teacher(names[randName], lastnames[randLastname],
			surnames[randSurname], static_cast<Teacher::Position>(randPosition), subj);
		teachers.push_back(teacher);
	}



	cout << "Краткая информация о студентах, у которых средний бал больше 4:\n";
	for (int i = 0; i < students.size(); i++) {
		if (students[i].getAverageScore() > 4) {
			cout << students[i].getShortStudentInfo() << endl;
		}
	}

	cout << endl << "Краткая информация о студентах, у которых средний бал меньше 3:\n";
	for (int i = 0; i < students.size(); i++) {
		if (students[i].getAverageScore() < 3) {
			cout << students[i].getShortStudentInfo() << endl;
		}
	}

	cout << endl << "Полная информация о студенте, у которого больше всего оценок:\n";
	int maxAmount = 1;
	Student* studentWithMaxAmount = nullptr;
	for (int i = 0; i < students.size(); i++) {
		if (students[i].getScoresAmount() >= maxAmount) {
			maxAmount = students[i].getScoresAmount();
			studentWithMaxAmount = &students[i];
		}
	}
	if (studentWithMaxAmount == nullptr) {
		cout << "Нет такого студента" << endl;
	}
	else {
		cout << studentWithMaxAmount->getFullStudentInfo() << endl;
	}

	cout << endl << "Краткая информация обо всех доцентах:\n";
	for (int i = 0; i < teachers.size(); i++) {
		if (teachers[i].getPosition() == "доцент") {
			cout << teachers[i].getShortTeacherInfo() << endl;
		}
	}

	cout << endl << "Полная информация о профессоре, у которого больше всего предметов:\n";
	int maxSub = 1;
	Teacher* teacherWithMaxSub = nullptr;
	for (int i = 0; i < teachers.size(); i++) {
		if (teachers[i].getPosition() == "профессор" 
			&& teachers[i].getSubAmount() >= maxSub) {
			maxSub = teachers[i].getSubAmount();
			teacherWithMaxSub = &teachers[i];
		}
	}
	if (teacherWithMaxSub == nullptr) {
		cout << "Нет такого преподавателя" << endl;
	}
	else {
		cout << teacherWithMaxSub->getFullTeacherInfo() << endl;
	}

	cout << endl << "Полная информация о профессорах, которые ведут информатику:\n";
	for (int i = 0; i < teachers.size(); i++) {
		for (int j = 0; j < teachers[i].getSubAmount(); j++) {
			if (teachers[i].getCertainSub(j) == "Информатика") {
				cout << teachers[i].getFullTeacherInfo() << endl;
			}
		}
	}

	inputStud(fileOfStud, students);
	inputTeach(fileOfTeach, teachers);

	cout << endl << "Список студентов:\n";
	outputStud(fileOfStud);
	cout << endl << "Список преподавателей:\n";
	outputTeach(fileOfTeach);

	//4 задание
	cout << "Ранее связывание\n";
	Summator firstSequence;
	cout << "Сумма от 1 до 5: " << firstSequence.Sum(5) << endl;
	SquareSummator secondSequence;
	cout << "Сумма квадратов от 1 до 7: " << secondSequence.Sum(7) << endl;
	CubeSummator thirdSequence;
	cout << "Сумма кубов от 1 до 13: " << thirdSequence.Sum(13) << endl << endl;

	cout << "Позднее связывание\n";
	int power, lastNum;
	Summator* sequence = nullptr;
	cout << "В какую степень возводить элементы последовательности(1-3)? ";
	cin >> power;
	if (power > 3 || power < 1) {
		cout << "Такого варианта нет!" << endl;
		delete sequence;
		return 0;
	}
	cout << "До какого числа будем складывать(целое)? ";
	cin >> lastNum;
	if (power == 1) {
		sequence = new Summator;
		cout << "Сумма от 1 до " << lastNum << ": "
			<< sequence->Sum(lastNum) << endl;
	}
	else if (power == 2) {
		sequence = new SquareSummator;
		cout << "Сумма от 1 до " << lastNum << ": " 
			<< sequence->Sum(lastNum) << endl;
	}
	else {
		sequence = new CubeSummator;
		cout << "Сумма от 1 до " << lastNum << ": "
			<< sequence->Sum(lastNum) << endl;
	}
	delete sequence;


	return 0;
}
