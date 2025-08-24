#ifndef PLAYER_H
#define PLAYER_H

#include "Card.h"
#include "Deck.h"
#include <vector>
#include <utility>

class Player {

    private: 
    std::vector<std::reference_wrapper<Card>> player_hand_{};
    Deck*                                     current_deck_{nullptr};
    int                                       player_value_{};
    double                                    player_bank_{1000};
    bool                                      dealer{false};

    public:
    Player(Deck* deck);
    Player(Deck* deck,bool dealer);

    void bet(double amount);
    void betWon(double amount);
    void hit();
    void stand();

    void displayHand(bool unveil = false);
    int returnValue(bool unveil = false);
    void reset();
    
    double returnBalance() {return player_bank_;}
};




#endif