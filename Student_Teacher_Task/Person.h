#ifndef __PERSON_HEADER__
#define __PERSON_HEADER__

class Person
{

public:

	Person(const char*, unsigned short);
	Person(const Person&);
	Person& operator=(const Person&);
	~Person();

public:

	void print();

private:

	void clean();
	void copyFrom(const Person&);

private:

	char* name;
	unsigned short age;

};

#endif // !__PERSON_HEADER__