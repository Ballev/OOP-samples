#include "Execution.h"

void zooOptions() {

	std::cout << "You are welcome to our new zoo!\nYou can choose one of the following options:\n"
		<< "\tFor adding new Animal click 1.\n"
		<< "\tFor feeding the existing Animals click 2.\n"
		<< "\tFor filling the resourses in the storage click 3.\n"
		<< "\tFor adding new cage click 4.\n"
		<< "\tFor receiving information for an animal click 5.\n"
		<< "\tFor receiving information of some of the cages click 6.\n"
		<< "\tFor exit click 0.\n"
		<< "\tPlease, choose one of the options above now!\n\n";
}

void animalOptions() {

	std::cout << "You have chosen to add new animal!\nYou can choose one of the following options:\n"
		<< "\tFor adding new Wolf click 1.\n"
		<< "\tFor adding new Rhino click 2.\n"
		<< "\tFor adding new Eagle click 3.\n"
		<< "\tFor adding new Penguin click 4.\n"
		<< "\tFor adding new Aligator click 5.\n"
		<< "\tFor adding new Lizard click 6.\n"
		<< "\tFor adding new Shark click 7.\n"
		<< "\tFor adding new Plankton click 8.\n"
		<< "\tFor exit click 0.\n"
		<< "\tPlease, choose one of the options above now!\n\n";
}

void animalTypeOptions() {

	std::cout << "You have chosen to view the information of an animal type!\nYou can choose one of the following options:\n"
		<< "\tFor seeing the information for Wolf click 1.\n"
		<< "\tFor seeing the information for Rhino click 2.\n"
		<< "\tFor seeing the information for Eagle click 3.\n"
		<< "\tFor seeing the information for Penguin click 4.\n"
		<< "\tFor seeing the information for Aligator click 5.\n"
		<< "\tFor seeing the information for Lizard click 6.\n"
		<< "\tFor seeing the information for Shark click 7.\n"
		<< "\tFor seeing the information for Plankton click 8.\n"
		<< "\tFor exit click 0.\n"
		<< "\tPlease, choose one of the options above now!\n\n";
}

void cageTypeOptions() {

	std::cout << "You have chosen to view the information for a cage!\nYou can choose one of the following options:\n"
		<< "\tFor viewing the information for a Forest click 1.\n"
		<< "\tFor viewing the information for a Savanna click 2.\n"
		<< "\tFor viewing the information for a Jungle click 3.\n"
		<< "\tFor viewing the information for a ArcticZone click 4.\n"
		<< "\tFor viewing the information for a Aquarium click 5.\n"
		<< "\tFor viewing the information for a Terarium click 6.\n"
		<< "\tFor exit click 0.\n"
		<< "\tPlease, choose one of the options above now!\n\n";
}

Animal* chooseAnimal( unsigned int chosen) {

	Animal* temp;

	switch (chosen) {

	case 1: temp = new Mammal("Wolf", CARNIVOR, MEAT, 3, FOREST, "auuu");
		break;
	case 2: temp = new Mammal("Rhino", HERBIVOR, PLANTS, 5, SAVANNA, "muuu");
		break;
	case 3: temp = new Bird("Eagle", CARNIVOR, MEAT, 2, FOREST, "iiii");
		break;
	case 4: temp = new Bird("Penguin", CARNIVOR, FISH, 2, ARCTICZONE, "pi pi");
		break;
	case 5: temp = new Reptile("Aligator", CARNIVOR, MEAT, 10, SAVANNA, "blqh");
		break;
	case 6: temp = new Reptile("Lizard", CARNIVOR, MEAT, 1, TERRARIUM, "auuu");
		break;
	case 7: temp = new Mammal("Shark", CARNIVOR, FISH, 15, AQUARIUM, "sonar");
		break;
	case 8: temp = new Mammal("Plankton", HERBIVOR, PLANTS, 1, AQUARIUM, "cyr");
		break;
	default:
		break;
	}

	return temp;
}

void cageOptions() {

	std::cout << "You have chosen to add new cage!\nYou can choose one of the following options:\n"
		<< "\tFor adding new Forest click 1.\n"
		<< "\tFor adding new Savanna click 2.\n"
		<< "\tFor adding new Jungle click 3.\n"
		<< "\tFor adding new ArcticZone click 4.\n"
		<< "\tFor adding new Aquarium click 5.\n"
		<< "\tFor adding new Terarium click 6.\n"
		<< "\tFor exit click 0.\n"
		<< "\tPlease, choose one of the options above now!\n\n";
}

