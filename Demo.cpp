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
#include <string>
#include <stdexcept>
using namespace std;

#define RESET       "\033[0m"
#define RED         "\033[31m"
#define GREEN       "\033[32m"

void what_role(string rol);
void what_action(string action);
void cities_num();
City int_to_city(int c);
void take_action(Player& player, string action);

int main () {
    Board board;
    vector<string> roles {"Dispatcher", "Scientist", "Researcher", "Medic", "Virologist", "GeneSplicer", "FieldDoctor"};
    cout << "let's play a game called Pandemic!" << endl;
    cout << "every player need to choose his role in the game from the list below:" << endl;
    for (uint i = 0; i < roles.size(); i++) {
        cout << "- " << roles[i] << endl;
    }
    
    string tmp;
    Dispatcher player {board, City::Algiers};
    while (true) {
        cout << "\nPlease pick a role from the list above: " << endl;
        string x;
        cin >> x;
        tmp = x;
        if (tmp == "Dispatcher") {
            Dispatcher player {board, City::Algiers};
            break;
        }
        else if (tmp == "Scientist") {
            Scientist player {board, City::Algiers, 4};
            break;
        }
        else if (tmp == "Researcher") {
            Researcher player {board, City::Algiers};
            break;
        }
        else if (tmp == "Medic") {
            Medic player {board, City::Algiers};
            break;
        }
        else if (tmp == "Virologist") {
            Virologist player {board, City::Algiers};
            break;
        }
        else if (tmp == "GeneSplicer") {
            GeneSplicer player {board, City::Algiers};
            break;
        }
        else if (tmp == "FieldDoctor") {
            FieldDoctor player {board, City::Algiers};
            break;
        }
        else {
            cout << "You didn't choose a player from the list, please try again." << endl;
        }
    }
    cout << "You chose to be: " << tmp << endl;
    what_role(tmp);

    cout << "\n\nLet's start the game!" << endl;
    cout << "Your player is in Algiers" << endl;
    cout << "These are the cities you can travel in:\n" << endl;
    cities_num();
    cout << "Now, what would you like to do?" << endl;
    vector<string> options {"Take_card - Take card from the packet",
                            "Drive - Drive to a connected city",
                            "Fly_direct - Fly from one city to another by dropping the card with the city you wanna go to",
                            "Fly_charter - Fly from one city to another by dropping the card with your current city on",
                            "Fly_Shuttle - Fly from one city to another if both cities have research stations",
                            "Build - Build research station in the current city",
                            "Discover_cure - Discover cure to a specific color by dropping 5 cards with the same color",
                            "Treat - Treat one disease cube from the current city"
                            };
    for (uint i = 0; i < options.size(); i++) {
        cout << "- " << options[i] << endl;
    }

    cout << "\nPlease pick an action from the list above: " << endl;
    string act;
    while (true) {
            try {
                string act;
                take_action(player, act);
                break;
            }
            catch (const invalid_argument &invalid) {
                cout << "Exception: " << RED << invalid.what() << RESET << endl;
                cout << "Please try again." << endl;
            }
            catch (exception &e) {
                cout << "Exception: " << RED << e.what() << RESET << endl;
                cout << "Something went wrong, please try again." << endl;
            }
        }

    return 0;
}

void what_role(string rol) {
    if (rol == "Dispatcher") {
            cout << rol << " - Special skill is: If the Dispatcher is at a research station, he is able to fly direct to any city without dropping a card";
    }
    else if (rol == "Scientist") {
        cout << rol << " - Special skill is: Scientist can discover cure with 4 cards";
    }
    else if (rol == "Researcher") {
        cout << rol << " - Special skill is: Researcher can discover cure without having to be in a reasearch station";
    }
    else if (rol == "Medic") {
        cout << rol << " - Special skill is: Treat all the disease cubes from the city he is in";
    }
    else if (rol == "Virologist") {
        cout << rol << " - Special skill is: Virologist can treat any city in the world by dropping its card";
    }
    else if (rol == "GeneSplicer") {
        cout << rol << " - Special skill is: GeneSplicer can discover cure with any 5 cards (with mixed colors)";
    }
    else if (rol == "FieldDoctor") {
            cout << rol << " - Special skill is: FieldDoctor can treat connected cities as well without dropping a card";
    }
}

