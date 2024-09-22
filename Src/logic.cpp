//
// Created by Sonic on 22.09.2024.
//

#include "logic.h"

#include <iostream>

constinit uint64_t min_land_const = 17;
constinit uint64_t max_land_const = 26;

logic::logic() : acr_land(1000), people(100), wheat_bushel(2800) {
}

logic::~logic() = default;

void logic::next_round() {
    round++;
}

void logic::round_info(){
    std::cout << "Номер пятилетки: " << round << std::endl;
    std::cout << "Round info:" << std::endl;// количество репрессированных
    //количество приехавших
    //были ли репрессии
    std::cout << "Население Республики: " << people << std::endl;
    //собранная пшеница, сколько пшеницы с гектара
    //сколько пшеницы было уничтожено или украдено контрреволюционерами
    std::cout << "Нынешние размеры нашей Республики: " << acr_land << std::endl;
    land_cost = 17; //min_land_const - max_land_const
    std::cout << "Цена выкупа гектара земли у соседних республик" << land_cost << std::endl;
}

void logic::player_do() {

}

void logic::results() const {

}



