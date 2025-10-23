#include <iostream>
using namespace std;

/*функция считает сумму
положительных чисел массива*/
float summa(float* arr, int amount) {
	float sum = 0;
	for (int i = 0; i < amount; i++) {
		if (arr[i] > 0)
			sum += arr[i];
	}
	return sum;
}

/*функция считает произведение
элементов между наибольшим и 
наименьшим значениями (по модулю)*/
float multiplication(float* arr, int amount) {
	float max = abs(arr[0]);
	float min = abs(arr[0]);
	int indMax = 0;
	int indMin = 0;
	for (int i = 1; i < amount; i++) {
		if (abs(arr[i]) > max) {
			max = abs(arr[i]);
			indMax = i;
		}
		if (abs(arr[i]) < min) {
			min = abs(arr[i]);
			indMin = i;
		}
	}

	float multi = 1;
	float start = (indMin < indMax) ? indMin : indMax;
	float end = (indMin > indMax) ? indMin : indMax;
	for (int i = start + 1; i < end; i++) {
		multi *= arr[i];
	}
	return multi;
}

/*функция преобразовывает массив,
чтобы сначала были положительные
числа*/
float* newArray(float* arr, int amount) {
	float* newArr = new float[amount];
	int a = 0;
	for (int i = 0; i < amount; i++) {
		if (arr[i] >= 0) {
			newArr[a] = arr[i];
			a++;
		}
	}
	for (int i = 0; i < amount; i++) {
		if (arr[i] < 0) {
			newArr[a] = arr[i];
			a++;
		}
	}
	return newArr;
}

int main()
{
	setlocale(LC_ALL, "ru");
	int amount;
	cout << "Сколько будет элементов?" << endl;
	cin >> amount;
	float* arr = new float[amount];
	cout << "Введите элементы массива:"
		<< endl;
	for (int i = 0; i < amount; i++) {
		cin >> arr[i];
	}

	cout << "Сумма положительных " //1 задание
		<< "элементов массива: " << 
		summa(arr, amount) << endl;

	
	if (multiplication(arr, amount) == 1) //2 задание
		cout << "Между наибольшим "
		<< "и наименьшим элементами "
		<< "массива нет чисел" << endl;
	else 
		cout << "Произведение элементов массива: "
		<< multiplication(arr, amount) << endl;

	
	cout << "Новый массив:" << endl; //3 задание
	float* newArr = newArray(arr, amount);
	for (int i = 0; i < amount; i++) {
		cout << newArr[i] << " ";
	}

	delete[] arr;
	return 0;
}
