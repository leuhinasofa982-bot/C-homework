#include <iostream>
using namespace std;

/*функция, которая определяет,
является ли число простым*/
int primary(int num) {
	if (num <= 1)
		return false;
	else if (num == 2)
		return true;
	else {
		int i = 2;
		int flag = 1;
		while (i <= sqrt(num)) {
			if (num % i == 0) {
				flag = 0;
				break;
			}
			i++;
		}
		if (flag == 0)
			return false;
		else
			return true;
	}
}

int main()
{
	setlocale(LC_ALL, "ru");
	cout << "Введите диапазон: " << endl;
	int a, b;
	cin >> a >> b;
	int c = a;
	int d = b;
	cout << "Простые числа в диапазоне от "
		<< a << " до " << b << ":" << endl;
	/*Цикл выводит все простые
	числа из диапазона*/
	for (a; a <= b; a++) { 
		if (primary(a)) 
			cout << a << endl;
	}

	cout << "Дружественные числа: " << endl;
	/*Цикл выводит все дружественные 
	числа из диапазона*/
	for (c; c <= d; c++) {
		if (primary(c) && primary(c + 2))
			cout << c << " " << c+2 << endl;
	}
		return 0;
}
