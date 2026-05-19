#pragma once
#include "Figure.h"

class Triangle : public Figure {
private:
	double base;
	double height;
public:
	Triangle(double base, double height);
	double calcArea() override;
	void show() override;
};
