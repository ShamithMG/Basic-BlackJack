#ifndef GAME_H
#define GAME_H

#include "Player.h"

class Session{

    private:
    double bet_pool_{};
    int    bust_value_{21};
    int    stop_value_{17};

    Player& dealer_;
    Player& player_;

    void PreRound();
    void StartingRound();
    bool MidRound();

    public:
    Session(Player& dealer, Player& player);
    Session(Player& dealer, Player& player, int bust, int stop);

    bool PlayGame();

};





#endif