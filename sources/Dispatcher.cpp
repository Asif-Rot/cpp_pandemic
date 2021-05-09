#include "Board.hpp"
#include "City.hpp"
#include "Color.hpp"
#include "Player.hpp"
#include "Dispatcher.hpp"

#include <iostream>
#include <stdexcept>
#include <algorithm>
#include <vector>
using namespace std;

namespace pandemic {

    /* If the Dispatcher is at a research station, he is able to fly direct to any city without dropping a card*/
    Player& Dispatcher::fly_direct(City c) {
        if (city == c) {
            throw invalid_argument("You are already in " + city_name(c));
        }
        
        if(!(find(board.research_station.begin(), board.research_station.end(), city) != board.research_station.end())) {
            if(count(playcards.begin(), playcards.end(), c) == 0) {
                throw invalid_argument("You don't have " + city_name(c) + " in your cards");
            }
            playcards.erase(remove(playcards.begin(), playcards.end(), c), playcards.end());
        }
        
        city = c;
        
        return *this;
    }
};