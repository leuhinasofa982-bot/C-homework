//3 задание

#pragma once
#include <vector>

class Table {
private:
	std::vector <std::vector <int>> tableOfInt;
public:
	Table(int rows, int cols);

	int get_value(int row, int col);
	void set_value(int row, int col, int value);
	int n_rows();
	int n_cols();
	void print();
	double average();
};
