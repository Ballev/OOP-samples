#ifndef __ANIMAL_HEADER__
#define __ANIMAL_HEADER__

#include <iostream>

#include "Constants.h"

class Animal {

public:
	Animal();
	Animal(const char*, AnimalTypes, AnimalEatingHabits, FoodTypes, unsigned int, AnimalHabitat, const char*);
	Animal(const Animal&);
	Animal& operator=(const Animal&);
	virtual ~Animal();

public:
	const char* getName() const;
	const AnimalTypes getType() const;
	const AnimalEatingHabits getEatingHabits() const;
	const FoodTypes getFood() const;
	const unsigned int getFoodQuantity() const;
	const AnimalHabitat getHabitat() const;
	const char* getSound() const;

public:
	virtual void print() = 0;
	virtual Animal* clone() = 0;

protected:
	const char* eatingHabitsToString() const;
	const char* foodToString() const;
	const char* habitatToString() const;
	void clean();
	void copyFrom(const Animal&);

protected:
	char* name;
	AnimalTypes type;
	AnimalEatingHabits eatingHabits;
	FoodTypes food;
	unsigned int foodQuantity;
	AnimalHabitat habitat;
	char* sound;
};

#endif // !__ANIMAL_HEADER__
