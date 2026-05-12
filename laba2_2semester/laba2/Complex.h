//4 задание

#pragma once

class Complex {
private:
	double re;
	double im;
public:
	Complex();
	Complex(double x, double y);
	double Get_im();
	double Get_re();
	void Set_im(double im);
	void Set_re(double re);
	double Abs();
	double Arg();
	void Print();
	void TrigPrint();
	void ExpPrint();
	Complex Add(Complex z);
	Complex Sub(Complex z);
	Complex Mult(Complex z);
	Complex Div(Complex z);
};
