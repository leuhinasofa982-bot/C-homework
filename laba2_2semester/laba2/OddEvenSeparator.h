//2 задание
#pragma once 
//мы 1 раз включаем этот файл с основной(проверка)
#include <vector>

class OddEvenSeparator {
private:
	std::vector <int> listOfNum;
public:
	void add_number(double num);
	void even();
	void odd();
};
