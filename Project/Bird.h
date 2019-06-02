#ifndef __BIRD_HEADER__
#define __BIRD_HEADER__

#include "Animal.h"

class Bird :
	public Animal {

public:
	Bird();
	Bird(const char*, AnimalEatingHabits, FoodTypes, unsigned int, AnimalHabitat, const char*);
	Bird(const Bird&);
	Bird& operator=(const Bird&);
	~Bird();

public:
	virtual void print() override;
};

#endif // !__BIRD_HEADER__