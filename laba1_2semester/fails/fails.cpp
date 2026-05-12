#include <iostream>
#include <string>
#include <fstream>
#include <ctime>
#include <vector>
#include <algorithm>
#include "functionsForHouses.h"
using namespace std;


const char VALUE_SEPARATOR = ',';
const char* fileName = "objects.txt";

vector <string> streets = { "Ленина", "Мичурина",
		"Красная", "Ишимская", "Весенняя", "Кирова", "Соборная",
		"Терешковой", "Авроры", "Азотная", "Агеева", "Антипова",
		"Базовая", "Варшавская", "Гагарина" };


int main()
{
	setlocale(LC_ALL, "ru");

	ofstream fileOfObj(fileName);

	srand(time(nullptr));
	int numOfObjects = 5 + rand() % 11;
	//диапазон от 5 до 15

	fillingFileRandom(fileOfObj, fileName, numOfObjects, streets, VALUE_SEPARATOR);

	vector <House> dataFromFile;
	fillingVector(fileName, dataFromFile);
	
	bubbleSortNum(dataFromFile, numOfObjects);
	fillingFileFromVector(fileOfObj, fileName, dataFromFile, numOfObjects);

	bubbleSortStreet(dataFromFile, numOfObjects);
	fillingFileFromVector(fileOfObj, fileName, dataFromFile, numOfObjects);
	

}
