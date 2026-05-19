#include "Rational.h"
#include <numeric>   
using namespace std;

    void Rational::normalize() {
        if (den == 0) throw invalid_argument("Знаменатель не должен равняться 0");
        int g = std::gcd(abs(num), abs(den));
        num /= g;
        den /= g;
        if (den < 0) { // сделать знаменатель положительным
            num = -num;
            den = -den;
        }
    }
    // конструктор по умолчанию: 0/1
    Rational::Rational(int n = 0, int d = 1) : num(n), den(d) {
        normalize();
    }

    // получение несократимого представления
    int Rational::Numerator() const { return num; }
    int Rational::Denominator() const { return den; }

    // унарные операторы
    Rational Rational::operator+() const { return *this; }
    Rational Rational::operator-() const { return Rational(-num, den); }

    // комбинированные операторы с Rational и с int
    Rational& Rational::operator+=(const Rational& r) {
        long long newNum = (long long)num * r.den + (long long)r.num * den;
        long long newDen = (long long)den * r.den;
        num = (int)newNum;
        den = (int)newDen;
        normalize();
        return *this;
    }
    Rational& Rational::operator-=(const Rational& r) {
        long long newNum = (long long)num * r.den - (long long)r.num * den;
        long long newDen = (long long)den * r.den;
        num = (int)newNum;
        den = (int)newDen;
        normalize();
        return *this;
    }
    Rational& Rational::operator*=(const Rational& r) {
        num = num * r.num;
        den = den * r.den;
        normalize();
        return *this;
    }
    Rational& Rational::operator/=(const Rational& r) {
        if (r.num == 0) throw invalid_argument("Деление на 0!");
        num = num * r.den;
        den = den * r.num;
        normalize();
        return *this;
    }

    // варианты с int
    Rational& Rational::operator+=(int x) { return *this += Rational(x); }
    Rational& Rational::operator-=(int x) { return *this -= Rational(x); }
    Rational& Rational::operator*=(int x) { return *this *= Rational(x); }
    Rational& Rational::operator/=(int x) { return *this /= Rational(x); }

    // сравнения
    bool Rational::operator==(const Rational& r) const { return num == r.num && den == r.den; }
    bool Rational::operator!=(const Rational& r) const { return !(*this == r); }

    // дружественные не-членские операторы (реализованы через комбинированные)
    Rational operator+(Rational a, const Rational& b) { a += b; return a; }
    Rational operator-(Rational a, const Rational& b) { a -= b; return a; }
    Rational operator*(Rational a, const Rational& b) { a *= b; return a; }
    Rational operator/(Rational a, const Rational& b) { a /= b; return a; }

    // операции с int слева/справа
    Rational operator+(Rational a, int b) { a += b; return a; }
    Rational operator-(Rational a, int b) { a -= b; return a; }
    Rational operator*(Rational a, int b) { a *= b; return a; }
    Rational operator/(Rational a, int b) { a /= b; return a; }

    Rational operator+(int a, Rational b) { b += a; return b; }
    Rational operator-(int a, Rational b) { return Rational(a) - b; }
    Rational operator*(int a, Rational b) { b *= a; return b; }
    Rational operator/(int a, Rational b) { return Rational(a) / b; }

    // ввод/вывод: формат "a/b" или просто "a" (в этом случае знаменатель = 1)
    ostream& operator<<(ostream& os, const Rational& r) {
        if (r.den == 1) os << r.num;
        else os << r.num << '/' << r.den;
        return os;
    }

    istream& operator>>(istream& is, Rational& r) {
        int n;
        if (!(is >> n)) return is;
        is >> ws;
        if (is.peek() == '/') {
            char ch;
            int d;
            is >> ch >> d;
            r = Rational(n, d);
        }
        else {
            r = Rational(n, 1);
        }
        return is;
    }
