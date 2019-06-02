#ifndef __REPTILE_HEADER__
#define __REPTILE_HEADER__

#include "Animal.h"

class Reptile :
	public Animal {

public:
	Reptile();
	Reptile(const char*, AnimalEatingHabits, FoodTypes, unsigned int, AnimalHabitat, const char*);
	Reptile(const Reptile&);
	Reptile& operator=(const Reptile&);
	~Reptile();

public:
	virtual void print() override;
};

#endif // !__REPTILE_HEADER__