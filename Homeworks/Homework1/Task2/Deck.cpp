#include "Deck.h"

Deck::Deck() {

	cards = new (std::nothrow) Card[DEFAULT_SIZE_OF_DECK];
	if (!cards) {

		std::cerr << "There were problems with allocating memory for the cards!" << std::endl;
		return;
	}

	Card tempCard;

	for (size_t i = 0; i < DEFAULT_SIZE_OF_DECK; ++i) {

		cards[i] = tempCard;
	}
}

Deck::Deck(const Deck & other) {

	copyFrom(other);
}

Deck::Deck(const char * fileName) {

	std::ifstream iFile;
	iFile.open(fileName, std::ios::binary);

	if (!iFile.good()) {

		std::cerr << "There was some problems with opening your file!" << std::endl;
		return;
	}

	cards = new (std::nothrow) Card[DEFAULT_SIZE_OF_DECK];

	if (!cards) {

		std::cerr << "There were problems with allocating memory for the cards!" << std::endl;
		return;
	}

	for (size_t i = 0; i < DEFAULT_SIZE_OF_DECK; ++i)
		cards[i].deserialiseCard(iFile);

	if (!iFile) {

		std::cerr << "Error occurred while reading from the file!" << std::endl;
		return;
	}
			
	iFile.close();
}

Deck & Deck::operator=(const Deck & other) {

	if (this != &other) {

		clear();
		copyFrom(other);
	}

	return *this;
}

Deck::~Deck() {

	clear();
}

void Deck::changeCard(size_t position, const char * _name) {

	if (position >= DEFAULT_SIZE_OF_DECK) {

		std::cerr << "You have chosen an unexisting position!"
				  << "Please repeat the process with position between 0 and 39!" << std::endl;
		return;
	}

	Card temp(_name);
	cards[position] = temp;
}

void Deck::changeCard(size_t position, const char * _name, size_t ap, size_t dp) {

	if (position >= DEFAULT_SIZE_OF_DECK) {

		std::cerr << "You have chosen an unexisting position!"
			<< "Please repeat the process with position between 0 and 39!" << std::endl;
		return;
	}

	Card temp(_name, ap, dp);
	cards[position] = temp;
}

size_t Deck::numberOfMagicCards() {

	size_t cnt = 0;
	
	for (size_t i = 0; i < DEFAULT_SIZE_OF_DECK; ++i) {

		if (!cards[i].getIsMonster())
			++cnt;
	}

	return cnt;
}

size_t Deck::numberOfMonsters() {

	size_t cnt = 0;

	for (size_t i = 0; i < DEFAULT_SIZE_OF_DECK; ++i) {

		if (cards[i].getIsMonster())
			++cnt;
	}

	return cnt;
}

bool Deck::serialise(const char * fileName) {

	std::ofstream oFile;
	oFile.open(fileName, std::ios::binary | std::ios::trunc);

	if (!oFile.good()) {

		std::cerr << "There was some problems with opening your file!" << std::endl;
		return false;
	}

	for (size_t i = 0; i < DEFAULT_SIZE_OF_DECK; ++i)
		cards[i].serialiseCard(oFile);

	if (!oFile.good()) {
		
		std::cerr << "Error occurred while writing the file!" << std::endl;
		return false;
	}

	oFile.close();
	
	return true;
}

void Deck::clear() {

	delete[] cards;
	cards = nullptr;
}

void Deck::copyFrom(const Deck & other) {

	cards = new (std::nothrow) Card[DEFAULT_SIZE_OF_DECK];
	
	if (!cards) {

		std::cerr << "There were problems with allocating memory for the cards!";
		return;
	}

	for (size_t i = 0; i < DEFAULT_SIZE_OF_DECK; ++i)
		cards[i] = other.cards[i];
}
