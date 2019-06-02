// All constants and enums we need for the project are collected here.
#ifndef __CONSTANTS_HEADER__
#define __CONSTANTS_HEADER__

enum AnimalTypes {

	UNDEFINED = -1,
	MAMMAL,
	BIRD,
	REPTILE,
	FISHES
};

enum AnimalEatingHabits {

	HUNGRY = -1,
	HERBIVOR,
	CARNIVOR
};

enum FoodTypes {

	FEEDLESS = -1,
	MEAT,
	FISH,
	PLANTS
};

enum AnimalHabitat {

	NONE = -1,
	FOREST,
	SAVANNA,
	JUNGLE,
	ARCTICZONE,
	AQUARIUM,
	TERRARIUM
};

enum Terrain {

	WITHOUTTERRAIN = -1,
	FORESTY,
	HILLS,
	DESSERT,
	WATER
};

const unsigned int MIN_PERCENTAGE = 0;
const unsigned int MAX_PERCENTAGE = 100;

#endif // !__CONSTANTS_HEADER__