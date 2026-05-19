#pragma once
#include "Summator.h"

class CubeSummator : public Summator {
private:
	int transform(int i) override;
};