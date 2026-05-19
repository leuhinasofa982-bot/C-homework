#include "Triangle.h"
#include <iostream>
using namespace std;

	Triangle::Triangle(double base, double height) {
		this->base = base;
		this->height = height;
	}
	double Triangle::calcArea() {
		double area = 0.5 * base * height;
		return area;
	}
	void Triangle::show() {
		cout << "Фигура: треугольник\n"
			<< "Основание и высота треугольника: " << base << ", "
			<< height << endl
			<< "Площадь фигуры: " << calcArea() << endl << endl;
	}
