#include <iostream>
#include <string>
#include <cmath>
#include "OddEvenSeparator.h"
using namespace std;

	void OddEvenSeparator::add_number(double num) {
		if (num != (int)num) {
			cout << "Число " << num << " должно быть целым!" << endl;
		}
		else {
			listOfNum.push_back(num);
		}
	}

	void OddEvenSeparator::even() {
		cout << "Четные числа:" << endl;
		for (int i = 0; i < listOfNum.size(); i++) {
			if (listOfNum[i] % 2 == 0) {
				cout << listOfNum[i] << endl;
			}
		}
		cout << endl;
	}

	void OddEvenSeparator::odd() {
		cout << "Нечетные числа:" << endl;
		for (int i = 0; i < listOfNum.size(); i++) {
			if (listOfNum[i] % 2 != 0) {
				cout << listOfNum[i] << endl;
			}
		}
		cout << endl;
	}
