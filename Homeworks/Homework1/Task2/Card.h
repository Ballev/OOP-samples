#ifndef __CARD_HEADER__
#define __CARD_HEADER__

#include <iostream>
#include <fstream>

const size_t MAX_SIZE_NAME = 26;
const size_t MAX_ATT_DEF_POINTS = 5000;
const size_t SIZE_OF_DEFAULT_CARD = 5;

class Card {

public:
	Card();
	// Constructor for Monster.
	Card(const char*, size_t, size_t);
	// Constructor for Magic Card. Sets AP and DP to 0 by default
	Card(const char*);
	Card(const Card&);
	Card& operator=(const Card&);
	~Card();

// Mutators. Some of them are currently not used but they will be usefull for new functionalities.
public:
	void setName(const char*, size_t);
	void setPoints(size_t, size_t);
	const char* getName() const;
	const size_t getAP() const;
	const size_t getDP() const;
	const bool  getIsMonster() const;
	
//Helping function for the serialisation of Deck.
	void serialiseCard(std::ofstream&);
	void deserialiseCard(std::ifstream&);

// Helping function inside of the class.
private:
	void clear();
	void copyFrom(const Card&);
	// Validation, if the AP and DP are less than 5000 and that they are more than 0 or equal to it.
	bool isCorrectPoints(size_t);

private:
	char* name;
	size_t attackP;
	size_t defenceP;
	bool isMonster;

};

#endif // !__CARD_HEADER__