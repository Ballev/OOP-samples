#include "Mammal.h"


Mammal::Mammal(const char * _name, AnimalEatingHabits _habits, FoodTypes _food, unsigned int _quantity, AnimalHabitat _habitat, const char * _sound)
	: Animal(_name, MAMMAL, _habits, _food, _quantity, _habitat, _sound)
{}

Mammal::~Mammal()
{}

void Mammal::print() {

	std::cout << "Our animal: " << getName() << " is a " << eatingHabitsToString() << " mammal.\nIt eats " <<
		foodToString() << ". It eats " << getFoodQuantity() << " kg of food every day.\n" <<
		"The animal lives in " << habitatToString() << " and produces " << getSound() << " sound.\n";
}

Animal* Mammal::clone(){
	
	return new Mammal(*this);
}
