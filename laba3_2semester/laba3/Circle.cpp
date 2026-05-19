#include "Circle.h"
#include <cmath>
#include <iostream>
using namespace std;

const double PI = 3.14159;

	Circle::Circle(double radius) {
		this->radius = radius;
	}
	double Circle::calcArea() {
		double area = PI * pow(radius, 2);
		return area;
	}
	void Circle::show() {
		cout << "Фигура: круг\n" << "Радиус фигуры: " << radius
			<< endl << "Площадь фигуры: " << calcArea() << endl << endl;
	}
