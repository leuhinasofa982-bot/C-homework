#include "Complex.h"
#include <fstream>
using namespace std;

    // конструкторы
    Complex::Complex() : re(0.0), im(0.0) {}
    Complex::Complex(int x, int y) : re(x), im(y) {}
    Complex::Complex(double x, double y) : re(x), im(y) {}
    Complex::Complex(const Complex& other) : re(other.re), im(other.im) {}

    // присваивание
    Complex& Complex::operator=(const Complex& other) {
        if (this != &other) {
            re = other.re;
            im = other.im;
        }
        return *this;
    }


    Complex Complex::operator+(const Complex& o) const { return Complex(re + o.re, im + o.im); }
    Complex Complex::operator-(const Complex& o) const { return Complex(re - o.re, im - o.im); }
    Complex Complex::operator*(const Complex& o) const {
        return Complex(re * o.re - im * o.im, re * o.im + im * o.re);
    }
    Complex Complex::operator/(const Complex& o) const {
        double denom = o.re * o.re + o.im * o.im;
        return Complex((re * o.re + im * o.im) / denom, (im * o.re - re * o.im) / denom);
    }

    // комбинированные операторы
    Complex& Complex::operator+=(const Complex& o) { re += o.re; im += o.im; return *this; }
    Complex& Complex::operator-=(const Complex& o) { re -= o.re; im -= o.im; return *this; }
    Complex& Complex::operator*=(const Complex& o) {
        double r = re * o.re - im * o.im;
        double i = re * o.im + im * o.re;
        re = r; im = i;
        return *this;
    }
    Complex& Complex::operator/=(const Complex& o) {
        double denom = o.re * o.re + o.im * o.im;
        double r = (re * o.re + im * o.im) / denom;
        double i = (im * o.re - re * o.im) / denom;
        re = r; im = i;
        return *this;
    }

    Complex& Complex::operator++() { ++re; ++im; return *this; }      // префикс
    Complex Complex::operator++(int) { Complex tmp = *this; ++(*this); return tmp; } // постфикс
    Complex& Complex::operator--() { --re; --im; return *this; }      // префикс
    Complex Complex::operator--(int) { Complex tmp = *this; --(*this); return tmp; } // постфикс

    // модуль (длина)
    double Complex::magnitude() const { return std::hypot(re, im); }

    // сравнение по модулю
    bool Complex::operator>(const Complex& o) const { return magnitude() > o.magnitude(); }
    bool Complex::operator<(const Complex& o) const { return magnitude() < o.magnitude(); }
    bool Complex::operator>=(const Complex& o) const { return magnitude() >= o.magnitude(); }
    bool Complex::operator<=(const Complex& o) const { return magnitude() <= o.magnitude(); }
    // равенство по компонентам
    bool Complex::operator==(const Complex& o) const { return re == o.re && im == o.im; }
    bool Complex::operator!=(const Complex& o) const { return !(*this == o); }

    // ввод/вывод
    ostream& operator<<(ostream& os, const Complex& c) {
        os << c.re;
        if (c.im >= 0) os << " + " << c.im << "i";
        else os << " - " << -c.im << "i";
        return os;
    }

    // при вводе ожидаем два числа: re im
    istream& operator>>(istream& is, Complex& c) {
        is >> c.re >> c.im;
        return is;
    }