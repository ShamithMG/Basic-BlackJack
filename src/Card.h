#ifndef CARD_H
#define CARD_H

#include <iostream>
#include <array>

struct Card{

    enum Rank{

        rank_ace, 
        rank_2,
        rank_3, 
        rank_4, 
        rank_5, 
        rank_6, 
        rank_7, 
        rank_8, 
        rank_9, 
        rank_10, 
    
        rank_jack, 
        rank_queen, 
        rank_king,

        max_rank

    };
    static constexpr std::array<Rank, max_rank> allRanks{
        rank_ace, rank_2,rank_3, rank_4, rank_5, rank_6, rank_7, 
        rank_8, rank_9, rank_10, rank_jack, rank_queen, rank_king
    };

    enum Suit{

        suit_club, 
        suit_diamond, 
        suit_heart, 
        suit_spade,

        max_suit
    }; 
    static constexpr std::array<Suit, max_suit> allSuits{
        suit_club, suit_diamond, suit_heart, suit_spade,
    };

    //member variables
    Rank rank {};
    Suit suit {};

    Card() = default;
    Card(Rank rnk, Suit sut)
        : rank {rnk}
        , suit {sut}
    {}

    //value return memberfunction
    int return_value(){
        static constexpr std::array<int, max_rank> cardValue{
            11, 2, 3, 4, 5, 6, 7, 8, 9, 10, 10, 10, 10
        };
        return cardValue[rank];
    }

    //friend functions for operators
    friend std::ostream& operator<<(std::ostream& out,const Card& card){
        static constexpr std::array<char,max_rank> Rank_identifier{
        'A','2','3','4','5','6','7','8','9','T','J','Q','K'
        };
        static constexpr std::array<char,max_suit> Suit_identifier{
        'C','D','H','S'
        };

        out << Rank_identifier[card.rank] << Suit_identifier[card.suit];
        return out;
    }
};


#endif