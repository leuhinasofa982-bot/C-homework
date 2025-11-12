#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
using namespace std;

/*функция записывает в файл
рандомное количество чисел*/
void randNum() {
	srand(time(NULL));
	int count = 1 + (rand() % 1000);
	ofstream file("fileThree.txt");
	for (int i = 1; i <= count; i++) {
		file << (rand() % 2001 - 1000) << endl;
	}
}

/*функция определяет наименьшее число
из файла*/
void min() {
	int num;
	int min = 1000000;
	ifstream fileIn("fileThree.txt");
	while (fileIn >> num) {
		if (num < min)
			min = num;
	}
	cout << "Минимальное число из файла: "
		<< min << endl;
}

int main()
{
	setlocale(LC_ALL, "ru");
	randNum();
	min();
}
