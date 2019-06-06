#include "Cage.h"



Cage::Cage() : name(nullptr), animals(nullptr), curSizeOfAnimals(0), terrain(WITHOUTTERRAIN),
			   isForMeatEaters(0), habitat(NONE), humidity(0), flora(0), location(nullptr)
{}

Cage::Cage(const char * _name, unsigned int _humidity, unsigned int _flora, Terrain _terrain, const char * _location, bool _eatsMeat, AnimalHabitat _habitat) 
	: animals(nullptr), curSizeOfAnimals(0), isForMeatEaters(_eatsMeat), habitat(_habitat), terrain(_terrain) {

	if (_humidity > MAX_PERCENTAGE || _humidity < MIN_PERCENTAGE) {

		std::cout << "There was a problem with the persentage you have tried to add for the humidity of the cage!\n";
		return;
	}

	humidity = _humidity;

	if (_flora > MAX_PERCENTAGE || _flora < MIN_PERCENTAGE) {

		std::cout << "There was a problem with the persentage you have tried to add for the flora of the cage!\n";
		return;
	}

	flora = _flora;

	name = new (std::nothrow) char[strlen(_name) + 1];
	if (!name) {

		std::cerr << "There was a problem with allocating memory for our cage's name!\n";
		return;
	}

	strcpy(name, _name);

	location = new (std::nothrow) char[strlen(_location) + 1];
	if (!location) {

		std::cerr << "There was a problem with allocating memory for our cage's location!\n";
		return;
	}

	strcpy(location, _location);
}

Cage::Cage(const Cage & other) {

	copyFrom(other);
}


Cage & Cage::operator=(const Cage & other) {

	if (this != &other) {

		clean();
		copyFrom(other);
	}

	return *this;
}

Cage::~Cage() {

	clean();
}

const char * Cage::getName() const {

	return name;
}

const char * Cage::getLocation() const {

	return location;
}

const unsigned int Cage::getHumidity() const {

	return humidity;
}

const unsigned int Cage::getFlora() const {

	return flora;
}

const Terrain Cage::getTerrain() const {

	return terrain;
}

const size_t Cage::getCurSize() const {

	return curSizeOfAnimals;
}

const bool Cage::getIsForMeatEaters() const {

	return isForMeatEaters;
}

const AnimalHabitat Cage::getHabitat() const {

	return habitat;
}

void Cage::addAnimal(Animal* newAnimal) {

	Animal** temp = new (std::nothrow) Animal* [curSizeOfAnimals + 1];
	if (!temp) {

		std::cerr << "There was a problem with allocating memory for our animal's container!\n";
		return;
	}

	for (size_t i = 0; i < curSizeOfAnimals; ++i) {

		temp[i] = animals[i];
	}

	temp[curSizeOfAnimals] = newAnimal;

	++curSizeOfAnimals;
	
	//cleaning only the array of pointers 
	//not the pointers themselves
	delete[] animals;

	animals = temp;
}

void Cage::clean() {

	delete[] name;
	name = nullptr;

	for (size_t i = 0; i < curSizeOfAnimals; ++i) {

		delete animals[i];
	}

	delete[] animals;
	animals = nullptr;

	delete[] location;
	location = nullptr;

	curSizeOfAnimals = 0;
}

void Cage::copyFrom(const Cage & other) {

	name = new (std::nothrow) char[strlen(other.getName()) + 1];
	if (!name) {

		std::cerr << "There was a problem with allocating memory for our animal's name!\n";
		return;
	}

	strcpy(name, other.getName());

	humidity = other.getHumidity();
	flora = other.getFlora();
	curSizeOfAnimals = other.getCurSize();
	isForMeatEaters = other.getIsForMeatEaters();
	habitat = other.getHabitat();

	location = new (std::nothrow) char[strlen(other.getLocation()) + 1];
	if (!location) {

		std::cerr << "There was a problem with allocating memory for our animal's name!\n";
		return;
	}

	strcpy(location, other.getLocation());

	animals = new (std::nothrow) Animal*[other.getCurSize()];
	if (!animals) {

		std::cerr << "There was a problem with allocating memory for our animal's container!\n";
		return;
	}

	for (size_t i = 0; i < other.getCurSize(); ++i) {

		animals[i] = other.animals[i]->clone();
	}
}

const char * Cage::terrainToString() const {
	if (terrain == FORESTY)
		return "Foresty";

	else if (terrain == 1)
		return "Hills";

	else if (terrain == 2)
		return "Dessert";

	else if (terrain == 3)
		return "Water";

	else
		return "Undefined terrain";
}

const char * Cage::isForMeatEatersToString() const
{
	if (isForMeatEaters)
		return "eat meat";

	return "do not eat meat";
}
