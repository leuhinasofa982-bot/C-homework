#include <iostream>
#include <fstream>
using namespace std;

/*функция записывает натуральные 
числа в файл*/
void inFile(int n) { 
	ofstream file("file.txt");
	for (int i = 1; i <= 2 * n; i++) {
		if (i % 2 == 0)
			file << i << endl;
		else
			continue;
	}
}

/*функция считывает необходимое 
количество чисел*/
void outFile(int m, int n) {
	ifstream fileIn("file.txt");
	int num;
	for (int i = 1; i <= m; i++) {
		if (m > n) {
			cout << "Столько чисел "
				<< "в файле нет" << endl;
			break;
		}
		else if (fileIn >> num) {
			cout << num << " ";
		}
	}
}

int main()
{
	setlocale(LC_ALL, "ru");
	int n, m;
	cout << "Введите количество чисел:" << endl;
	cin >> n;
	if (n <= 0) {
		cout << "Некорректный ввод" << endl;
	}
	else {
		inFile(n);
		cout << "Сколько чисел,"
			<< " нужно вывести: " << endl;
		cin >> m;
		if (m <= 0) {
			cout << "Некорректный ввод" << endl;
		} else
			outFile(m, n);
	}
}
