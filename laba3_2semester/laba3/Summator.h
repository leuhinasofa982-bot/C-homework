#pragma once

class Summator { //базовый класс
protected:
	virtual int transform(int i);
public:
	virtual ~Summator() {};
	int Sum(int N);
};