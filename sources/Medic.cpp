#include "Board.hpp"
#include "City.hpp"
#include "Color.hpp"
#include "Player.hpp"
#include "Medic.hpp"

using namespace std;

namespace pandemic {

    /**
     *  כשהוא מבצע פעולת "טיפול במחלה", הוא מוריד את כל קוביות-המחלה מהעיר שהוא נמצא בה, ולא רק אחת.
אם כבר התגלתה תרופה למחלה, הוא אוטומטית מוריד את כל קוביות-המחלה מכל עיר שהוא נמצא בה, גם בלי לבצע פעולת "טיפול במחלה".
    */

    Player& Medic::treat(City c) {
        if (city != c) {
            throw invalid_argument("Player is not in " + city_name(c) + ", can't perform this action");
        }
        
        if(board[c] == 0) {
            throw invalid_argument(city_name(c) + " is already cured!");
        }
        
        board[c] = 0;

        return *this;
    }

    Player& Medic::drive(City c) {
        Player::drive(c);
        if (board.cured.count(city_colorr.at(c)) != 0U) {
            board[c] = 0;
        }

        return *this;
    }
    Player& Medic::fly_direct(City c) {
        Player::fly_direct(c);
        if (board.cured.count(city_colorr.at(c)) != 0U) {
            board[c] = 0;
        }

        return *this;
    }

    Player& Medic::fly_shuttle(City c) {
        Player::fly_shuttle(c);
        if (board.cured.count(city_colorr.at(c)) != 0U) {
            board[c] = 0;
        }

        return *this;
    }
    
    Player& Medic::fly_charter(City c) {
        Player::fly_charter(c);
        if (board.cured.count(city_colorr.at(c)) != 0U) {
            board[c] = 0;
        }

        return *this;
    }
};