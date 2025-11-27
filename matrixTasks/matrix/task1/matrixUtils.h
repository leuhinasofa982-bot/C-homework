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
void transporedMatrix(int** matrix, int** matrixT, int numOfColumns, int numOfRows);
void transporedMatrixVector(vector<vector<int>>& matrix, vector<vector<int>>& matrixT, int numOfColumns, int numOfRows);