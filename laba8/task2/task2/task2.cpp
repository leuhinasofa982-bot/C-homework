#include <iostream>
#include <vector>
#include <ctime>
#include <fstream>
#include "C:\Users\User\Desktop\matrixTasks\matrix\task1\matrixUtils.h"
using namespace std;

int main()
{
	setlocale(LC_ALL, "ru");
	const char* fileName = "numders.txt";

	//заполнение файла рандомными числами
	ofstream fileOfNum(fileName);
	srand(time(nullptr));
	int count = rand() / 10;
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
	

	cout << "Матрица А и С:" << endl;
	printMatrix(matrixA, n, m);
	cout << endl;
	printMatrix(matrixC, n, m);
	cout << endl;
	cout << "Матрица B и D:" << endl;
	printMatrixVector(matrixB, m, m);
	cout << endl;
	printMatrixVector(matrixD, m, m);
	cout << endl;


	//транспонирование матриц
	int** matrixAT = createMatrix(m, n);
	transporedMatrix(matrixA, matrixAT, m, n);
	vector<vector<int>> matrixDT(m, vector<int>(m));
	transporedMatrixVector(matrixD, matrixDT, m, m);


	cout << "Транспонированные матрицы A и D:" << endl;
	printMatrix(matrixAT, m, n);
	cout << endl;
	printMatrixVector(matrixDT, m, m);
	cout << endl;


	//умножение транспонированной матрицы А на С
	int** matrixATC = createMatrix(m, m);
	fillMatrix0(matrixATC, m, m);
	multiplyTwoMatrices(matrixATC, matrixAT, matrixC, m, n, n, m);


	cout << "Транспонированная матрица А, умноженная на С:" << endl;
	printMatrix(matrixATC, m, m);
	cout << endl;

	
	//умножение матрицы B на число
	multiplyMatNumVector(matrixB, m, m, 4);


	cout << "Матрица В, умноженная на 4:" << endl;
	printMatrixVector(matrixB, m, m);
	cout << endl;


	//умножение матрицы В на транспонированную D
	vector<vector<int>> matrix4BDT(m, vector<int>(m));
	multiplyTwoMatricesVector(matrix4BDT, matrixB, matrixDT, m, m, m, m);


	cout << "Транспонированная матрица D, умноженная на 4В:" << endl;
	printMatrixVector(matrix4BDT, m, m);
	cout << endl;
	

	//сложение двух больших матриц
	int** bigMatrix = createMatrix(m, m);
	matrixAddition(bigMatrix, matrixATC, matrix4BDT, m, m);


	cout << "Конечная матрица:" << endl;
	printMatrix(bigMatrix, m, m);

	return 0;
}
