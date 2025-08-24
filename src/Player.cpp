#include "Player.h"
#include "Deck.h"

#include <iostream>

Player::Player(Deck* deck)
    : current_deck_ {deck}
{

}

Player::Player(Deck* deck, bool dealer = true)
    : current_deck_{deck}
    , player_hand_{}
    , player_bank_{1000000000}
    , dealer{dealer}
{
}

void Player::hit(){
    if(!current_deck_){
        std::cout << "No current deck";
    }
    Card& dealt_card = current_deck_ -> dealCard();
    player_hand_.emplace_back(dealt_card);
    player_value_ += dealt_card.return_value();

}

void Player::betWon(double amount){
    player_bank_ += amount;
}

void Player::displayHand(bool unveil){
    bool firstpass{true};
    for (auto card : player_hand_){
        if (firstpass && dealer && !unveil){
            std::cout << "XX";
            firstpass = false;
            continue;
        } else if (firstpass){
            std::cout << card;
            firstpass = false;
            continue;
        }

        std::cout << " , " << card;

    }   
}

int Player::returnValue(bool unveil){
    if (dealer && !unveil){
        return (player_value_ - player_hand_[0].get().return_value());
    } else {
        return player_value_;
    }
}

void Player::bet(double amount){
    player_bank_ -= amount;
}

void Player::reset(){
    player_hand_.clear();
    player_value_ = 0;
}