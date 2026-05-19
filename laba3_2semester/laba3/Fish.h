#pragma once
#include "Animal.h"

class Fish : public Animal {
public:
	void breathe() override;
	void eat() override;
	void swim();
};
