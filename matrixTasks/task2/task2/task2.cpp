#include <iostream>
#include <vector>
#include <ctime>
#include <fstream>
#include "C:\Users\User\Desktop\matrixTasks\matrix\task1\matrixUtils.h"
using namespace std;

int main()
{
	const char* fileName = "numders.txt";

	//заполнение файла рандомными числами
	ofstream fileOfNum(fileName);
	srand(time(nullptr));
	int count = rand() / 50;
	for (int i = 1; i <= count; i++) {
		fileOfNum << rand() % 2000 - 1000 << endl;
	}

	//рандомное определние количества строк и столбцов
	int n = 1 + rand() % 9;
	int m = 1 + rand() % 9;


	//создание матриц
	int** matrixA = createMatrix(n, m);
	int** matrixC = createMatrix(n, m);
	vector <vector<int>> matrixB(m, vector<int>(m));
	vector <vector<int>> matrixD(m, vector<int>(m));


	//считывание и запись чисел из файла в матрицы
	matrixFromFile(matrixA, n, m, fileName);
	matrixFromFile(matrixC, n, m, fileName);
	matrixFromFileVector(matrixB, m, m, fileName);
	matrixFromFileVector(matrixD, m, m, fileName);
	

	//транспонированние матриц
	int** matrixAT = createMatrix(m, n);
	transporedMatrix(matrixA, matrixAT, m, n);
	vector<vector<int>> matrixDT(m, vector<int>(m));
	transporedMatrixVector(matrixD, matrixDT, m, m);

	int** matrixATC = createMatrix(n, m);
	for (int row1 = 0; row1 < m; row1++) {
		for (int column1 = 0; column1 < n; column1++) {
			for (int row2 = 0; row2 < n; row2++) {
				for (int column2 = 0; column2 < m; column2++) {
					matrixATC[row1][column1] = matrixAT[row][column]
						* matrixC[row][column]
						+ matrixAT[row][column + 1] * matrixC[row + 1][column];
				}
			}
		}
	}
}
