#include "Board.hpp"
#include "City.hpp"
#include "Color.hpp"
#include "Player.hpp"

#include <iostream>
#include <stdexcept>
#include <algorithm>
#include <vector>
using namespace std;

namespace pandemic {
    
    const int max_num_cards = 5;

    /* Drive from one city to another */
    Player& Player::drive(City c) {
        if (!(pandemic::Board::isNei(city, c))){
            throw invalid_argument(city_name(c) + " is not a neighbor of " + city_name(city));
        }
        city = c;

        return *this;
    }

    /* Fly from one city to another by dropping the card with the city you wanna go to */
    Player& Player::fly_direct(City c) {
        if(count(playcards.begin(), playcards.end(), c) == 0) {
            throw invalid_argument("You don't have " + city_name(c) + " in your cards");
        }
        if (city == c) {
            throw invalid_argument("You are already in " + city_name(c));
        }
        playcards.erase(remove(playcards.begin(), playcards.end(), c), playcards.end());
        city = c;
        
        return *this;
    }

    /* Fly from one city to another by dropping the card with your current city on */
    Player& Player::fly_charter(City c) {
        if(!(find(playcards.begin(), playcards.end(), city) != playcards.end())) {
            throw invalid_argument("You don't have " + city_name(city) + " in your cards");
        }
        if (city == c) {
            throw invalid_argument("You are already in " + city_name(c));
        }
        playcards.erase(remove(playcards.begin(), playcards.end(), city), playcards.end());
        city = c;
        
        return *this;
    }

    /* Fly from one city to another if both cities have research stations */
    Player& Player::fly_shuttle(City c) {
        if(!(find(board.research_station.begin(), board.research_station.end(), city) != board.research_station.end())
         || !(find(board.research_station.begin(), board.research_station.end(), c) != board.research_station.end())) {
            throw invalid_argument("You don't have a research station in " + city_name(city) + " or in " + city_name(c));
        }
        if (city == c) {
            throw invalid_argument("You are already in " + city_name(c));
        }
        city = c;
        
        return *this;
    }

    /* Build research station in the current city */
    Player& Player::build() {
        if(!(find(playcards.begin(), playcards.end(), city) != playcards.end())) {
            throw invalid_argument("You don't have " + city_name(city) + " in your cards");
        }
        board.research_station.insert(board.research_station.begin(), city);
        playcards.erase(remove(playcards.begin(), playcards.end(), city), playcards.end());

        return *this;
    }

    /* Discover cure to a specific color by dropping 5 cards with the same color */
    Player& Player::discover_cure(Color c) {
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

    /* Treat one disease cube from the current city */
    Player& Player::treat(City c) {
        if (city != c) {
            throw invalid_argument("Player is not in " + city_name(c) + ", can't perform this action");
        }
        
        if(board[c] == 0) {
            throw invalid_argument(city_name(c) + "is already cured!");
        }
        
        // if the color of the city is already cured, clear the city from disease
        if (board.cured.count(city_colorr.at(c)) == 0U) {
            board[c]--;
        }
        else {
            board[c] = 0;
        }

        return *this;
    }

    /* Take a card from the packet */
    Player& Player::take_card(City c) {
        playcards.insert(playcards.begin(), c);
        return *this;

    }
    /* Remove all cards */
    void Player::remove_cards() {
        playcards.clear();
    }

    /* Checking how many cards with the same color does the player have */
    int Player::color_cards(Color c) {
        int num = 0;
        for(uint i = 0; i < playcards.size(); i++) {
            if(city_colorr.at(playcards.at(i)) == c) {
                num++;
            }
        }
        return num;
    }

};