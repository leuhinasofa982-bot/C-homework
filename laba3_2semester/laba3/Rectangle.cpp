#include "Rectangle.h"
#include <iostream>
using namespace std;

	Rectangle::Rectangle(double lenght, double width) {
		this->lenght = lenght;
		this->width = width;
	}
	double Rectangle::calcArea() {
		double area = lenght * width;
		return area;
	}
	void Rectangle::show() {
		cout << "Фигура: прямоугольник\n"
			<< "Длина и ширина прямоугольника: " << lenght << ", " << width << endl
			<< "Площадь фигуры: " << calcArea() << endl << endl;
	}