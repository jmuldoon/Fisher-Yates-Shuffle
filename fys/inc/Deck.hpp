#ifndef DECK_HPP
#define DECK_HPP

#include <iostream>
#include <vector>
#include <algorithm>
#include <random>

#include "Card.hpp"

#define MAX_DECK_SIZE 52

class Deck{
public:
	Deck();
	void PrintDeck();		// Prints the entire deck for verification
	void RandShuffleDeck(); // Uses Algorithm/STD::Random_Shuffle
	void FYShuffleDeck();	// Fisher-Yates Shuffle

protected:	
	void SwapElement(const std::vector<Card*>::iterator &, const std::vector<Card*>::iterator &); // Swap elements based on iterators passed in

private:
	std::vector<Card*> pDeck; // Playing deck container
	std::random_device rd;	// Seed with a real random value, if available

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

void Deck::FYShuffleDeck(){
	std::mt19937 rng(rd());	// Use 32-bit Mersenne Twister by Matsumoto and Nishimura, 1998 Algorithm
	std::uniform_int_distribution<int> u_dist(0,MAX_DECK_SIZE-1);	// Default range [0, MAX]

	for(std::vector<Card*>::iterator i = pDeck.begin(), r = pDeck.begin(); i!=pDeck.end();++i){
		r = pDeck.begin()+std::round(u_dist(rng));	// Determine next random index to swap
		SwapElement(i, r); // Swap current index with the randomely generated index
	}
}

void Deck::SwapElement(const std::vector<Card*>::iterator &it1, const std::vector<Card*>::iterator &it2){
	std::iter_swap(it1,it2);
}

void Deck::PrintDeck(){
	for(auto &i: pDeck){
		std::cout<<"Suite: "<<i->getSuite()<<" Value: "<<i->getValue()<<std::endl;
	}
}

#endif //Deck_HPP