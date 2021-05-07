#include "Board.hpp"
#include "City.hpp"
#include "Color.hpp"
#include "Player.hpp"
#include "Virologist.hpp"

#include <iostream>
#include <stdexcept>
#include <algorithm>
#include <vector>
using namespace std;

namespace pandemic {

    Player& Virologist::treat(City c) {
        if (city == c) {
            Player::treat(c);
            return *this;
        }

        if(count(playcards.begin(), playcards.end(), c) == 0) {
            throw invalid_argument("You don't have " + city_name(c) + " in your cards");
        }

        if(board[c] == 0) {
            throw invalid_argument(city_name(c) + "is already cured!");
        }
        
        if (board.cured.count(city_colorr.at(c)) == 0U) {
            board[c]--;
        }
        else {
            board[c] = 0;
        }
        playcards.erase(remove(playcards.begin(), playcards.end(), c), playcards.end());

        return *this;
    }
};