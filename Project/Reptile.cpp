#include "Reptile.h"


Reptile::Reptile() : Animal()
{}

Reptile::Reptile(const char * _name, AnimalEatingHabits _habits, FoodTypes _food, unsigned int _quantity, AnimalHabitat _habitat, const char * _sound)
	: Animal(_name, REPTILE, _habits, _food, _quantity, _habitat, _sound)
{}


Reptile::Reptile(const Reptile & other) : Animal(other)
{}

Reptile & Reptile::operator=(const Reptile & other) {

	Animal::operator=(other);

	return *this;
}

Reptile::~Reptile()
{}

void Reptile::print() {

	std::cout << "Our animal: " << getName() << " is a " << eatingHabitsToString() << " reptile.\nIt eats " <<
		foodToString() << ". It eats " << getFoodQuantity() << " kg of food every day.\n" <<
		"The animal lives in " << habitatToString() << " and produces " << getSound() << " sound.\n";
}
