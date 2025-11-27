#include <iostream>
#include <ctime>
#include "matrixUtils.h"
using namespace std;


int main()
{
	setlocale(LC_ALL, "ru");

	int a, b;
	cout << "Введите диапазон рандомных чисел:" << endl;
	cin >> a >> b;

	int n;
	cout << "Введите размер квадратной матрицы:" << endl;
	cin >> n;

	int** matrix = createMatrix(n, n);
	randomizeMatrix(matrix, n, n, a, b);
	printMatrix(matrix, n , n);

	//зеленая зона
	int max = a - 1;
	int maxRow, maxColumn;
	for (int column = 0; column < n / 2; column++) {
		for (int row = column; row < n - column; row++) {
			if (matrix[row][column] < 0
				&& matrix[row][column] > max) {
				max = matrix[row][column];
				maxRow = row;
				maxColumn = column;
			}
		}
	}
	if (max == a - 1) {
		cout << "В зеленом секторе нет "
			<< "отрицательных чисел" << endl;
		printMatrix(matrix, n, n);
		cout << "Задача не может быть выполнена" << endl;
		return 0;
	}
	else {
		cout << "Максимальный отрицательный элемент в зеленом секторе: "
			<< max << endl <<
			"Индексы элемента: "
			<< maxRow << " " << maxColumn << endl;
	}

	//красная зона
	int min = b + 1;
	int minRow, minColumn;
	for (int row = 0; row < n / 2; row++) {
		for (int column = row; column < n - row; column++) {
			if (matrix[row][column] < min
				&& matrix[row][column] > 0) {
				min = matrix[row][column];
				minRow = row;
				minColumn = column;
			}
		}
	}
	if (min == b + 1) {
		cout << "В красном секторе нет "
			<< "положительных чисел" << endl;
		printMatrix(matrix, n, n);
		cout << "Задача не может быть выполнена" << endl;
		return 0;
	}
	else {
		cout << "Минимальный положительный элемент в красном секторе: "
			<< min << endl 
			<< "Индексы элемента: "
			<< minRow << " " << minColumn << endl;
	}

	swapElements(matrix, maxRow, maxColumn, minRow, minColumn);

	cout << "Измененная матрица:" << endl;
	printMatrix(matrix, n, n);
	deleteMatrix(matrix, n);
	return 0;
}
