#include "Animal.h"


Animal::Animal() : name(nullptr), type(UNDEFINED), food(FEEDLESS), eatingHabits(HUNGRY), foodQuantity(0), habitat(NONE), sound(nullptr)
{}

Animal::Animal(const char * _name, AnimalTypes _type, AnimalEatingHabits _habits, FoodTypes _food, unsigned int _quantity, AnimalHabitat _habitat, const char * _sound)
	: type(_type), eatingHabits(_habits), food(_food), foodQuantity(_quantity), habitat(_habitat) {

	name = new (std::nothrow) char[strlen(_name) + 1];
	if (!name) {

		std::cerr << "There was a problem with allocating memory for our animal's name!\n";
		return;
	}

	strcpy(name, _name);

	sound = new (std::nothrow) char[strlen(_sound) + 1];
	if (!sound) {

		std::cerr << "There was a problem with allocating memory for our animal's sound!\n";
		return;
	}

	strcpy(sound, _sound);
}

Animal::Animal(const Animal & other) {

	copyFrom(other);
}

Animal & Animal::operator=(const Animal & other) {

	if (this != &other) {

		clean();
		copyFrom(other);
	}

	return *this;
}


Animal::~Animal() {

	clean();
}

const char * Animal::getName() const {

	return name;
}

const AnimalTypes Animal::getType() const {

	return type;
}

const AnimalEatingHabits Animal::getEatingHabits() const {

	return eatingHabits;
}

const FoodTypes Animal::getFood() const {

	return food;
}

const unsigned int Animal::getFoodQuantity() const {

	return foodQuantity;
}

const AnimalHabitat Animal::getHabitat() const {

	return habitat;
}

const char * Animal::getSound() const {

	return sound;
}

const char * Animal::eatingHabitsToString() const {

	if (eatingHabits == 1)
		return "carnivor";

	else if (eatingHabits == 0)
		return "herbivor";

	else
		return "undefined eating habits!";
}

const char * Animal::foodToString() const {

	if (food == 0)
		return "meat";

	else if (food == 1)
		return "fish";

	else if (food == 2)
		return "plants";
	
	else
		return "Undefined food type!";
}

const char * Animal::habitatToString() const {

	if (habitat == 0)
		return "Forest";

	else if (habitat == 1)
		return "Savanna";

	else if (habitat == 2)
		return "Jungle";

	else if (habitat == 3)
		return "Arctic Zone";

	else if (habitat == 4)
		return "Aquarium";

	else if (habitat == 5)
		return "Terrarium";

	else
		return "Undefined habitat!";
}

void Animal::clean() {

	delete[] name;
	name = nullptr;

	delete[] sound;
	sound = nullptr;
}

void Animal::copyFrom(const Animal & other) {

	name = new (std::nothrow) char[strlen(other.getName()) + 1];
	if (!name) {

		std::cerr << "There was a problem with allocating memory for our animal's name!\n";
		return;
	}

	strcpy(name, other.getName());

	type = other.getType();
	eatingHabits = other.getEatingHabits();
	food = other.getFood();
	foodQuantity = other.getFoodQuantity();
	habitat = other.getHabitat();

	sound = new (std::nothrow) char[strlen(other.getSound()) + 1];
	if (!sound) {

		std::cerr << "There was a problem with allocating memory for our animal's sound!\n";
		return;
	}

	strcpy(sound, other.getSound());
}