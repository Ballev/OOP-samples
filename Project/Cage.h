#ifndef __CAGE_HEADER__
#define __CAGE_HEADER__

#include <iostream>

#include "Animal.h"
#include "Constants.h"

class Cage {

public:
	Cage();
	Cage(const char*, unsigned int, unsigned int, Terrain, const char*, bool, AnimalHabitat);
	Cage(const Cage&);
	Cage& operator=(const Cage&);
	virtual ~Cage();

public:
	const char* getName() const;
	const char* getLocation() const;
	const unsigned int getHumidity() const;
	const unsigned int getFlora() const;
	const Terrain getTerrain() const;
	const size_t getCurSize() const;
	const  bool getIsForMeatEaters() const;
	const AnimalHabitat getHabitat() const;

	void addAnimal(Animal*);
	virtual void print() = 0;

protected:
	void clean();
	void copyFrom(const Cage&);
	const char* terrainToString() const;
	const char* isForMeatEatersToString() const;

protected:
	char* name;
	unsigned int humidity;
	unsigned int flora;
	Terrain terrain;
	Animal** animals;
	size_t curSizeOfAnimals;
	char* location;
	bool isForMeatEaters;
	AnimalHabitat habitat;
};

#endif // !__CAGE_HEADER__

