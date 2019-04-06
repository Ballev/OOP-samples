#ifndef __DECK_HEADER__
#define __DECK__HEADER__

#include <iostream>
#include <fstream>

#include "Card.h"

const size_t DEFAULT_SIZE_OF_DECK = 40;

class Deck {

public:
	Deck();
	Deck(const Deck&);
	Deck(const char*);
	Deck& operator=(const Deck&);
	~Deck();

// Functionalities.
public:
	//Method overloading for both scenarious.
	void changeCard(size_t, const char*);
	void changeCard(size_t, const char*, size_t, size_t);
	size_t numberOfMagicCards();
	size_t numberOfMonsters();
	bool serialise(const char*);

// Helping functions.
private:
	void clear();
	void copyFrom(const Deck&);

private:
	Card* cards;

};

#endif // ! __DECK__HEADER__
