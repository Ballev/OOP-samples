#ifndef __FISH_HEADER__
#define __FISH_HEADER__

#include "Animal.h"

class Fish 
	: public Animal {

public:
	Fish();
	Fish(const char*, AnimalEatingHabits, FoodTypes, unsigned int, AnimalHabitat, const char*);
	Fish(const Fish&);
	Fish& operator=(const Fish&);
	~Fish();

public:
	virtual void print() override;
};

#endif  // !__FISH_HEADER__