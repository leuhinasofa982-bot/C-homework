#include <iostream>
#include <string>
#include <fstream>
#include <ctime>
#include <vector>
using namespace std;

enum Type {
	brick,
	timber,
	panel,
	block
};
struct House {
	string street;
	int number; //дома
	float square;
	Type structureType;
};

void fillingFileRandom(ofstream& fileOfObj, const char* fileName, int numOfObjects, vector <string> streets, const char VALUE_SEPARATOR);
void fillingVector(const char* fileName, vector <House>& dataFromFile);
void fillingFileFromVector(ofstream& fileOfObj, const char* fileName, vector <House>& dataFromFile, int numOfObjects);

void bubbleSortNum(vector <House>& dataFromFile, int numOfObjects);
void bubbleSortStreet(vector <House>& dataFromFile, int numOfObjects);
