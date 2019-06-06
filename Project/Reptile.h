#ifndef __REPTILE_HEADER__
#define __REPTILE_HEADER__

#include "Animal.h"

class Reptile :
	public Animal {

public:
	Reptile(const char*, AnimalEatingHabits, FoodTypes, unsigned int, AnimalHabitat, const char*);
	~Reptile();

public:
	virtual void print() override;
	virtual Animal* clone() override;
};

#endif // !__REPTILE_HEADER__