void take_action(Player& player, string action) {
    while (true) {
        cin >> action;
        if (action == "Take_card") {
            cout << "Which city? choose a number from 0 to 48 from the list above:" << endl;
            int c;
            cin >> c;
            City city = int_to_city(c);
            player.take_card(city);
            break;
        }
        else if (action == "Drive") {
            cout << "Which city? choose a number from 0 to 48 from the list above:" << endl;
            int c;
            cin >> c;
            City city = int_to_city(c);
            player.drive(city);
            break;
        }
        else if (action == "Fly_direct") {
            cout << "Which city? choose a number from 0 to 48 from the list above:" << endl;
            int c;
            cin >> c;
            City city = int_to_city(c);
            player.fly_direct(city);
            break;
        }
        else if (action == "Fly_charter") {
            cout << "Which city? choose a number from 0 to 48 from the list above:" << endl;
            int c;
            cin >> c;
            City city = int_to_city(c);
            player.fly_charter(city);
            break;
        }
        else if (action == "Fly_Shuttle") {
            cout << "Which city? choose a number from 0 to 48 from the list above:" << endl;
            int c;
            cin >> c;
            City city = int_to_city(c);
            player.fly_shuttle(city);
            break;
        }
        else if (action == "Build") {
            player.build();
            break;
        }
        else if (action == "Discover_cure") {
            cout << "Which color? choose a number from 0 to 4 from the list below:" << endl;
            cout <<
                    "0 - Red\n"
                    "1 - Yellow\n"
                    "2 - Blue\n"
                    "3 - Black\n" << endl;
            int c;
            while (true) {
                cin >> c;
                if (c < 0 || c > 3) {
                    cout << "Please try again." << endl;
                }
                break;
            }
            Color color = (Color)c;
            player.discover_cure(color);
            break;
        }
        else if (action == "Treat") {
            cout << "Which city? choose a number from 0 to 48 from the list above:" << endl;
            int c;
            cin >> c;
            City city = int_to_city(c);
            player.treat(city);
            break;
        }
        else {
            cout << "Please choose one of the actions from the list above." << endl;
            action = "";
        }
    }
}

void cities_num() {
    cout <<
    "0 - Algiers\n"
    "1 - Atlanta\n"
    "2 - Baghdad\n"
    "3 - Bangkok\n"
    "4 - Beijing\n"
    "5 - Bogota\n"
    "6 - BuenosAires\n"
    "7 - Cairo\n"
    "8 - Chennai\n"
    "9 - Chicago\n"
    "10 - Delhi\n"
    "11 - Essen\n"
    "12 - HoChiMinhCity\n"
    "13 - HongKong\n"
    "14 - Istanbul\n"
    "15 - Jakarta\n"
    "16 - Johannesburg\n"
    "17 - Karachi\n"
    "18 - KePasio\n"
    "19 - Khartoum\n"
    "20 - Kinshasa\n"
    "21 - Kolkata\n"
    "22 - Lagos\n"
    "23 - Lima\n"
    "24 - London\n"
    "25 - LosAngeles\n"
    "26 - Madrid\n"
    "27 - Manila\n"
    "28 - MexicoCity\n"
    "29 - Miami\n"
    "30 - Milan\n"
    "31 - Montreal\n"
    "32 - Moscow\n"
    "33 - Mumbai\n"
    "34 - NewYork\n"
    "35 - Osaka\n"
    "36 - Paris\n"
    "37 - Riyadh\n"
    "38 - SanFrancisco\n"
    "39 - Santiago\n"
    "40 - SaoPaulo\n"
    "41 - Seoul\n"
    "42 - Shanghai\n"
    "43 - StPetersburg\n"
    "44 - Sydney\n"
    "45 - Taipei\n"
    "46 - Tehran\n"
    "47 - Tokyo\n"
    "48 - Washington\n" << endl;
}

City int_to_city(int c) {
    City city;
    while (true) {
        if (c < 0 || c > 48) {
            cout << "Please chooes a number from 0 to 48 from the list above." << endl;
        }
        else {
            city = (City)c;
            break;
        }
    }
    return city;
}
