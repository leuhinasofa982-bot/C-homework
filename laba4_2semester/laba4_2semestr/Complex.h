#pragma once
#include <fstream>

class Complex {
public:
    double re;
    double im;


    Complex();
    Complex(int x, int y);
    Complex(double x, double y);
    Complex(const Complex& other);
    Complex& operator=(const Complex& other);
    Complex operator+(const Complex& o)const;
    Complex operator-(const Complex& o)const;
    Complex operator*(const Complex& o)const;
    Complex operator/(const Complex& o)const;
    Complex& operator+=(const Complex& o);
    Complex& operator-=(const Complex& o);
    Complex& operator*=(const Complex& o);
    Complex& operator/=(const Complex& o);
    Complex& operator++();
    Complex operator++(int);
    Complex& operator--();
    Complex operator--(int);
    double magnitude()const;
    bool operator>(const Complex& o)const;
    bool operator<(const Complex& o)const;
    bool operator>=(const Complex& o)const;
    bool operator<=(const Complex& o)const;
    bool operator==(const Complex& o)const;
    bool operator!=(const Complex& o)const;
    friend std::ostream& operator<<(std::ostream& os, const Complex& c);
    friend std::istream& operator>>(std::istream& is, Complex& c);
};