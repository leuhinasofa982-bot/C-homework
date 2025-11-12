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
	ofstream file("fileFour.bin", ios::binary);
	for (int i = 0; i < count; i++) {
		int num = rand() % 2001 - 1000;
		file.write(reinterpret_cast<char*>(&num),
			sizeof(num));
	}
}

/*функция считает сумму
четных чисел из файла*/
void outFile() {
	srand(time(NULL));
	ifstream fileIn("fileFour.bin", ios::binary);
	int sum = 0;
	int num;
	while (fileIn.read(reinterpret_cast<char*>(&num),
		sizeof(num))) {
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
