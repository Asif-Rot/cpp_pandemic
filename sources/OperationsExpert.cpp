#include "Board.hpp"
#include "City.hpp"
#include "Color.hpp"
#include "Player.hpp"
#include "OperationsExpert.hpp"

using namespace std;

namespace pandemic {

    /* OperationsExpert can build a research station without dropping a card */
    Player& OperationsExpert::build() {
        board.research_station.insert(board.research_station.begin(), city);
        return *this;
    }
};