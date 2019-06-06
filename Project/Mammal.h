#ifndef __MAMMAL_HEADER__
#define __MAMMAL_HEADER__

#include "Animal.h"

class Mammal :
	public Animal {

public:
	Mammal(const char*, AnimalEatingHabits, FoodTypes, unsigned int, AnimalHabitat, const char*);
	~Mammal();
	
public:
	virtual void print() override;
	virtual Animal* clone() override;

};

#endif // !__MAMMAL_HEADER__
