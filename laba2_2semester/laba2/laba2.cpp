#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include "Bell.h"
#include "OddEvenSeparator.h"
#include "Table.h"
#include "Complex.h"
#include "Stock.h"
using namespace std;


int main()
{
	setlocale(LC_ALL, "ru");

	//1 задание
	Bell bell1;
	bell1.sound();

	//2 задание
	OddEvenSeparator num;
	int number = 1;
	num.add_number(10.9);
	num.add_number(10);
	num.add_number(1063);
	num.add_number(number);
	num.even();
	num.odd();
	
	//3 задание
	Table table(4, 4);
	table.set_value(0, 0, 3);
	table.set_value(0, 2, 5);
	table.set_value(0, 3, 12);
	table.set_value(2, 1, 10);
	cout << "Значение ячейки (0,0): " << table.get_value(0, 0) << endl;
	cout << "Среднее арифметическое таблиц: " << table.average() << endl;
	cout << "Количество строк и столбцов в таблице: " << table.n_rows() << ", " << table.n_cols() << endl;
	table.print();

	//4 задание
	Complex num(3.5, -1.2);

	//геттер и сеттор
	cout << "re(действительная часть) комплексного числа: " << num.Get_re() << endl;
	double newRe;
	cout << "Введите новую re(действительная часть): ";
	cin >> newRe;
	num.Set_re(newRe);
	cout << "Новая re(действительная часть) комплексного числа: " << num.Get_re() << endl;

	cout << "Модуль и аргумент комплексного числа: " << num.Abs()
		<< ", " << num.Arg() << endl;

	//принты
	num.Print();
	num.TrigPrint();
	num.ExpPrint();

	//действия с числами
	Complex z;
	cout << "Введите число z(действительную и мнимую части): ";
	double re, im;
	cin >> re >> im;
	if (re == 0 || im == 0) {
		cout << "Re и im числа не должны равняться 0!" << endl;
	}
	else {
		z.Set_re(re);
		z.Set_im(im);
		cout << "Результат сложения текущего комплексного числа с комплексным числом z: ";
		num.Add(z).Print();
		cout << "Результат вычитания текущего комплексного числа с комплексным числом z: ";
		num.Sub(z).TrigPrint();
		cout << "Результат умножения текущего комплексного числа с комплексным числом z: ";
		num.Mult(z).Print();
		cout << "Результат деления текущего комплексного числа с комплексным числом z: ";
		num.Div(z).ExpPrint();
	}

	//5 задание
	Stock warehouse;
	warehouse.Add(120, 30);
	warehouse.Add(472, 73);
	warehouse.Add(836, 65);
	warehouse.Add(295, 85);
	warehouse.Add(614, 47);
	warehouse.Add(90, 13);
	cout << "Введите грузоподъемность и объем новой коробки: ";
	int w, v;
	cin >> w >> v;
	warehouse.Add(w, v);
	cout << "Введите минимальную грузоподъемность: ";
	int min_w;
	cin >> min_w;
	int idW = warehouse.GetByW(min_w);
	if (idW == -1) {
		cout << "Нужной коробки нет на складе!" << endl;
	}
	else {
		cout << "Серийный номер нужной коробки: " << idW << endl;
	}
	cout << "Введите минимальный объем: ";
	int min_v;
	cin >> min_v;
	int idV = warehouse.GetByV(min_v);
	if (idV == -1) {
		cout << "Нужной коробки нет на складе!" << endl;
	}
	else {
		cout << "Серийный номер нужной коробки: " << idV << endl;
	}
}

