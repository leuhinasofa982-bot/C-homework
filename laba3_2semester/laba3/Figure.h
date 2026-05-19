#pragma once

class Figure {
public:
	virtual double calcArea() = 0;
	virtual void show() = 0;
	double cylinderVolume(double height);
};