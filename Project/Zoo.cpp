#include "Zoo.h"


Zoo::Zoo(const char * _name) : cages(nullptr), curSize(0) {

	name = new (std::nothrow) char[strlen(_name) + 1];
	if (!name) {

		std::cerr << "There was a problem with allocating memory for our animal's name!\n";
		return;
	}

	strcpy(name, _name);
}

Zoo::~Zoo() {

	clean();
}

bool Zoo::addAnimal(Animal * _animal) {

	for (size_t i = 0; i < curSize; ++i) {

		if (_animal->getEatingHabits() == CARNIVOR && cages[i]->getIsForMeatEaters()
			&& _animal->getHabitat() == cages[i]->getHabitat()) {

			cages[i]->addAnimal(_animal);
			if (_animal->getFood() == MEAT) {

				storage.setNeededMeat(_animal->getFoodQuantity() + storage.getNeededMeat());
			}
			else if (_animal->getFood() == FISH) {

				storage.setNeededFish(_animal->getFoodQuantity() + storage.getNeededFish());
			}

			return true;
		}

		else if (_animal->getEatingHabits() == HERBIVOR && (!cages[i]->getIsForMeatEaters())
			&& _animal->getHabitat() == cages[i]->getHabitat()) {

			cages[i]->addAnimal(_animal);

			if (_animal->getFood() == PLANTS) {

				storage.setNeededPlants(_animal->getFoodQuantity() + storage.getNeededPlants());
			}

			return true;
		}
	}

	std::cout << "There is no suitable location for our Animal!";
	return false;
}

bool Zoo::feedAnimals() {

	if (!storage.isAbleToFeedTheAnimals()) {

		std::cout << "Not enough food in the storage to feed the animals!\n";
	
		return false;
	}

	storage.setFish(storage.getFish() - storage.getNeededFish());
	storage.setMeat(storage.getMeat() - storage.getNeededMeat());
	storage.setPlants(storage.getPlants() - storage.getNeededPlants());

	std::cout << "The animals have been fed successfully.\n";
	
	return true;
}

void Zoo::fillStorage() {

	storage.setMeat(storage.getNeededMeat());
	storage.setFish(storage.getNeededFish());
	storage.setPlants(storage.getNeededPlants());

	std::cout << "The storage was succeessfully refilled.\n";
}

void Zoo::createCage(Cage* _cage) {

	Cage** temp = new (std::nothrow) Cage*[curSize + 1];
	if (!temp) {

		std::cerr << "There was a problem with allocating memory for our new cage!\n";
		return;
	}
	
	for (size_t i = 0; i < curSize; ++i) {

		temp[i] = cages[i];
	}

	temp[curSize++] = _cage;

	delete[] cages;

	cages = temp;
}

void Zoo::printCageInfo(size_t pos) {

	cages[pos]->print();
}

void Zoo::clean() {

	delete[] name;
	name = nullptr;

	for (size_t i = 0; i < curSize; ++i) {

		delete cages[i];
	}

	delete[] cages;
	cages = nullptr;

	curSize = 0;
}
