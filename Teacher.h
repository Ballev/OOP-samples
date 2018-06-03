#ifndef __TEACHER_HEADER__
#define __TEACHER_HEADER__

#include "Person.h"

class Teacher : public Person
{

public:

	Teacher(const char*, unsigned short, const char*, const char*);
	Teacher(const Teacher&);
	Teacher& operator=(const Teacher&);
	~Teacher();

public:

	void print();
	void changeSubject(const char*);

private:

	void clean();
	void copyFrom(const Teacher&);

private:

	char* university;
	char* subject;

};

#endif //!__TEACHER_HEADER__