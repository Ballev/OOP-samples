#ifndef __STUDENT_HEADER__
#define __STUDENT_HEADER__

#include "Person.h"

class Student : public Person
{

public:

	Student(const char*, unsigned short, const char*, const char*, size_t);
	Student(const Student&);
	Student& operator=(const Student&);
	~Student();

public:

	void print();

private:

	void clean();
	void copyFrom(const Student&);

private:

	char* university;
	char* specialty;
	size_t fn;

};

#endif // !__STUDENT_HEADER__