#include <iostream>
using namespace std;

//Функция считает сумму цифр числа
int sum(int n) {
	int sum = 0;
	while (n > 0) {
		sum += n % 10;
		n = n / 10;
	}
	return sum;
}

int main()
{
	setlocale(LC_ALL, "ru");
	cout << "Введите последовательность чисел," << 
		" чтобы завершить введите -1" << endl;
	int maxSum = 0;
	long long minSum = 1000000000000000000;
	int minNum = 0;
	int maxNum = 0;
	int num;
	/*Цикл определяет числа
	с наибольшей и наименьшей
	суммой цифр*/
	cin >> num;
	while (num != -1) {
		if (sum(num) > maxSum) {
			maxSum = sum(num);
			maxNum = num;
		}
		if (sum(num) < minSum) {
			minSum = sum(num);
			minNum = num;
		}
		cin >> num;
	}
	cout << "Число, у которого наибольшая сумма цифр: "
		<< maxNum << endl;
	cout << "Число, у которого наименьшая сумма цифр: "
		<< minNum << endl;
}
