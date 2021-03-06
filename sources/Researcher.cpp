#include "Board.hpp"
#include "City.hpp"
#include "Color.hpp"
#include "Player.hpp"
#include "Researcher.hpp"

#include <iostream>
#include <stdexcept>
#include <algorithm>
#include <vector>
using namespace std;

namespace pandemic {

    const int max_num_cards = 5;

    /* Researcher can discover cure without having to be in a reasearch station */
    Player& Researcher::discover_cure(Color c) {
        int count = 0;
        for(uint i = 0; i < playcards.size(); i++) {
            count++;
        }
        if (count < max_num_cards) {
            throw invalid_argument("You don't have enough cards");
        }
        
        if (board.cured.count(city_colorr.at(city)) == 0U) { 
            if ((color_cards(c) < max_num_cards)) {
                throw invalid_argument("You don't have enough cards with the same color");
            }

            int num = 0;
            uint j = 0;
            while (num < max_num_cards) {
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