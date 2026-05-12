#include "Complex.h"
#include <cmath>
#include <iostream>
using namespace std;


	//конструкторы
	Complex::Complex() {
		re = 0.0; //можно и просто 0, дл€ нагл€дности 0.0
		im = 0.0;
	}
	Complex::Complex(double x, double y) {
		re = x;
		im = y;
	}


	//геттеры и сетторы
	double Complex::Get_im() {
		return im;
	}
	double Complex::Get_re() {
		return re;
	}
	void Complex::Set_im(double im) {
		this->im = im;
	}
	void Complex::Set_re(double re) {
		this->re = re;
	}


	//методы
	double Complex::Abs() {
		return sqrt(pow(re, 2) + pow(im, 2));
	}
	double Complex::Arg() {
		return atan2(im, re);
		/*аргумент - угол между + направлением и вектором к числу,
		atan2 арктангенс, но он различает, в какой четверти точка,
		в отличие от atan*/
	}

	void Complex::Print() {
		cout << " омплексное число(стандартна€ форма) z = "
			<< re << " + i * " << im << endl;
	}
	void Complex::TrigPrint() {
		cout << " омплексное число(тригонометрическа€ форма) z = "
			<< Abs() << " * (cos(" << Arg()
			<< ") + i * sin(" << Arg() << "))" << endl;
	}
	void Complex::ExpPrint() {
		cout << " омплексное число(показательна€ форма) z = "
			<< Abs() << " * e^i*" << Arg() << endl;
	}

	Complex Complex::Add(Complex z) {
		double newRe = this->re + z.re; //можно this->re + z.Get_re()
		double newIm = this->im + z.im;
		Complex newNum(newRe, newIm);
		return newNum;
	}
	Complex Complex::Sub(Complex z) {
		double newRe = this->re  - z.re;
		double newIm = this->im - z.im;
		Complex newNum(newRe, newIm);
		return newNum;
	}
	Complex Complex::Mult(Complex z) {
		double newRe = this->re * z.re - this->im * z.im;
		double newIm = this->re * z.im + this->im * z.re;
		Complex newNum(newRe, newIm);
		return newNum;
	}
	Complex Complex::Div(Complex z) {
		double denominator = pow(z.re, 2) + pow(z.im, 2);
		double newRe = (this->re * z.re + this->im * z.im) / denominator;
		double newIm = (this->im * z.re - this->re * z.im) / denominator;
		Complex newNum(newRe, newIm);
		return newNum;
	}