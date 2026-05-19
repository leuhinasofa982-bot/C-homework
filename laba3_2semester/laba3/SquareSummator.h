#pragma once
#include "Summator.h"

class SquareSummator : public Summator {
private:
	int transform(int i) override;
};