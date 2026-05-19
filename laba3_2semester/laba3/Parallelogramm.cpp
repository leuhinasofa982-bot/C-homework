#include "Parallelogramm.h"
#include <iostream>
using namespace std;

	Parallelogramm::Parallelogramm(double base, double height) {
		this->base = base;
		this->height = height;
	}
	double Parallelogramm::calcArea() {
		double area = base * height;
		return area;
	}
	void Parallelogramm::show() {
		cout << "Фигура: параллелограмм\n"
			<< "Основание и высота параллелограмма: " << base << ", "
			<< height << endl
			<< "Площадь фигуры: " << calcArea() << endl << endl;
	}