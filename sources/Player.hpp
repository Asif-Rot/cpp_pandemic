#pragma once
#include "Board.hpp"
#include "City.hpp"
#include "Color.hpp"

#include <iostream>
#include <stdexcept>
#include <vector>

using namespace std;

namespace pandemic {
    class Player {
        
        protected:
            Board& board;
            City city;
            std::string rol;
            std::vector<City> playcards;

        public:
            Player(Board& b, City c, std::string r) : board(b), city(c), rol(r) {
                std::vector<City> playcardstmp;
                this->playcards = playcardstmp;
            }

            virtual Player& drive(City c);
            virtual Player& fly_direct(City);
            virtual Player& fly_charter(City);
            virtual Player& fly_shuttle(City);
            virtual Player& build();
            virtual Player& discover_cure(Color);
            virtual Player& treat(City);
            Player& take_card(City);
            std::string role() {
                return rol;
            }
            void remove_cards();

            int color_cards(Color);

            
    
    };
    
};