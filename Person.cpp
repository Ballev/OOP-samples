#include <iostream>

#include "Person.h"


Person::Person(const char* _name, unsigned short _age) : age(_age)
{
	name = new char[strlen(_name) + 1];
	if (!name)
	{
		std::cerr << "Not enough memory for creating name!\n";
		return;
	}
	strcpy(name, _name);
}

Person::Person(const Person & other)
{
	copyFrom(other);
}

Person & Person::operator=(const Person & other)
{
	if (this != &other)
	{
		clean();
		copyFrom(other);
	}
	return *this;
}


Person::~Person()
{
	clean();
}

void Person::print()
{
	std::cout << "Name: " << name << "\n"
		<< "Age: " << age << "\n";
}

void Person::clean()
{
	delete[] name;
}

void Person::copyFrom(const Person & other)
{
	name = new char[strlen(other.name) + 1];
	if (!name)
	{
		std::cerr << "Not enough memory for copying name!\n";
		return;
	}
	strcpy(name, other.name);
	age = other.age;
}
