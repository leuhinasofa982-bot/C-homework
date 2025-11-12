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
	ofstream file("fileTwo.txt");
	for (int i = 1; i <= count; i++) {
		file << (rand() % 2001 - 1000) << endl;
	}
}

/*функция считает сумму 
четных чисел из файла*/
void outFile() {
	ifstream fileIn("fileTwo.txt");
	int sum = 0;
	int num;
	while (fileIn >> num) {
		if (num % 2 == 0) {
			sum += num;
		}
	}
	cout << "Сумма четных чисел: "
		<< sum << endl;
}

int main()
{
	setlocale(LC_ALL, "ru");
	randNum();
	outFile();
}
