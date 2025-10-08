#include <iostream>
using namespace std;
const double kPi = 3.1415;

//функция считает площадь круга
double circleArea(double radius) {
	double circle = kPi * (radius * radius);
	return circle;
}

//функция считает площадь прямоугольника
double recArea(double side1, double side2) {
	double rectangle = side1 * side2;
	return rectangle;
}

/*функция считает площадь 
прямоугольного треугольника*/
double triArea(double side1, double side2) {
	double triangle = (side1 * side2) / 2;
	return triangle;
}

int main()
{
	setlocale(LC_ALL, "ru");
	int choice;
	int answer;
	/*цикл выполняется до тех пор,
	пока пользователь не введет 2, 
	в зависимости от выбора 
	пользователя вычисляется 
	площадь нужной фигуры*/
	do { 
		cout <<
			"Выберите фигуру" << 
			"(1-круг, 2-прямоугольник, 3-треугольник): "
			<< endl;
		cin >> choice;
		if (choice == 1) {
			cout << "Введите радиус круга: " << endl;
			double r;
			cin >> r;
			cout << "Площадь круга с радиусом "
				<< r << " равна: "
				<< circleArea(r) << endl;
		}
		else if (choice == 2) {
			cout << "Введите " << 
				"стороны прямоугольника : " << endl;
			double s1, s2;
			cin >> s1 >> s2;
			cout << "Площадь прямоугольника со сторонами "
				<< s1 << " и " << s2 << " равна: "
				<< recArea(s1, s2) << endl;
		}
		else {
			cout << "Введите стороны " << 
				"прямоугольного треугольника : "
				<< endl;
			double s1, s2;
			cin >> s1 >> s2;
			cout <<
				"Площадь прямоугольного " << 
				"треугольника со сторонами "
				<< s1 << " и " << s2 << " равна: "
				<< triArea(s1, s2) << endl;
		}
		cout << "Хотите продолжить расчеты?(да-1, нет-2)"
			<< endl;
		cin >> answer;
	} while (answer == 1);
}

