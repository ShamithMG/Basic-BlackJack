#include "UserInput.h"
#include <iostream>
#include <limits>

static void ClearInput(){
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

   
namespace user{
    
    char GetAction(){
        while(true){
            std::cout << "(h) to hit, (s) to stand: ";
            char inp{};
            std::cin >> inp;
            
            if(!std::cin){
                std::cout << "Invalid input - please try again: ";
                std::cin.clear();
                ClearInput();
                continue;
            }

            if((inp == 'h' || inp == 's')){
                return inp;

            } else {    
                std::cout << "Not h or s, what action would you like to take?";
            }
        }
    }

    bool PlayAgain(){
        while(true){
            std::cout << "(y) to play another round, (n) to leave with your winnings: ";
            char inp{};
            std::cin >> inp;
            
            if(!std::cin){
                std::cout << "Invalid input - please try again: ";
                std::cin.clear();
                ClearInput();
                continue;
            }

            if(inp == 'y'){
                return true;
            } else if (inp == 'n'){
                return false;
            } else {    
                std::cout << "Not y or n, what action would you like to take?";
            }
        }
    }

    double GetBet(){
        while(true){
            std::cout << "Enter bet: ";
            int inp{};
            std::cin >> inp;

            if (!std::cin){
                std::cout << "Invalid input - please try again";
                std::cin.clear();
                ClearInput();
                continue;
            }
            
            return inp;
        }
    }
}