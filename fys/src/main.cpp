#include "Deck.hpp"

int main(void) {
    Deck *nDeck = new Deck();

    std::cout<<"---\tGenerate Deck\t---"<<std::endl;
    nDeck->PrintDeck();

    std::cout<<"---\tSTD Random Shuffle\t---"<<std::endl;
    nDeck->RandShuffleDeck();
    nDeck->PrintDeck();

    Deck *nFysDeck = new Deck();
    std::cout<<"---\tGenerate Deck\t---"<<std::endl;
    nFysDeck->PrintDeck();

    std::cout<<"---\tFisher-Yates Shuffle\t---"<<std::endl;
    nFysDeck->FYShuffleDeck();
    nFysDeck->PrintDeck();

    return 0;
}
