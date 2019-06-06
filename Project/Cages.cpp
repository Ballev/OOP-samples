#include "Cages.h"


Forest::Forest(const char* _name, const char * _location, bool _eatsMeat)
	: Cage("_name", 45, 85, FORESTY, _location, _eatsMeat, FOREST)
{}

Forest::~Forest()
{}

void Forest::print() {

	std::cout << "The cage " << getName() << " is a Forest.\nThe humidity in the forest is " << getHumidity()
		<< "% and the flora around in the cage is " << getFlora() << "%. The cage's terrain is " << terrainToString()
		<< ".\n The cage is located on " << getLocation() << " and is used for animals that " << isForMeatEatersToString()
		<< std::endl << std::endl;
}


Savanna::Savanna(const char* _name, const char * _location, bool _eatsMeat)
	: Cage(_name, 30, 50, HILLS, _location, _eatsMeat, SAVANNA)
{}

Savanna::~Savanna()
{}

void Savanna::print() {

	std::cout << "The cage " << getName() << " is a Savanna.\nThe humidity in the forest is " << getHumidity()
		<< "% and the flora around in the cage is " << getFlora() << "%. The cage's terrain is " << terrainToString()
		<< ".\n The cage is located on " << getLocation() << " and is used for animals that " << isForMeatEatersToString()
		<< std::endl << std::endl;
}


Jungle::Jungle(const char* _name, const char * _location, bool _eatsMeat)
	: Cage(_name, 76, 98, FORESTY, _location, _eatsMeat, JUNGLE)
{}

Jungle::~Jungle()
{}

void Jungle::print() {

	std::cout << "The cage " << getName() << " is a Jungle.\nThe humidity in the forest is " << getHumidity()
		<< "% and the flora around in the cage is " << getFlora() << "%. The cage's terrain is " << terrainToString()
		<< ".\n The cage is located on " << getLocation() << " and is used for animals that " << isForMeatEatersToString()
		<< std::endl << std::endl;
}


ArcticZone::ArcticZone(const char* _name, const char * _location, bool _eatsMeat)
	: Cage(_name, 55, 0, WATER, _location, _eatsMeat, ARCTICZONE)
{}

ArcticZone::~ArcticZone()
{}

void ArcticZone::print() {

	std::cout << "The cage " << getName() << " is an Arctic Zone.\nThe humidity in the forest is " << getHumidity()
		<< "% and the flora around in the cage is " << getFlora() << "%. The cage's terrain is " << terrainToString()
		<< ".\n The cage is located on " << getLocation() << " and is used for animals that " << isForMeatEatersToString()
		<< std::endl << std::endl;
}


Aquarium::Aquarium(const char* _name, const char * _location, bool _eatsMeat)
	: Cage(_name, 100, 25, WATER, _location, _eatsMeat, AQUARIUM)
{}

Aquarium::~Aquarium()
{}

void Aquarium::print() {

	std::cout << "The cage " << getName() << " is an Aquarium.\nThe humidity in the forest is " << getHumidity()
		<< "% and the flora around in the cage is " << getFlora() << "%. The cage's terrain is " << terrainToString()
		<< ".\n The cage is located on " << getLocation() << " and is used for animals that " << isForMeatEatersToString()
		<< std::endl << std::endl;
}


Terrarium::Terrarium(const char* _name, const char * _location, bool _eatsMeat)
	: Cage(_name, 55, 30, HILLS, _location, _eatsMeat, TERRARIUM)
{}

Terrarium::~Terrarium()
{}

void Terrarium::print() {

	std::cout << "The cage " << getName() << " is a Terrarium.\nThe humidity in the forest is " << getHumidity()
		<< "% and the flora around in the cage is " << getFlora() << "%. The cage's terrain is " << terrainToString()
		<< ".\n The cage is located on " << getLocation() << " and is used for animals that " << isForMeatEatersToString()
		<< std::endl << std::endl;
}
