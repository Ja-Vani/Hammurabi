//
// Created by Ja_Vani on 22.09.2024.
//

#ifndef LOGIC_H
#define LOGIC_H
#include <cstdint>

//People, acr of land, bushel of wheat
class logic {
private:
    uint8_t land_cost = 0;
    uint64_t player_land_buy = 0;
    uint64_t player_land_sell = 0;
    uint64_t player_wheal_eat = 0;
    uint64_t player_land_sow = 0;

    uint64_t acr_land;
    uint64_t people;
    uint64_t wheat_bushel;
public:
    uint8_t round = 0;
    logic();

    ~logic();
    void round_info();
    void player_do();
    void next_round();
    void results() const;
};


#endif //LOGIC_H
