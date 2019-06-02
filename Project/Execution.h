#ifndef __EXECITION_HEADER__
#define __EXECITION_HEADER__

#include <iostream>

#include "Cage.h"
#include "Cages.h"
#include "Animal.h"
#include "Bird.h"
#include "Fish.h"
#include "Mammal.h"
#include "Reptile.h"
#include "Storage.h"
#include "Constants.h"
#include "Zoo.h"

void zooOptions();
void animalOptions();
void animalTypeOptions();
void cageTypeOptions();
Animal* chooseAnimal(unsigned int);
void cageOptions();
Cage* chooseCage(unsigned int, bool);
void printAnimal(unsigned int);
void printCage(unsigned int, bool);
void start();

#endif // !__EXECITION_HEADER__