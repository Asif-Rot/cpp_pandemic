#include "Board.hpp"
#include "City.hpp"
#include "Color.hpp"
#include "Player.hpp"
#include "Scientist.hpp"

#include <iostream>
#include <stdexcept>
#include <algorithm>
#include <vector>
using namespace std;

namespace pandemic {

    /* Scientist can discover cure with n cards (initialized in the constructor) */
    Player& Scientist::discover_cure(Color c) {
        int count = 0;
        for(uint i = 0; i < tmp; i++) {
            count++;
        }
        if (count < tmp) {
            throw invalid_argument("You don't have enough cards");
        }
        
        if (board.cured.count(city_colorr.at(city)) == 0U) { 
            if(!(find(board.research_station.begin(), board.research_station.end(), city) != board.research_station.end())) {
                throw invalid_argument("You don't have a research station in " + city_name(city));
            }
            if ((color_cards(c) < tmp)) {
                throw invalid_argument("You don't have enough cards with the same color");
            }

            int num = 0;
            uint j = 0;
            while (num < tmp) {
                if(city_colorr.at(playcards.at(j)) == c) {
                    playcards.erase(playcards.begin() + j);                    
                    j--;
                    num++;
                }
                j++;
            }
            board.cured.insert({c, true});
        }

        return *this;
    }
};