#ifndef __BIRD_HEADER__
#define __BIRD_HEADER__

#include "Animal.h"

class Bird :
	public Animal {

public:
	Bird(const char*, AnimalEatingHabits, FoodTypes, unsigned int, AnimalHabitat, const char*);
	~Bird();

public:
	virtual void print() override;
	virtual Animal* clone() override;
};

#endif // !__BIRD_HEADER__
