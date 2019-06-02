#ifndef __CAGES_HEADER__
#define __CAGES_HEADER__

#include <iostream>

#include "Cage.h"

class Forest 
	: public Cage {

public:
	Forest(const char*, const char*, bool);
	Forest(const Forest&);
	Forest& operator=(const Forest&);
	~Forest();

	virtual void print();
};

class Savanna
	: public Cage {

public:
	Savanna(const char*, const char*, bool);
	Savanna(const Savanna&);
	Savanna& operator=(const Savanna&);
	~Savanna();

	virtual void print();
};

class Jungle
	: public Cage {

public:
	Jungle(const char*, const char*, bool);
	Jungle(const Jungle&);
	Jungle& operator=(const Jungle&);
	~Jungle();

	virtual void print();
};

class ArcticZone
	: public Cage {

public:
	ArcticZone(const char*, const char*, bool);
	ArcticZone(const ArcticZone&);
	ArcticZone& operator=(const ArcticZone&);
	~ArcticZone();

	virtual void print();
};

class Aquarium
	: public Cage {

public:
	Aquarium(const char*, const char*, bool);
	Aquarium(const Aquarium&);
	Aquarium& operator=(const Aquarium&);
	~Aquarium();

	virtual void print();
};

class Terrarium
	: public Cage {

public:
	Terrarium(const char*, const char*, bool);
	Terrarium(const Terrarium&);
	Terrarium& operator=(const Terrarium&);
	~Terrarium();

	virtual void print();
};

#endif // !__CAGES_HEADER__