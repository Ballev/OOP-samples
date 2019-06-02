#ifndef __STORAGE_HEADER__
#define __STORAGE_HEADER__

#include <iostream>

#include "Constants.h"

class Storage {

public:
	Storage();                                            // No dynamic data, does not need big 4.

public:
	const unsigned int getNeededMeat() const;
	const unsigned int getNeededFish() const;
	const unsigned int getNeededPlants() const;
	const unsigned int getMeat() const;
	const unsigned int getFish() const;
	const unsigned int getPlants() const;
	void setMeat(unsigned int);
	void setFish(unsigned int);
	void setPlants(unsigned int);
	void setNeededMeat(unsigned int);
	void setNeededFish(unsigned int);
	void setNeededPlants(unsigned int);


public:
	bool isAbleToFeedTheAnimals();

private:
	unsigned int meat;
	unsigned int fish;
	unsigned int plants;
	unsigned int neededMeat;
	unsigned int neededFish;
	unsigned int neededPlants;
};

#endif // !__STORAGE_HEADER__