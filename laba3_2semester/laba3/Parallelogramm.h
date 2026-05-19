#pragma once
#include "Figure.h"

class Parallelogramm : public Figure {
private:
	double base;
	double height;
public:
	Parallelogramm(double base, double height);
	double calcArea() override;
	void show() override;
};