#include <iostream>
using namespace std;

//функция, которая вычисляет факториал числа
int factorial(int n) { //2 задание
	int fact = 1;
	for (int i = 1; i <= n; i++) {
		fact *= i;
	}
	return fact;
}

int main()
{
	setlocale(LC_ALL, "ru");
	cout << "Введите диапазон: " << endl;
	int m, n;
	cin >> m >> n;
	long int sum = 0;

	/*если число четное,
	то следующий цикл добавит
	к сумме факториал этого числа*/
	for (m; m <= n; m++) {
		if (m % 2 == 0)
			sum += factorial(m);
	}
	cout << "Сумма факториалов четных чисел: "
		<< sum << endl;
}
