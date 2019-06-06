#include "Fish.h"


Fish::Fish(const char * _name, AnimalEatingHabits _habits, FoodTypes _food, unsigned int _quantity, AnimalHabitat _habitat, const char * _sound)
	: Animal(_name, FISHES, _habits, _food, _quantity, _habitat, _sound)
{}

Fish::~Fish()
{}

void Fish::print() {

	std::cout << "Our animal: " << getName() << " is a " << eatingHabitsToString() << " fish.\nIt eats " <<
		foodToString() << ". It eats " << getFoodQuantity() << " kg of food every day.\n" <<
		"The animal lives in " << habitatToString() << " and produces " << getSound() << " sound.\n";
}

Animal* Fish::clone(){
	
	return new Fish(*this);
}
