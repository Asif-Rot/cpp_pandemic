#include "doctest.h"
#include "Board.hpp"
#include "City.hpp"
#include "Color.hpp"
#include "Player.hpp"

#include "Researcher.hpp"
#include "Scientist.hpp"
#include "FieldDoctor.hpp"
#include "GeneSplicer.hpp"
#include "OperationsExpert.hpp"
#include "Dispatcher.hpp"
#include "Medic.hpp"
#include "Virologist.hpp"

using namespace pandemic;

#include <vector>
#include <iostream>
#include <stdexcept>
using namespace std;


TEST_CASE("Good pandemic code") {
    Board board;
    GeneSplicer player {board, City::Atlanta};
    board[Washington] = 2;

    player.take_card(City::Atlanta);
    CHECK_NOTHROW(player.build());
    CHECK_NOTHROW(player.drive(City::Washington));
    CHECK_EQ(board[Washington], 2);
    CHECK_NOTHROW(player.treat(City::Washington));
    CHECK_EQ(board[Washington], 1);
    CHECK_NOTHROW(player.treat(City::Washington));
    CHECK_EQ(board[Washington], 0);
    CHECK_THROWS(player.treat(City::Washington));

    player.take_card(City::Washington);
    CHECK_NOTHROW(player.build());

    player.take_card(City::Washington).take_card(City::Atlanta)
    .take_card(City::Chicago).take_card(City::NewYork).take_card(City::Montreal);
    CHECK_NOTHROW(player.discover_cure(Color::Blue));
    
    player.take_card(City::Bangkok).take_card(City::Washington);
    CHECK_NOTHROW(player.fly_direct(City::Bangkok));

    player.take_card(City::Bangkok);
    CHECK_NOTHROW(player.build());
    CHECK_NOTHROW(player.fly_shuttle(City::Washington));
    
    player.take_card(City::Bangkok);
    CHECK_NOTHROW(player.fly_charter(City::Washington));

    player.take_card(City::Karachi).take_card(City::Lagos)
    .take_card(City::Milan).take_card(City::Miami).take_card(City::Sydney);
    CHECK_NOTHROW(player.discover_cure(Color::Red)); // Should not throw as we are with the GeneSplicer
}

TEST_CASE("Bad pandemic code") {
    Board board;
    OperationsExpert player {board, City::NewYork};

    CHECK_THROWS(player.drive(City::Algiers));

    player.take_card(City::Beijing);
    CHECK_THROWS(player.fly_charter(City::Beijing));

    CHECK_THROWS(player.fly_direct(City::SaoPaulo));
    CHECK_THROWS(player.fly_shuttle(City::Sydney));

    player.take_card(City::Karachi).take_card(City::Lagos)
    .take_card(City::Milan).take_card(City::Miami).take_card(City::Sydney);
    CHECK_THROWS(player.discover_cure(Color::Red));

    Scientist p {board, City::Tehran, 4};
    CHECK_THROWS(p.build());
    CHECK_THROWS(player.discover_cure(Color::Black));
    CHECK_THROWS(p.treat(City::Tehran));
}

TEST_CASE("Dispatcher code") {
    Board board;
    Dispatcher player {board, City::Milan};
    player.take_card(City::Milan);
    CHECK_NOTHROW(player.build());
    CHECK_NOTHROW(player.fly_direct(City::SanFrancisco));
    CHECK_THROWS(player.fly_direct(City::Santiago));
}

TEST_CASE("FieldDoctor code") {
    Board board;
    FieldDoctor player {board, City::Milan};
    board[City::Milan] = 2;
    board[City::Paris] = 2;
    board[City::Essen] = 0;
    board[City::London] = 2;
    
    CHECK_NOTHROW(player.treat(City::Milan));
    CHECK_EQ(board[Milan], 1);
    CHECK_NOTHROW(player.treat(City::Paris));
    CHECK_EQ(board[Paris], 1);
    CHECK_THROWS(player.treat(City::Essen));
    CHECK_THROWS(player.treat(City::London));
    CHECK_EQ(board[London], 2);

    player.take_card(City::Milan).take_card(City::Paris)
    .take_card(City::Essen).take_card(City::London).take_card(City::Madrid);
    CHECK_NOTHROW(player.build());
    player.take_card(City::Milan);
    CHECK_NOTHROW(player.discover_cure(Color::Blue));
    CHECK_NOTHROW(player.drive(City::Paris));
    board[City::Madrid] = 2;
    CHECK_NOTHROW(player.treat(City::Madrid));
    CHECK_EQ(board[Madrid], 0);
}

