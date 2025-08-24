#include "Game.h"
#include "UserInput.h"
#include "Player.h"
#include <iostream>


Session::Session(Player& dealer, Player& player)
    : player_ {player}
    , dealer_ {dealer}
{}

Session::Session(Player& dealer, Player& player, int bust, int stop)
    : player_ {player}
    , dealer_ {dealer}
    , bust_value_ {bust}
    , stop_value_ {stop}
{}
    
static void TableWrapper(Player& player_object, bool unveil = false){
    std::cout << "=============================================\n";
    player_object.displayHand(unveil);
    std::cout << "    -  value : " << player_object.returnValue(unveil); 
    std::cout << "\n=============================================\n";     
}

bool Session::PlayGame(){
    while(true){
        PreRound();
        StartingRound();
        
        if (MidRound()){
            player_.betWon(bet_pool_);
        } else {
            dealer_.betWon(bet_pool_);
        }
        bet_pool_ = 0;

        if(player_.returnBalance() == 0){
            std::cout << "You have no money left to gamble better luck next time\n";
            return false;
        }
        if(dealer_.returnBalance() == 0){
            std::cout << "You won against the house - congratulations";
            return true;
        }
        if (!user::PlayAgain()){break;}
        
    }

    std::cout << "Thanks for playing your balance: " << player_.returnBalance()<<'\n';
    return true; 
}

void Session::PreRound(){
    player_.reset();
    dealer_.reset();
    std::cout << "You have: £" << player_.returnBalance()<<'\n';
    while (true){
        double bet_sum{user::GetBet()};

        if (bet_sum > player_.returnBalance()){
            std::cout << "You do not have enough money to place this bet\n";
            continue;
        }

        player_.bet(bet_sum);
        dealer_.bet(bet_sum);
        bet_pool_ += bet_sum*2;
        return;
    }
}

void Session::StartingRound(){
    std::cout << "The dealer is showing:\n";
    dealer_.hit();
    dealer_.hit();
    TableWrapper(dealer_);
    std::cout << "Your hand: \n";
    player_.hit();
    player_.hit();
    TableWrapper(player_);
}   

bool Session::MidRound(){
    while (user::GetAction() == 'h'){
        player_.hit();
        std::cout << '\n';
        TableWrapper(player_);
        
        if(player_.returnValue() > bust_value_){
            std::cout << "\nYou went bust \n";
            TableWrapper(dealer_, true);
            TableWrapper(player_);
            
            return false;
        }
        else if (player_.returnValue() == bust_value_){
            std::cout << "\nBLACKJACK!\n";
            return true;
        }
    }

    while(true){
        std::cout << "dealer flips:\n"; 
        TableWrapper(dealer_, true);
        while(dealer_.returnValue(true) < stop_value_){
            std::cout << "Dealer draws: \n";
            dealer_.hit();
            TableWrapper(dealer_, true);
        }
        if (dealer_.returnValue(true) > bust_value_){
            std::cout << "You won!\n";
            return true;
        }
        else if(dealer_.returnValue(true) < bust_value_){
            if (dealer_.returnValue(true) > player_.returnValue()){
                std::cout << "You lost!\n";
                return false;
            } else if(dealer_.returnValue(true) < player_.returnValue()){
                std::cout << "You won!\n";
                return true;
            }
            std::cout << "Both the same, equal win\n";
            return true;
        }

        std::cout << "Dealer blackjack! - you lost\n";
        return false;


    }
}