#include <iostream>

#include "Teacher.h"



Teacher::Teacher(const char* _name, unsigned short _age,
				 const char* _university , const char* _subject)
	: Person(_name, _age)
{
	university = new char[strlen(_university) + 1];
	if (!university)
	{
		std::cerr << "Not enough memory for creating university name!\n";
		return;
	}
	strcpy(university, _university);
	subject = new char[strlen(_subject) + 1];
	if (!subject)
	{
		std::cerr << "Not enough memory for creating subject name!\n";
		return;
	}
	strcpy(subject, _subject);
}

Teacher::Teacher(const Teacher & other) : Person(other)
{
	copyFrom(other);
}

Teacher & Teacher::operator=(const Teacher & other)
{
	if (this != &other)
	{
		clean();
		Person::operator=(other);
		copyFrom(other);
	}
	return *this;
}


Teacher::~Teacher()
{
	clean();
}

void Teacher::print()
{
	Person::print();
	std::cout << "University: " << university << "\n"
		<< "Subject: " << subject << "\n";
}

void Teacher::changeSubject(const char * newSubject)
{
	delete[] subject;
	subject = new char[strlen(newSubject) + 1];
	if (!subject)
	{
		std::cerr << "Not enough memory for creating subject name!\n";
		return;
	}
	strcpy(subject, newSubject);

}

void Teacher::clean()
{
	delete[] university;
	delete[] subject;
}

void Teacher::copyFrom(const Teacher & other)
{
	university = new char[strlen(other.university) + 1];
	if (!university)
	{
		std::cerr << "Not enough memory for creating university name!\n";
		return;
	}
	strcpy(university, other.university);
	subject = new char[strlen(other.subject) + 1];
	if (!subject)
	{
		std::cerr << "Not enough memory for creating subject name!\n";
		return;
	}
	strcpy(subject, other.subject);
}
