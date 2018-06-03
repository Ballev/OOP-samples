#include <iostream>

#include "Student.h"


Student::Student(const char* _name, unsigned short _age, const char* _university,
				 const char* _specialty, size_t _fn) : Person(_name, _age), fn(_fn)
{
	university = new char[strlen(_university) + 1];
	if (!university)
	{
		std::cerr << "Not enough memory for creating university name!\n";
		return;
	}
	strcpy(university, _university);
	specialty = new char[strlen(_specialty) + 1];
	if (!specialty)
	{
		std::cerr << "Not enough memory for creating specialty!\n";
		return;
	}
	strcpy(specialty, _specialty);

}

Student::Student(const Student & other) : Person(other)
{
	copyFrom(other);
}

Student & Student::operator=(const Student & other)
{
	if (this != &other)
	{
		clean();
		Person::operator=(other);
		copyFrom(other);
	}
	return *this;
}


Student::~Student()
{
	clean();
}

void Student::print()
{
	Person::print();
	std::cout << "University: " << university << "\n"
		<< "Specialty: " << specialty << "\n"
		<< "Faculty number: " << fn << "\n";
}

void Student::clean()
{
	delete[] university;
	delete[] specialty;
}

void Student::copyFrom(const Student & other)
{
	university = new char[strlen(other.university) + 1];
	if (!university)
	{
		std::cerr << "Not enough memory for copying university name!\n";
		return;
	}
	strcpy(university, other.university);
	specialty = new char[strlen(other.specialty) + 1];
	if (!specialty)
	{
		std::cerr << "Not enough memory for copying specialty!\n";
		return;
	}
	strcpy(specialty, other.specialty);
	fn = other.fn;
}
