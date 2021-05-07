#pragma once
#include "Board.hpp"
#include "City.hpp"
#include "Color.hpp"
#include "Player.hpp"

namespace pandemic {
    class Scientist: public Player {
        int tmp;
        
        public:
            Scientist(Board& board, City city, int n) : Player(board, city, "Scientist"), tmp(n)  {}
            Player& discover_cure(Color) override;
    };
};