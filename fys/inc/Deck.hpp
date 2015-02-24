#ifndef DECK_HPP
#define DECK_HPP

#include <iostream>
#include <vector>
#include <algorithm>

#include "Card.hpp"

class Deck{
public:
	Deck();
	void PrintDeck();		// Prints the entire deck for verification
	void RandShuffleDeck(); // Uses Algorithm/STD::Random_Shuffle
	void FYShuffleDeck();	// Fisher-Yates Shuffle
	void XORSwap();			// XOR Swap

private:
	std::vector<Card*> pDeck;
};

Deck::Deck(){
	// initialize deck
	for(int i = 1; i<=13; ++i){
		pDeck.push_back(new Card(CLUBS, (value_t)i));
		pDeck.push_back(new Card(DIAMONDS, (value_t)i));
		pDeck.push_back(new Card(HEARTS, (value_t)i));
		pDeck.push_back(new Card(SPADES, (value_t)i));
	}
}

void Deck::RandShuffleDeck(){
	std::random_shuffle(pDeck.begin(),pDeck.end());
}

void Deck::XORSwap(){
	
}

void Deck::PrintDeck(){
	for(auto &i: pDeck){
		std::cout<<"Suite: "<<i->getSuite()<<" Value: "<<i->getValue()<<std::endl;
	}
}

#endif //Deck_HPP