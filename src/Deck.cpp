#include "Deck.h"
#include "Card.h"
#include "Random.h"
#include <array>
#include <cassert>
#include <algorithm>

std::size_t Deck::current_card_{0};

Deck::Deck()
{
    int i{0};
    for (Card::Suit suit: Card::allSuits){
        for (Card::Rank rank : Card::allRanks){
            standard_deck_[i++] = Card{rank, suit};
        }
    }
}

void Deck::shuffle(){
    std::shuffle(standard_deck_.begin(), standard_deck_.end(), Random::mt);
}

void Deck::reset(){
    current_card_ = 0;
}

Card& Deck::dealCard(){
    assert(current_card_ < 52);
    return standard_deck_[current_card_++];
}