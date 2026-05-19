#pragma once
#include "Figure.h"

class Rectangle : public Figure {
private:
	double lenght;
	double width;
public:
	Rectangle(double lenght, double width);
	double calcArea() override;
	void show() override;
};