Cage * chooseCage(unsigned int chosen, bool isForMeatEaters)
{
	Cage* temp;

	switch (chosen) {

	case 1: temp = new Forest("Forest", "90 south", isForMeatEaters);
		break;
	case 2: temp = new Savanna("Savanna", "20 south", isForMeatEaters);
		break;
	case 3: temp = new Jungle("Jungle", "5 south", isForMeatEaters);
		break;
	case 4: temp = new ArcticZone("Arctic Zone", "90 north", isForMeatEaters);
		break;
	case 5: temp = new Aquarium("Aquarium", "44 south", isForMeatEaters);
		break;
	case 6: temp = new Terrarium("Terrarium", "33 north", isForMeatEaters);
		break;
	default:
		break;
	}

	return temp;
}

void printAnimal(unsigned int chosen) {

	Animal* temp;

	switch (chosen) {

	case 1: temp = new Mammal("Wolf", CARNIVOR, MEAT, 3, FOREST, "auuu");
		break;
	case 2: temp = new Mammal("Rhino", HERBIVOR, PLANTS, 5, SAVANNA, "muuu");
		break;
	case 3: temp = new Bird("Eagle", CARNIVOR, MEAT, 2, FOREST, "iiii");
		break;
	case 4: temp = new Bird("Penguin", CARNIVOR, FISH, 2, ARCTICZONE, "pi pi");
		break;
	case 5: temp = new Reptile("Aligator", CARNIVOR, MEAT, 10, SAVANNA, "blqh");
		break;
	case 6: temp = new Reptile("Lizard", CARNIVOR, MEAT, 1, TERRARIUM, "auuu");
		break;
	case 7: temp = new Mammal("Shark", CARNIVOR, FISH, 15, AQUARIUM, "sonar");
		break;
	case 8: temp = new Mammal("Plankton", HERBIVOR, PLANTS, 1, AQUARIUM, "cyr");
		break;
	default:
		break;
	}

	temp->print();

	delete[] temp;
}

void printCage(unsigned int chosen, bool isForMeatEaters) {

	Cage* temp;

	switch (chosen) {

	case 1: temp = new Forest("Forest", "90 south", isForMeatEaters);
		break;
	case 2: temp = new Savanna("Savanna", "20 south", isForMeatEaters);
		break;
	case 3: temp = new Jungle("Jungle", "5 south", isForMeatEaters);
		break;
	case 4: temp = new ArcticZone("Arctic Zone", "90 north", isForMeatEaters);
		break;
	case 5: temp = new Aquarium("Aquarium", "44 south", isForMeatEaters);
		break;
	case 6: temp = new Terrarium("Terrarium", "33 north", isForMeatEaters);
		break;
	default:
		break;
	}

	temp->print();

	delete[] temp;
}

void start() {

	Zoo zoo("Zooparka");

	unsigned int option = 0;
	
	do {

		zooOptions();

		std::cin >> option;

		if (option > 6 || option < 0) {
			
			std::cout << "You have chosen unexisting option. Please, choose again!\n\n";
			continue;
		}

		if (option == 1) {

			unsigned int option2 = 0;
			animalOptions();

			std::cin >> option2;
			if (option2 <= 8) {

				zoo.addAnimal(chooseAnimal(option2));

				std::cout << "Our animal was added successfully!\n\n";
			}

			else
				std::cout << "No such animal to be added!\n\n";
		}

		else if (option == 2) {

			zoo.feedAnimals();
			std::cout << "Animals were successfully fed.\n\n";
		}

		else if (option == 3) {

			zoo.fillStorage();
			std::cout << "Storage was successfully filled.\n\n";
		}

		else if (option == 4) {

			unsigned int option2 = 0;
			bool isEatingMeat = 0;
			cageOptions();

			std::cin >> option2;

			std::cout << "Choose, if the cage is for eat meaters on not:\n"
				<< "1. 0 for vegetarians.\n2. 1 for meat eaters.\n\n";
			std::cin >> isEatingMeat;
			
			if (option2 <= 6) {

				zoo.createCage(chooseCage(option2, isEatingMeat));

				std::cout << "Our cage was added successfully!\n\n";
			}
			else
				std::cout << "No such cage to be added!\n\n";
		}

		else if (option == 5) {

			unsigned int option2 = 0;

			animalTypeOptions();
			
			std::cin >> option2;
			
			if (option <= 8) {
				
				printAnimal(option2);
			}

			else
				std::cout << "No such animal to be printed!\n\n";
		}

		else if (option == 6) {

			unsigned int option2 = 0;
			bool isEatingMeat = 0;
			cageTypeOptions();

			std::cin >> option2;

			std::cout << "Choose, if the cage is for eat meaters on not:\n"
				<< "1. 0 for vegetarians.\n2. 1 for meat eaters.\n\n";
			std::cin >> isEatingMeat;

			if (option2 <= 6) {

				printCage(option2, isEatingMeat);
			}
			else
				std::cout << "No such cage to be printed!\n\n";
		}

	} while (option != 0);
}
