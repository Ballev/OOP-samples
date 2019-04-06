#include "Card.h"

Card::Card() : attackP(0), defenceP(0), isMonster(true) {

	setName("Token", SIZE_OF_DEFAULT_CARD);
}

Card::Card(const char * _name, size_t ap, size_t dp) : isMonster(true) {

	setPoints(ap, dp);
	size_t lenOfName = strlen(_name);
	setName(_name, lenOfName);
}

Card::Card(const char * _name) : attackP(0), defenceP(0), isMonster(false) {

	size_t lenOfName = strlen(_name);
	setName(_name, lenOfName);
}

Card::Card(const Card & other) {

	copyFrom(other);
}

Card & Card::operator=(const Card & other) {

	if (this != &other) {

		clear();
		copyFrom(other);
	}

	return *this;
}

Card::~Card() {

	clear();
}

void Card::setName(const char * _name, size_t lenOfName) {

	name = new (std::nothrow) char[lenOfName + 1];
	
	if (!name) {

		std::cerr << "Problems with allocating memory for name!" << std::endl;
		return;
	}

	strcpy(name, _name);
}

void Card::setPoints(size_t ap, size_t dp) {

	if (isCorrectPoints(ap) && isCorrectPoints(dp)) {

		attackP = ap;
		defenceP = dp;
	}

	else {

		std::cerr << "You have chosen unrealistic points. Please repeat the last operation with"
			      << "points less than 5000 and more than 0 for AP and DP" << std::endl;
		return;
	}
}

const char * Card::getName() const {

	return name;
}

const size_t Card::getAP() const {

	return attackP;
}

const size_t Card::getDP() const {

	return defenceP;
}

const bool Card::getIsMonster() const
{
	return isMonster;
}

void Card::serialiseCard(std::ofstream& oFile) {

	size_t len = strlen(name);

	oFile.write((const char*)&len, sizeof(size_t));
	oFile.write(name, len);
	oFile.write((const char*)&attackP, sizeof(size_t));
	oFile.write((const char*)&defenceP, sizeof(size_t));
	oFile.write((const char*)&isMonster, sizeof(bool));
}

void Card::deserialiseCard(std::ifstream & iFile) {

	size_t len = 0;
	iFile.read((char*)&len, sizeof(size_t));
	
	if (name != nullptr)
		delete[] name;

	name = new char[len + 1];
	if (!name) {

		std::cerr << "Problems with allocating memory for name!" << std::endl;
		return;
	}

	iFile.read(name, len);
	name[len] = '\0';

	iFile.read((char*)&attackP, sizeof(size_t));
	iFile.read((char*)&defenceP, sizeof(size_t));
	iFile.read((char*)&isMonster, sizeof(bool));	
}


void Card::clear() {

	delete[] name;
	name = nullptr;
	attackP = 0;
	defenceP = 0;
	isMonster = 0;
}

void Card::copyFrom(const Card & other) {

	size_t lenOfName = strlen(other.getName());
	
	setName(other.getName(), lenOfName);
	setPoints(other.getAP(), other.getDP());
	isMonster = other.getIsMonster();
}

bool Card::isCorrectPoints(size_t points) {

	if(points > MAX_ATT_DEF_POINTS)
		return false;

	return true;
}
