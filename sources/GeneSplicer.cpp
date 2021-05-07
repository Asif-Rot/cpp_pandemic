#include "Board.hpp"
#include "City.hpp"
#include "Color.hpp"
#include "Player.hpp"
#include "GeneSplicer.hpp"

#include <iostream>
#include <stdexcept>
#include <algorithm>
#include <vector>
using namespace std;

namespace pandemic {

    const int max_num_cards = 5;

    Player& GeneSplicer::discover_cure(Color c) {
        int count = 0;
        for(uint i = 0; i < playcards.size(); i++) {
            count++;
        }
        
        if (count < max_num_cards) {
            throw invalid_argument("You don't have enough cards");
        }
        
        if (board.cured.count(city_colorr.at(city)) == 0U) { 
            if(!(find(board.research_station.begin(), board.research_station.end(), city) != board.research_station.end())) {
                throw invalid_argument("You don't have a research station in " + city_name(city));
            }
            
            for (int i = 0; i < max_num_cards; ++i) {
                playcards.erase(playcards.begin());
            }
            board.cured.insert({c, true});
        }

        return *this;
    }
};