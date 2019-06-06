#include "Bird.h"


Bird::Bird(const char * _name, AnimalEatingHabits _habits, FoodTypes _food, unsigned int _quantity, AnimalHabitat _habitat, const char * _sound)
	: Animal(_name, BIRD, _habits, _food, _quantity, _habitat, _sound)
{}

Bird::~Bird()
{}

void Bird::print() {

	std::cout << "Our animal: " << getName() << " is a " << eatingHabitsToString() << " bird.\nIt eats " <<
		foodToString() << ". It eats " << getFoodQuantity() << " kg of food every day.\n" <<
		"The animal lives in " << habitatToString() << " and produces " << getSound() << " sound.\n";
}

Animal* Bird::clone(){
	
	return new Bird(*this);
}
