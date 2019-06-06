#ifndef __CAGES_HEADER__
#define __CAGES_HEADER__

#include <iostream>

#include "Cage.h"

class Forest 
	: public Cage {

public:
	Forest(const char*, const char*, bool);
	~Forest();

	virtual void print();
};

class Savanna
	: public Cage {

public:
	Savanna(const char*, const char*, bool);
	~Savanna();

	virtual void print();
};

class Jungle
	: public Cage {

public:
	Jungle(const char*, const char*, bool);
	~Jungle();

	virtual void print();
};

class ArcticZone
	: public Cage {

public:
	ArcticZone(const char*, const char*, bool);
	~ArcticZone();

	virtual void print();
};

class Aquarium
	: public Cage {

public:
	Aquarium(const char*, const char*, bool);
	~Aquarium();

	virtual void print();
};

class Terrarium
	: public Cage {

public:
	Terrarium(const char*, const char*, bool);
	~Terrarium();

	virtual void print();
};

#endif // !__CAGES_HEADER__
