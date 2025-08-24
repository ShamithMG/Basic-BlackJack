#ifndef DECK_H
#define DECK_H

#include "Card.h"
#include <array>

class Deck{

    private:
    std::array<Card, 52> standard_deck_{};
    static std::size_t current_card_;

    public:
    Deck();

    //member functions
    Card& dealCard();
    void shuffle();
    void reset();

};



#endif