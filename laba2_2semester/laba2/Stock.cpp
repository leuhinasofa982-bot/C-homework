#include "Stock.h"

	void Stock::Add(int w, int v) {
		boxes.push_back({ w, v });
		/*автоматически создает структуру и добавляет
		ее в вектор, короткая запись*/
	}
	int Stock::GetByW(int min_w) {
		int minPossible = -1; //начальное значение т.к. еще ничего не нашли
		for (int i = 0; i < boxes.size(); i++) {
			if (boxes[i].w >= min_w) {
				if (minPossible == -1/*первую подходящую мы берем в любом случае*/
					|| boxes[i].w <= boxes[minPossible].w) {
					//<= т.к. нам нужен наибольший индекс
					minPossible = i;
				}
			}
		}
		if (minPossible != -1) {
			boxes.erase(boxes.begin() + minPossible);
		}
		return  minPossible;
	}
	int Stock::GetByV(int min_v) {
		int minPossible = -1;
		for (int i = 0; i < boxes.size(); i++) {
			if (boxes[i].v >= min_v) {
				if (minPossible == -1 || boxes[i].v <= boxes[minPossible].v) {
					minPossible = i;
				}
			}
		}
		if (minPossible != -1) {
			boxes.erase(boxes.begin() + minPossible);
		}
		return  minPossible;
	}
