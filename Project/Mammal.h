#ifndef __MAMMAL_HEADER__
#define __MAMMAL_HEADER__

#include "Animal.h"

class Mammal :
	public Animal {

public:
	Mammal();
	Mammal(const char*, AnimalEatingHabits, FoodTypes, unsigned int, AnimalHabitat, const char*);
	Mammal(const Mammal&);
	Mammal& operator=(const Mammal&);
	~Mammal();
	
public:
	virtual void print() override;
};

#endif // !__MAMMAL_HEADER__