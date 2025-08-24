#include "Deck.h"
#include "Player.h"
#include "Game.h"

#include <iostream>


int main()
{
    Deck game_deck{};
    game_deck.shuffle();

    Player dealer{&game_deck, true};
    Player player1{&game_deck};

    Session game{dealer, player1};
    std::cout << "-----------------------------------\n";
    std::cout << "WELCOME TO BLACKJACK!\n";
    std::cout << "-----------------------------------\n";
    game.PlayGame();

    return 0;
}