#include <iostream>
#include <string>
#include <fstream>
#include <limits>
#include <sstream>

using namespace std;

const char VALUE_SEPARATOR = ',';

enum class SunExposure {
	fullSun,
	partialSun,
	partialShade,
	fullShade
};
struct Flower {
	SunExposure light;
	string type;
	string color;
	int size;
	double price;
};
struct ListElement {
	Flower flower;
	ListElement* next;
};


void printList(ListElement* listHead);
ListElement* createNewElement(ListElement* listHead);

ListElement* deleteElement(ListElement* listHead);
ListElement* removeList(ListElement* listHead);

void saveListToFile(const char* fileName, ListElement* listHead);
void listFromFile(const char* fileName, ListElement* listHead);


int main()
{
	setlocale(LC_ALL, "ru");
	ListElement* listHead = nullptr;
	int choiceOfAction;
	const char* fileName = "flowers.csv";
	do {
		//system("cls");
		cout << "Что вы хотите сделать, введите нужную цифру:" << endl
			<< "1 - Вывести текущий список на экран" << endl
			<< "2 - Добавить в список новый элемент" << endl
			<< "3 - Удалить из списка существующий элемент" << endl
			<< "4 - Очистить список" << endl
			<< "5 - Сохранить список в файл" << endl
			<< "6 - Загрузить список из файла" << endl
			<< "7 - Выход из меню" << endl;
		cin >> choiceOfAction;
		if (choiceOfAction == 1) {
			printList(listHead);
		}
		else if (choiceOfAction == 2) {
			listHead = createNewElement(listHead);
		}
		else if (choiceOfAction == 3) {
			listHead = deleteElement(listHead);
		}
		else if (choiceOfAction == 4) {
			listHead = removeList(listHead);
		}
		else if (choiceOfAction == 5) {
			saveListToFile(fileName, listHead);
		}
		else if (choiceOfAction == 6) {
			listFromFile(fileName, listHead);
		}
		else if(choiceOfAction == 7){
			cout << "Программа завершена!" << endl;
		}
		else {
			cout << "Некорректный ввод, такой команды нет" << endl;
		}
	} while (choiceOfAction != 7);
	//to do delete list
}


//функция добавления нового элемента
ListElement* createNewElement(ListElement* listHead) {
	ListElement* newElement = new ListElement;

	cout << "Введите тип цветка:" << endl;
	cin >> newElement->flower.type;
	cin.ignore(numeric_limits<streamsize>::max(), '\n');

	cout << "Введите цвет цветка:" << endl;
	cin >> newElement->flower.color;
	cin.ignore(numeric_limits<streamsize>::max(), '\n');

	cout << "Введите размер цветка(в сантиметрах):" << endl;
	cin >> newElement->flower.size; 
	cin.ignore(numeric_limits<streamsize>::max(), '\n');

	cout << "Введите цену цветка:" << endl;
	cin >> newElement->flower.price;
	cin.ignore(numeric_limits<streamsize>::max(), '\n');

	cout << "Введите световые особенности цветка:" << endl
		<< "1 - полный солнечный свет" << endl
		<< "2 - частичное солнечное освещение" << endl
		<< "3 - частичная тень" << endl
		<< "4 - полная тень" << endl;
	int lightOption;
	cin >> lightOption;
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	if (lightOption < 1 || lightOption > 4) {
		cout << "Некорректный ввод" << endl;
		return nullptr;
	}
	else {
		newElement->flower.light = static_cast<SunExposure>(lightOption - 1);
	}

	newElement->next = listHead;
	listHead = newElement;
	cout << "Элемент добавлен!" << endl;

	return listHead;
}


//функция вывода на экран списка
void printList(ListElement* listHead) {
	if (listHead == nullptr) {
		cout << "Список пустой" << endl;
		return;
	}
	ListElement* currentElement = listHead;
	int elementNumber = 1;
	while (currentElement != nullptr) {
		cout << elementNumber << ")" << endl
			<< "Тип:    " << currentElement->flower.type << endl
			<< "Цвет:   " << currentElement->flower.color << endl
			<< "Размер: " << currentElement->flower.size << endl
			<< "Цена:   " << currentElement->flower.price << endl;
		int lightOption = static_cast<int>(currentElement->flower.light) + 1;
		if (lightOption == 1) cout << "Желательно наличие полного солнечного света" << endl;
		if (lightOption == 2) cout << "Желательно наличие частичного солнечного освещения" << endl;
		if (lightOption == 3) cout << "Желательно наличие частичной тени" << endl;
		if (lightOption == 4) cout << "Желательно наличие полной тени" << endl;
		currentElement = currentElement->next;
		elementNumber++;
	}
}

//функция удаления элемента
ListElement* deleteElement(ListElement* listHead) {
	ListElement* currentElement = listHead;
	listHead = currentElement->next;
	delete currentElement;
	return listHead;
}


//функция удаления всего списка
ListElement* removeList(ListElement* listHead) {
	if (listHead == nullptr) {
		cout << "Список пустой" << endl;
		return nullptr;
	}
	ListElement* currentElement;
	while (listHead != nullptr) {
		currentElement = listHead;
		listHead = currentElement->next;
		delete currentElement;
	}
	return listHead;
}


//функция сохранения списка в файл
void saveListToFile(const char* fileName, ListElement* listHead) {
	ofstream fileList(fileName);
	if (listHead == nullptr) {
		cout << "Ничего не сохранилось, список пустой" << endl;
		return;
	}
	ListElement* currentElement = listHead;
	fileList << "Тип" << VALUE_SEPARATOR << "Цвет" << VALUE_SEPARATOR 
		<< "Размер" << VALUE_SEPARATOR << "Цена" << VALUE_SEPARATOR 
		<< "Освещение номер" << VALUE_SEPARATOR<< "Освещение текстом" << endl;
	while (currentElement != nullptr) {
		 fileList 
			 << currentElement->flower.type << VALUE_SEPARATOR
			<< currentElement->flower.color << VALUE_SEPARATOR
			<< currentElement->flower.size << VALUE_SEPARATOR
			<< currentElement->flower.price << VALUE_SEPARATOR;
		int lightOption = static_cast<int>(currentElement->flower.light) + 1;
		fileList << lightOption << VALUE_SEPARATOR;
		if (lightOption == 1) fileList << "Желательно наличие полного солнечного света";
		if (lightOption == 2) fileList <<"Желательно наличие частичного солнечного освещения";
		if (lightOption == 3) fileList << "Желательно наличие частичной тени";
		if (lightOption == 4) fileList << "Желательно наличие полной тени";
		fileList << endl;
		currentElement = currentElement->next;
	}
	cout << "Список сохранен!" << endl;
}


//функция записи списка из файла
void listFromFile(const char* fileName, ListElement* listHead) {
	ifstream fileList(fileName);
	string line;
	getline(fileList, line);
	while (getline(fileList, line)) {
		ListElement* currentElement = new ListElement;
		stringstream flowerData(line);
		getline(flowerData, currentElement->flower.type, VALUE_SEPARATOR);
		getline(flowerData, currentElement->flower.color, VALUE_SEPARATOR);
		string size;
		getline(flowerData, size, VALUE_SEPARATOR);
		currentElement->flower.size = stoi(size);
		string price;
		getline(flowerData, price, VALUE_SEPARATOR);
		currentElement->flower.price = stod(price);
		string lightOption;
		getline(flowerData, lightOption, VALUE_SEPARATOR);
		currentElement->flower.light = static_cast<SunExposure>(stoi(lightOption) - 1);

		currentElement->next = listHead;
		listHead = currentElement;
	}
	
}