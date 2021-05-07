#pragma once
#include "Board.hpp"
#include "City.hpp"
#include "Color.hpp"
#include "Player.hpp"

namespace pandemic {
    class OperationsExpert: public Player {
        
        public:
            OperationsExpert(Board& board, City city) : Player(board, city, "OperationsExpert") {}
            Player& build() override;
    };
};