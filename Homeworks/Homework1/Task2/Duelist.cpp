#include "Duelist.h"

Duelist::Duelist(const char * _name) {

	name = new (std::nothrow) char[strlen(_name) + 1];
	
	if (!name) {

		std::cerr << "Problems with allocating memory for name!" << std::endl;
		return;
	}

	strcpy(name, _name);
	
	Deck tempDeck;
	deck = tempDeck;
}

Duelist::~Duelist() {

	clear();
}

void Duelist::changeCardInDeck(size_t position, const char * _name) {

	deck.changeCard(position, _name);
}

void Duelist::changeCardInDeck(size_t position, const char * _name, size_t ap, size_t dp) {

	deck.changeCard(position, _name, ap, dp);
}

size_t Duelist::numberOfMagicCardsInDeck() {

	return deck.numberOfMagicCards();
}

size_t Duelist::numberOfMonstersInDeck() {

	return deck.numberOfMonsters();
}

void Duelist::serialiseDeck(const char * fileName) {

	deck.serialise(fileName);
}

void Duelist::clear() {

	delete[] name;
	name = nullptr;
}
