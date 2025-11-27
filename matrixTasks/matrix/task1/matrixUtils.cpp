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

//поменять местами элементы в матрице
void swapElements(int** matrix, int row1, int column1, int row2, int column2) {
	int auxiliaryVar = matrix[row1][column1];
	matrix[row1][column1] = matrix[row2][column2];
	matrix[row2][column2] = auxiliaryVar;
}

//транспонированная матрица
void transporedMatrix(int** matrix, int** matrixT,int numOfColumns, 
	int numOfRows) {
	for (int row = 0; row < numOfColumns; row++) {
		for (int column = 0; column < numOfRows; column++) {
			matrixT[row][column] = matrix[column][row];
		}
	}
}


void transporedMatrixVector(vector<vector<int>>& matrix,
	vector<vector<int>>& matrixT, int numOfColumns,
	int numOfRows) {
	for (int row = 0; row < numOfColumns; row++) {
		for (int column = 0; column < numOfRows; column++) {
			matrixT[row][column] = matrix[column][row];
		}
	}
}