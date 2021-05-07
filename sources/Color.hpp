#pragma once
#include "City.hpp"

#include "iostream"
#include <map>

enum Color {
    Red,
    Yellow,
    Blue,
    Black
};

inline std::string color_name(int a) {
    if (a == 0) {
        return "Red";
    }
    if (a == 1) {
        return "Yellow";
    }
    if (a == 2) {
        return "Blue";
    }
    else {
        return "Black";
    }
}

const std::map <City, Color> city_colorr {
    {City::Algiers, Color::Black},
    {City::Atlanta, Color::Blue},
    {City::Baghdad, Color::Black},
    {City::Bangkok, Color::Red},
    {City::Beijing, Color::Red},
    {City::Bogota, Color::Yellow},
    {City::BuenosAires, Color::Yellow},
    {City::Cairo, Color::Black},
    {City::Chennai, Color::Black},
    {City::Chicago, Color::Blue},
    {City::Delhi, Color::Black},
    {City::Essen, Color::Blue},
    {City::HoChiMinhCity, Color::Red},
    {City::HongKong, Color::Red},
    {City::Istanbul, Color::Black},
    {City::Jakarta, Color::Red},
    {City::Johannesburg, Color::Yellow},
    {City::Karachi, Color::Black},
    {City::Khartoum, Color::Yellow},
    {City::Kinshasa, Color::Yellow},
    {City::Kolkata, Color::Black},
    {City::Lagos, Color::Yellow},
    {City::Lima, Color::Yellow},
    {City::London, Color::Blue},
    {City::LosAngeles, Color::Yellow},
    {City::Madrid, Color::Blue},
    {City::Manila, Color::Red},
    {City::MexicoCity, Color::Yellow},
    {City::Miami, Color::Yellow},
    {City::Milan, Color::Blue},
    {City::Montreal, Color::Blue},
    {City::Moscow, Color::Black},
    {City::Mumbai, Color::Black},
    {City::NewYork, Color::Blue},
    {City::Osaka, Color::Red},
    {City::Paris, Color::Blue},
    {City::Riyadh, Color::Black},
    {City::SanFrancisco, Color::Blue},
    {City::Santiago, Color::Yellow},
    {City::SaoPaulo, Color::Yellow},
    {City::Seoul, Color::Red},
    {City::Shanghai, Color::Red},
    {City::StPetersburg, Color::Blue},
    {City::Sydney, Color::Red},
    {City::Taipei, Color::Red},
    {City::Tehran, Color::Black},
    {City::Tokyo, Color::Red},
    {City::Washington, Color::Blue}
};