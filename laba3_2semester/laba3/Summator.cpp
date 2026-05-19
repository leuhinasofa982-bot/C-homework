#include "Summator.h"


	int Summator::transform(int i) {
		return i;
	}
	int Summator::Sum(int N) {
		int summa = 0;
		for (int i = 1; i <= N; i++) {
			summa += transform(i);
		}
		return summa;
	}
