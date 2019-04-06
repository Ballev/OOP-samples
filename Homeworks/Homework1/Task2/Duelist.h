#ifndef __DUELIST_HEADER__
#define __DUELIST_HEADER__

#include <iostream>
#include <fstream>

#include "Card.h"
#include "Deck.h"

class Duelist {

public:
	// Duelists are unique marvelous people so they can not be copied or equalised. They also as all man need a name
	// to exist so the default constructor is not good for them.
	Duelist(const char*);
	Duelist(const Duelist&) = delete;
	Duelist& operator=(const Duelist&) = delete;
	~Duelist();

public:
	//Method overloading for both scenarious.
	void changeCardInDeck(size_t, const char*);
	void changeCardInDeck(size_t, const char*, size_t, size_t);

	size_t numberOfMagicCardsInDeck();
	size_t numberOfMonstersInDeck();
	void serialiseDeck(const char*);

private:
	void clear();

private:
	char* name;
	Deck deck;

};

#endif // !__DUELIST_HEADER__
