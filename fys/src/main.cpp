#include "Deck.hpp"

int main(void) {
    Deck *nDeck = new Deck();

    std::cout<<"---\tGenerate Deck\t---"<<std::endl;
    nDeck->PrintDeck();

    std::cout<<"---\tSTD Random Shuffle\t---"<<std::endl;
    nDeck->RandShuffleDeck();
    nDeck->PrintDeck();

    std::cout<<"---\tFisher-Yates Shuffle\t---"<<std::endl;
    nDeck->FYShuffleDeck();
    nDeck->PrintDeck();

    return 0;
}
