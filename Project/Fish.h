#ifndef __FISH_HEADER__
#define __FISH_HEADER__

#include "Animal.h"

class Fish 
	: public Animal {

public:
	Fish(const char*, AnimalEatingHabits, FoodTypes, unsigned int, AnimalHabitat, const char*);
	~Fish();

public:
	virtual void print() override;
	virtual Animal* clone() override;
};

#endif  // !__FISH_HEADER__