TEST_CASE("Researcher code") {
    Board board;
    Researcher player {board, City::Milan};
    player.take_card(City::Milan).take_card(City::Paris)
    .take_card(City::Essen).take_card(City::London).take_card(City::Madrid);
    CHECK_NOTHROW(player.discover_cure(Color::Blue));   
    board[City::Milan] = 2;
    CHECK_NOTHROW(player.treat(City::Milan));
    CHECK_EQ(board[Milan], 0);
}

TEST_CASE("Virologist code") {
    Board board;
    Virologist player {board, City::Milan};
    board[City::Milan] = 2;
    board[City::Bogota] = 2;
    board[City::NewYork] = 0;
    board[City::Mumbai] = 2;
    
    CHECK_NOTHROW(player.treat(City::Milan));
    CHECK_EQ(board[Milan], 1);
    CHECK_NOTHROW(player.treat(City::Bogota));
    CHECK_EQ(board[Bogota], 1);
    CHECK_THROWS(player.treat(City::NewYork));
    CHECK_NOTHROW(player.treat(City::Mumbai));
    CHECK_EQ(board[Mumbai], 1);

    player.take_card(City::Milan).take_card(City::Paris)
    .take_card(City::Essen).take_card(City::London).take_card(City::Madrid);
    CHECK_NOTHROW(player.build());
    player.take_card(City::Milan);
    CHECK_NOTHROW(player.discover_cure(Color::Blue));
    board[City::Madrid] = 2;
    CHECK_NOTHROW(player.treat(City::Madrid));
    CHECK_EQ(board[Madrid], 0);
}

TEST_CASE("Scientist code") {
    Board board;
    Scientist player {board, City::Milan, 3};
    player.take_card(City::Milan).take_card(City::Paris).take_card(City::Essen);
    CHECK_NOTHROW(player.build());
    player.take_card(City::Milan);
    CHECK_NOTHROW(player.discover_cure(Color::Blue));   
    board[City::Milan] = 2;
    CHECK_NOTHROW(player.treat(City::Milan));
    CHECK_EQ(board[Milan], 0);


    Scientist p {board, City::Baghdad, 3};
    p.take_card(City::Baghdad).take_card(City::Cairo);
    CHECK_NOTHROW(p.build());
    p.take_card(City::Baghdad);
    CHECK_THROWS(p.discover_cure(Color::Black));   
    board[City::Baghdad] = 2;
    CHECK_NOTHROW(p.treat(City::Baghdad));
    CHECK_EQ(board[Baghdad], 1);
}

TEST_CASE("Medic code") {
    Board board;
    Medic player {board, City::Milan};
    board[City::Milan] = 2;
    board[City::Paris] = 3;
    board[City::Essen] = 0;
    board[City::London] = 2;

    CHECK_NOTHROW(player.treat(City::Milan));
    CHECK_EQ(board[Milan], 0);
    CHECK_NOTHROW(player.drive(City::Paris));
    CHECK_NOTHROW(player.treat(City::Paris));
    CHECK_EQ(board[Paris], 0);

    player.take_card(City::Milan).take_card(City::Paris)
    .take_card(City::Essen).take_card(City::London).take_card(City::Madrid);
    CHECK_NOTHROW(player.build());
    player.take_card(City::Paris);
    CHECK_NOTHROW(player.discover_cure(Color::Blue));

    player.take_card(City::NewYork);
    board[City::NewYork] = 2;
    CHECK_NOTHROW(player.fly_direct(City::NewYork));
    CHECK_EQ(board[NewYork], 0);

    player.take_card(City::NewYork);
    board[City::Atlanta] = 2;
    CHECK_NOTHROW(player.fly_charter(City::Atlanta));
    CHECK_EQ(board[NewYork], 0);

    player.take_card(City::Atlanta);
    CHECK_NOTHROW(player.build());
    board[City::Paris] = 3;
    CHECK_NOTHROW(player.fly_shuttle(City::Paris));
    CHECK_EQ(board[Paris], 0);

    player.take_card(City::Paris);
    board[City::Algiers] = 2;
    CHECK_NOTHROW(player.fly_charter(City::Algiers));
    CHECK_EQ(board[Algiers], 2);
}


