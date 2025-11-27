#include <vector>
using namespace std;


int** createMatrix(int qtyOfRows, int qtyOfColumns);
void deleteMatrix(int** matrix, int size);
void printMatrix(int** matrix, int qtyOfRows, int qtyOfColumns);
void printMatrixVector(vector<vector<int>>& matrix, int numOfRows, int numOfColumns);
void randomizeMatrix(int** matrix, int numOfRows, int numOfColumns, int a, int b);
void matrixFromFile(int** matrix, int numOfRows, int numOfColumns, const char* fileName);
void swapElements(int** matrix, int row1, int column1, int row2, int column2);
void matrixFromFileVector(vector<vector<int>>& matrix, int numOfRows, int numOfColumns, const char* fileName);
void fillMatrix0(int** matrix, int numOfRows, int numOfColumns);
void transporedMatrix(int** matrix, int** matrixT, int numOfColumns, int numOfRows);
void transporedMatrixVector(vector<vector<int>>& matrix, vector<vector<int>>& matrixT, int numOfColumns, int numOfRows);
void multiplyMatNumVector(vector<vector<int>>& matrix, int numOfRows, int numOfColumns, double number);
void multiplyTwoMatrices(int** matrix12, int** matrix1, int** matrix2, int numOfRows1, int numOfColumns1, int numOfRows2, int numOfColumns2);
void multiplyTwoMatricesVector(vector<vector<int>>& matrix12, vector<vector<int>>& matrix1, vector<vector<int>>& matrix2, int numOfRows1, int numOfColumns1, int numOfRows2, int numOfColumns2);
void matrixAddition(int** matrix12, int** matrix1, vector<vector<int>>& matrix2, int numOfRows, int numOfColumns);