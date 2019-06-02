#include "Storage.h"


Storage::Storage() : meat(0), fish(0), plants(0), neededMeat(0), neededFish(0), neededPlants(0)
{}

const unsigned int Storage::getNeededMeat() const {

	return neededMeat;
}

const unsigned int Storage::getNeededFish() const {
	
	return neededFish;
}

const unsigned int Storage::getNeededPlants() const {

	return neededPlants;
}

const unsigned int Storage::getMeat() const {

	return meat;
}

const unsigned int Storage::getFish() const {

	return fish;
}

const unsigned int Storage::getPlants() const {

	return plants;
}

void Storage::setMeat(unsigned int _meat) {

	meat = _meat;
}

void Storage::setFish(unsigned int _fish) {

	fish = _fish;
}

void Storage::setPlants(unsigned int _plants) {

	plants = _plants;
}

void Storage::setNeededMeat(unsigned int _meat) {

	neededMeat = _meat;
}

void Storage::setNeededFish(unsigned int _fish) {

	neededFish = _fish;
}

void Storage::setNeededPlants(unsigned int _plants) {

	plants = _plants;
}

bool Storage::isAbleToFeedTheAnimals() {

	if (meat < neededMeat || fish < neededFish || plants < neededPlants)
		return false;

	return true;
}

