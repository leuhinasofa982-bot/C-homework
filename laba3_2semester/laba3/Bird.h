#pragma once
#include "Animal.h"

class Bird : public Animal {
public:
	void breathe() override;
	void eat() override;
	void lay_eggs();
};
