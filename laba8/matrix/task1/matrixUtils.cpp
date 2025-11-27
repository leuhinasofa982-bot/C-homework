#include <iostream>
#include <fstream>
#include <vector>
#include "matrixUtils.h"
using namespace std;

int** createMatrix(int numOfRows, int numOfColumns) {
	int** matrix = new int* [numOfRows]; //массив указателей
	for (int i = 0; i < numOfRows; i++) {
		matrix[i] = new int[numOfColumns];
	}
	return matrix;
}


void deleteMatrix(int** matrix, int numOfColumns) {
	for (int row = 0; row < numOfColumns; row++) {
		delete[] matrix[row];
	}
	delete[] matrix;
}


void printMatrix(int** matrix, int numOfRows, int numOfColumns) {
	for (int row = 0; row < numOfRows; row++) {
		for (int column = 0; column < numOfColumns; column++) {
			cout << matrix[row][column] << " ";
		}
		cout << endl;
	}
}


void printMatrixVector(vector<vector<int>>& matrix, int numOfRows,
	int numOfColumns) {
	for (int row = 0; row < numOfRows; row++) {
		for (int column = 0; column < numOfColumns; column++) {
			cout << matrix[row][column] << " ";
		}
		cout << endl;
	}
}

//заполнение матрицы рандомными числамми из диапазона
void randomizeMatrix(int** matrix, int numOfRows, 
	int numOfColumns, int a, int b) {
	srand(time(nullptr)); //начальная точка для рандомайзера, время в данный момент
	for (int row = 0; row < numOfRows; row++) {
		for (int column = 0; column < numOfColumns; column++) {
			matrix[row][column] = a + rand() % (b - a + 1);
		}
	}
}


//заполнение матрицы числами из файла
void matrixFromFile(int** matrix, int numOfRows, int numOfColumns,
	const char* fileName) {
	ifstream fileIn(fileName);
	for (int row = 0; row < numOfRows; row++) {
		for (int column = 0; column < numOfColumns; column++) {
			fileIn >> matrix[row][column];
		}
	}
}

//заполнение матрицы числами из файла(vector)
void matrixFromFileVector(vector<vector<int>>& matrix,
	int numOfRows, int numOfColumns, const char* fileName) {
	ifstream fileIn(fileName);
	for (int row = 0; row < numOfRows; row++) {
		for (int column = 0; column < numOfColumns; column++) {
			fileIn >> matrix[row][column];
		}
	}
}

void fillMatrix0(int** matrix, int numOfRows, int numOfColumns) {
	for (int row = 0; row < numOfRows; row++) {
		for (int column = 0; column < numOfColumns; column++) {
			matrix[row][column] = 0;
		}
	}
}

//поменять местами элементы в матрице
void swapElements(int** matrix, int row1, int column1, int row2, int column2) {
	int auxiliaryVar = matrix[row1][column1];
	matrix[row1][column1] = matrix[row2][column2];
	matrix[row2][column2] = auxiliaryVar;
}

//транспонированая матрица
void transporedMatrix(int** matrix, int** matrixT, int numOfColumns, 
	int numOfRows) {
	for (int row = 0; row < numOfColumns; row++) {
		for (int column = 0; column < numOfRows; column++) {
			matrixT[row][column] = matrix[column][row];
		}
	}
}


//транспонирование матрицы(вектор)
void transporedMatrixVector(vector<vector<int>>& matrix,
	vector<vector<int>>& matrixT, int numOfColumns,
	int numOfRows) {
	for (int row = 0; row < numOfColumns; row++) {
		for (int column = 0; column < numOfRows; column++) {
			matrixT[row][column] = matrix[column][row];
		}
	}
}


//умножение матрицы на число
void multiplyMatNumVector(vector<vector<int>>& matrix, int numOfRows,
	int numOfColumns, double number) {
	for (int row = 0; row < numOfRows; row++) {
		for (int column = 0; column < numOfColumns; column++) {
			matrix[row][column] = matrix[row][column] * number;
		}
	}
}


//перемножение двух матриц
void multiplyTwoMatrices(int** matrix12, int** matrix1, int** matrix2, int numOfRows1,
	int numOfColumns1, int numOfRows2, int numOfColumns2) {
	if (numOfColumns1 == numOfRows2) {
		int n = numOfColumns1;
		for (int rowM1 = 0; rowM1 < numOfRows1; rowM1++) {
			for (int columnM2 = 0; columnM2 < numOfColumns2; columnM2++) {
				for (int i = 0; i < n; i++) {
					matrix12[rowM1][columnM2] = matrix12[rowM1][columnM2]
						+ matrix1[rowM1][i]
						* matrix2[i][columnM2];
				}
			}
		}
	}
	else {
		cout << "Невозможно перемножить матрицы с такими размерами" << endl;
	}
}


//перемножение двух матриц(вектор)
void multiplyTwoMatricesVector(vector<vector<int>>& matrix12, 
	vector<vector<int>>& matrix1, vector<vector<int>>& matrix2, int numOfRows1,
	int numOfColumns1, int numOfRows2, int numOfColumns2) {
	if (numOfColumns1 == numOfRows2) {
		int n = numOfColumns1;
		for (int rowM1 = 0; rowM1 < numOfRows1; rowM1++) {
			for (int columnM2 = 0; columnM2 < numOfColumns2; columnM2++) {
				for (int i = 0; i < n; i++) {
					matrix12[rowM1][columnM2] = matrix12[rowM1][columnM2]
						+ matrix1[rowM1][i]
						* matrix2[i][columnM2];
				}
			}
		}
	}
	else {
		cout << "Невозможно перемножить матрицы с такими размерами" << endl;
	}
}


//сложение двух матриц(одна из них вектор)
void matrixAddition(int** matrix12, int** matrix1, vector<vector<int>>& matrix2,
	int numOfRows, int numOfColumns) {
	for (int row = 0; row < numOfRows; row++) {
		for (int column = 0; column < numOfColumns; column++) {
			matrix12[row][column] = matrix1[row][column] + matrix2[row][column];
		}
	}
}