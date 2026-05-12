#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <ctime>
#include <vector>
#include "functionsForHouses.h"
using namespace std;


const char VALUE_SEPARATOR = ',';


//функция заполняет файл рандомными данными
void fillingFileRandom(ofstream& fileOfObj, const char* fileName, 
	int numOfObjects, vector <string> streets, const char VALUE_SEPARATOR) {
	for (int i = 1; i <= numOfObjects; i++) {
		House example;

		//рандоманое название дома
		int numOfStreet = rand() % 15;
		string streetOfHouse = streets[numOfStreet];
		example.street = streetOfHouse;

		//рандомный номер дома
		int numOfHouse = 1 + rand() % 1000;
		example.number = numOfHouse;

		//рандомная площадь дома
		float squareOfHouse = 1
			+ static_cast<float>(rand() % 20000)
			/ 100;
		/*случайное число от 0 до 19999,
		делим на 100
		(сдвигаем запятую на 00),
		получаем от 0 до 199.99,
		сдвигаем диапазон на 1:
		от 1 до 200.99*/
		example.square = squareOfHouse;

		//рандомный тип дома
		int typeOfHouse = rand() % 4;
		example.structureType = static_cast<Type>(typeOfHouse);

		fileOfObj << example.street << VALUE_SEPARATOR
			<< example.number << VALUE_SEPARATOR
			<< example.square << VALUE_SEPARATOR
			<< example.structureType << endl;
	}
}
//функция читает из файла и записывает в вектор
void fillingVector(const char* fileName, vector <House>& dataFromFile) {
	ifstream file(fileName);
	string line;
	/*читаем строку из файла
	если она есть мы делим по разделителям
	каждую часть записываем в соответсвующее поле структуры
	структуру добавляем в массив*/
	while(getline(file, line)) {
		House newHouse;
		stringstream streamLine(line);

		getline(streamLine, newHouse.street, VALUE_SEPARATOR);

		string numNewHouse;
		getline(streamLine, numNewHouse, VALUE_SEPARATOR);
		newHouse.number = stoi(numNewHouse);
		
		string squareNewHouse;
		getline(streamLine, squareNewHouse, VALUE_SEPARATOR);
		newHouse.square = stof(squareNewHouse);

		string typeNewHouse;
		getline(streamLine, typeNewHouse);
		newHouse.structureType = static_cast<Type>(stoi(typeNewHouse));//из string в int

		dataFromFile.push_back(newHouse);
	}
	file.close();
}
//функция читает из вектора и записывает в файл
void fillingFileFromVector(ofstream& fileOfObj, const char* fileName,
	vector <House>& dataFromFile, int numOfObjects) {
	fileOfObj << endl;
	for (int i = 0; i < numOfObjects; i++) {
		fileOfObj << dataFromFile[i].street << VALUE_SEPARATOR
			<< dataFromFile[i].number << VALUE_SEPARATOR
			<< dataFromFile[i].square << VALUE_SEPARATOR
			<< dataFromFile[i].structureType << VALUE_SEPARATOR
			<< endl;
	}
}

//метод пузырька для числовых полей
void bubbleSortNum(vector <House>& dataFromFile, int numOfObjects) {
	int i = 1;
	int limit = numOfObjects;
	while (i < limit) {
		for (int j = 0; j < limit - 1; j++) {
			if (dataFromFile[j].number < dataFromFile[j + 1].number) {
				swap(dataFromFile[j], dataFromFile[j + 1]);
			}
		}
		limit--;
	}
}
//метод пузырька для строковых полей
void bubbleSortStreet(vector <House>& dataFromFile, int numOfObjects) {
	int limit = numOfObjects;
	int i = 1;
	while (i < limit) {
		for (int j = 0; j < limit - 1; j++) {
			if (dataFromFile[j].street > dataFromFile[j + 1].street) {
				swap(dataFromFile[j], dataFromFile[j + 1]);
			}
		}
		limit--;
	}
}

