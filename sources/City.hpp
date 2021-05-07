#pragma once
#include <iostream>
#include <string>

enum City {
    Algiers,
    Atlanta,
    Baghdad,
    Bangkok,
    Beijing,
    Bogota,
    BuenosAires,
    Cairo,
    Chennai,
    Chicago,
    Delhi,
    Essen,
    HoChiMinhCity,
    HongKong,
    Istanbul,
    Jakarta,
    Johannesburg,
    Karachi,
    KePasio,
    Khartoum,
    Kinshasa,
    Kolkata,
    Lagos,
    Lima,
    London,
    LosAngeles,
    Madrid,
    Manila,
    MexicoCity,
    Miami,
    Milan,
    Montreal,
    Moscow,
    Mumbai,
    NewYork,
    Osaka,
    Paris,
    Riyadh,
    SanFrancisco,
    Santiago,
    SaoPaulo,
    Seoul,
    Shanghai,
    StPetersburg,
    Sydney,
    Taipei,
    Tehran,
    Tokyo,
    Washington
};

inline std::string city_name(City city) {
    switch (city) {
        case Algiers:       return "Algiers";
        case Atlanta:       return "Atlanta";
        case Baghdad:       return "Baghdad";       
        case Bangkok:       return "Bangkok";
        case Beijing:       return "Beijing";       
        case Bogota:        return "Bogota";
        case BuenosAires:   return "BuenosAires";
        case Cairo:         return "Cairo";
        case Chennai:       return "Chennai";
        case Chicago:       return "Chicago";
        case Delhi:         return "Delhi";
        case Essen:         return "Essen";
        case HoChiMinhCity: return "HoChiMinhCity";
        case HongKong:      return "HongKong";
        case Istanbul:      return "Istanbul";
        case Jakarta:       return "Jakarta";
        case Johannesburg:  return "Johannesburg";
        case Karachi:       return "Karachi";
        case KePasio:       return "KePasio";
        case Khartoum:      return "Khartoum";
        case Kinshasa:      return "Kinshasa";
        case Kolkata:       return "Kolkata";
        case Lagos:         return "Lagos";
        case Lima:          return "Lima";
        case London:        return "London";
        case LosAngeles:    return "LosAngeles";
        case Madrid:        return "Madrid";
        case Manila:        return "Manila";
        case MexicoCity:    return "MexicoCity";
        case Miami:         return "Miami";
        case Milan:         return "Milan";
        case Montreal:      return "Montreal";
        case Moscow:        return "Moscow";
        case Mumbai:        return "Mumbai";
        case NewYork:       return "NewYork";
        case Osaka:         return "Osaka";
        case Paris:         return "Paris";
        case Riyadh:        return "Riyadh";
        case SanFrancisco:  return "SanFrancisco";
        case Santiago:      return "Santiago";
        case SaoPaulo:      return "SaoPaulo";
        case Seoul:         return "Seoul";
        case Shanghai:      return "Shanghai";
        case StPetersburg:  return "StPetersburg";
        case Sydney:        return "Sydney";
        case Taipei:        return "Taipei";
        case Tehran:        return "Tehran";
        case Tokyo:         return "Tokyo";
        case Washington:    return "Washington";

        default:            return NULL;
    }
}