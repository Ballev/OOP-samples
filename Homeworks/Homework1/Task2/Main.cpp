#include <iostream>
#include <fstream>

#include "Card.h"
//#include "Deck.h"
#include "Duelist.h"

int main() {

	Deck deck;
	std::cout << deck.numberOfMonsters() << " " << deck.numberOfMagicCards() << std::endl;
	deck.changeCard(2, "Ai siktir");
	deck.changeCard(4, "Blue-eyes white dragon", 3000, 2500);
	deck.changeCard(33, "Karakorum");
	std::cout << deck.numberOfMonsters() << " " << deck.numberOfMagicCards() << std::endl;
	deck.serialise("test.bin");

	Deck deck2("test.bin");
	deck2.changeCard(12, "Dsd");
	std::cout << deck2.numberOfMonsters() << " " << deck2.numberOfMagicCards() << std::endl;

	Duelist player("Kolio");
	player.changeCardInDeck(8, "Dere");
	player.changeCardInDeck(9, "Laguna");
	player.changeCardInDeck(10, "Lakmus");
	player.serialiseDeck("test3.bin");
	std::cout << player.numberOfMonstersInDeck() << " " << player.numberOfMagicCardsInDeck() << std::endl;
	
	return 0;
}
