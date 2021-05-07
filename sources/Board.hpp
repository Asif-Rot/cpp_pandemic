#pragma once
#include "Color.hpp"
#include "City.hpp"

#include <vector>
#include <iostream>
#include <map>

namespace pandemic {
    class Board {
              
        std::map<City, int> num_cubes;
        static std::map<City, std::vector<City>> nei;
        
        public:
            Board();
            std::vector<City> research_station; // define here in case of multiple players
            std::map<Color, bool> cured;
            int& operator[](const City);
            friend std::ostream& operator<< (std::ostream& os, const Board& b);
            bool is_clean();
            void remove_cures();
            void remove_stations ();
            static bool isNei(City c1, City c2);

    };

};