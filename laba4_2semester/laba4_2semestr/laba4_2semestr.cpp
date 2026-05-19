#include <iostream>
#include <cmath>
#include "Complex.h"
#include <numeric>   
#include <stdexcept> 
#include <cstdlib>
#include "Rational.h"
using namespace std;



int main() {
    setlocale(LC_ALL, "ru");

    //1 задание
    Complex a(3, 5);
    Complex b = a;
    Complex c;
    c = a;
    cout << "a = " << a << "\n";
    cout << "b = " << b << "\n";
    cout << "c = " << c << "\n";

    // арифметика
    Complex s = a + b;
    Complex d = a - b;
    Complex m = a * b;
    Complex div = a / b;

    cout << "a + b = " << s << "\n";
    cout << "a - b = " << d << "\n";
    cout << "a * b = " << m << "\n";
    cout << "a / b = " << div << "\n";

    // комбинированные
    a += Complex(1, 1);
    cout << "a после a += (1,1): " << a << "\n";

    // ++/--
    cout << "++a = " << ++a << ", a++ = " << a++ << ", now a = " << a << "\n";
    cout << "--b = " << --b << ", b-- = " << b-- << ", now b = " << b << "\n";

    // сравнение по модулю
    cout << "|a| = " << a.magnitude() << ", |b| = " << b.magnitude() << "\n";
    if (a > b) {
        cout << "a больше b по модулю\n";
    }
    else {
        cout << "a не больше b по модулю\n";
    }

    // ввод
    cout << "Введите два числа (реальную и мнимую части) для нового комплексного: ";
    Complex x;
    if (cin >> x) {
        cout << "Введено: " << x << "\n";
    }

    //2 задание
    try {
        Rational a(6, 8);
        Rational b(2, 3);
        cout << "a = " << a << ", b = " << b << '\n';

        cout << "a + b = " << (a + b) << '\n';
        cout << "a - b = " << (a - b) << '\n';
        cout << "a * b = " << (a * b) << '\n';
        cout << "a / b = " << (a / b) << '\n';

        a += 1; // с int
        cout << "a += 1 -> " << a << '\n';

        Rational c = 1 + b; 
        cout << "1 + b = " << c << '\n';

        cout << "Введите дробь в форме a/b или целое число: ";
        Rational x;
        if (cin >> x) cout << "Вы ввели: " << x << '\n';

        // проверки ==
        Rational r1(2, 4); // 1/2
        Rational r2(1, 2);
        cout << "r1 == r2 ? " << (r1 == r2) << '\n';

    }
    catch (const exception& e) {
        cerr << "Ошибка: " << e.what() << '\n';
    }
    return 0;
}
