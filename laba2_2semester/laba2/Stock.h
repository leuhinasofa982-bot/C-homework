//5 задание

#pragma once
#include <vector>

class Stock {
private:
	struct oneBox {
		int w;
		int v;
	};
	std::vector <oneBox> boxes;
public:
	void Add(int w, int v);
	int GetByW(int min_w);
	int GetByV(int min_v);
};

