#pragma once
#include <fstream>

class Rational {
private:
    int num; // числитель
    int den; // знаменатель (внутри всегда >0)

    void normalize();
public:
    Rational(int n = 0, int d = 1);
    int Numerator() const;
    int Denominator() const;
    Rational operator+() const;
    Rational operator-() const;
    Rational& operator+=(const Rational& r);
    Rational& operator-=(const Rational& r);
    Rational& operator*=(const Rational& r);
    Rational& operator/=(const Rational& r);
    Rational& operator+=(int x);
    Rational& operator-=(int x);
    Rational& operator*=(int x);
    Rational& operator/=(int x);
    bool operator==(const Rational& r)const;
    bool operator!=(const Rational& r)const;
    friend Rational operator+(Rational a, const Rational& b);
    friend Rational operator-(Rational a, const Rational& b);
    friend Rational operator*(Rational a, const Rational& b);
    friend Rational operator/(Rational a, const Rational& b);
    friend Rational operator+(Rational a, int b);
    friend Rational operator-(Rational a, int b);
    friend Rational operator*(Rational a, int b);
    friend Rational operator/(Rational a, int b);
    friend Rational operator+(int a, Rational b);
    friend Rational operator-(int a, Rational b);
    friend Rational operator*(int a, Rational b);
    friend Rational operator/(int a, Rational b);
    friend std::ostream& operator<<(std::ostream& os, const Rational& r);
    friend std::istream& operator>>(std::istream& is, Rational& r);
};
