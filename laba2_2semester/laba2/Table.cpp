#include "Table.h"
#include <iostream>
using namespace std;


	Table::Table(int rows, int cols) {
		tableOfInt.assign(rows, vector<int>(cols, 0)); //assign меняет размер вектора, заполняет чем-то
	}


	int Table::get_value(int row, int col) {
		return tableOfInt[row][col];
	}
	void Table::set_value(int row, int col, int value) {
		tableOfInt[row][col] = value;
	}

	int Table::n_rows() {
		return tableOfInt.size();
	}
	int Table::n_cols() {
		return tableOfInt[0].size();
	}

	void Table::print() {
		for (int row = 0; row < tableOfInt.size(); row++) {
			for (int col = 0; col < tableOfInt[0].size(); col++) {
				cout << tableOfInt[row][col] << ' ';
			}
			cout << endl;
		}
	}

	double Table::average() {
		double sum = 0;
		int elementsAmount = 0;
		for (int row = 0; row < tableOfInt.size(); row++) {
			for (int col = 0; col < tableOfInt[0].size(); col++) {
				sum += tableOfInt[row][col];
				elementsAmount++;
			}
		}
		return sum / elementsAmount;
	}