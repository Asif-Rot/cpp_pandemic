#include "Board.hpp"
#include "City.hpp"
#include "Color.hpp"
#include "Player.hpp"
#include "FieldDoctor.hpp"

using namespace std;

namespace pandemic {
    
    /* FieldDoctor can treat connected cities as well without dropping a card */
    Player& FieldDoctor::treat(City c) {
        if (c == city || Board::isNei(city, c)) {
            if(board[c] == 0) {
                throw invalid_argument(city_name(c) + " is already cured!");
            }
    
            if (board.cured.count(city_colorr.at(c)) == 0U) {
                board[c]--;
            }
            else {
                board[c] = 0;
            }
        }
        else {
            throw invalid_argument(city_name(c) + " is not a neighbor of " + city_name(city));
        }

        return *this;
    }
};