#ifndef __ZOO_HEADER__
#define __ZOO_HEADER__

#include <iostream>

#include "Cage.h"
#include "Cages.h"
#include "Animal.h"
#include "Bird.h"
#include "Fish.h"
#include "Mammal.h"
#include "Reptile.h"
#include "Storage.h"
#include "Constants.h"

class Zoo {

	// Zoos are unique existences. They can be created and destroyed but 
	// they can not be copied.
public:
	Zoo(const char*);
	Zoo(const Zoo&) = delete;
	Zoo& operator=(const Zoo&) = delete;
	~Zoo();

public:
	bool addAnimal(Animal*);
	bool feedAnimals();
	void fillStorage();
	void createCage(Cage*);
	void printCageInfo(size_t);

private:
	void clean();

private:
	char* name;
	Cage** cages;
	Storage storage;
	size_t curSize;
};

#endif // !__ZOO_HEADER__