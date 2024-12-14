//
// Created by Ja_Vani on 22.09.2024.
//

#include "logic.h"

constexpr uint64_t min_get_bushel = 1;
constexpr uint64_t max_get_bushel = 6;
constexpr uint64_t min_land_const = 17;
constexpr uint64_t max_land_const = 26;
constexpr double max_eat_rat = 0.07;

Logic::Logic(uint8_t rounds) : acr_land_(1000), people_(100), wheat_bushel_(2800), max_rounds_(rounds) {
    generator_.seed(std::random_device()());
    get_bushel_rate_distribution_ = std::uniform_int_distribution<uint64_t>(min_get_bushel, max_get_bushel);
    bushel_cost_distribution_ = std::uniform_int_distribution<uint64_t>(min_land_const, max_land_const);
    rat_eat_rate_distribution_ = std::uniform_real_distribution<double>(0.0, max_eat_rat);
    chuma_rate_distribution_ = std::uniform_real_distribution<double>(0.0, 1.0);
    land_cost_ = bushel_cost_distribution_(this->generator_);
}

bool Logic::next_round() {
    round_++;
    get_bushel_rate_ = get_bushel_rate_distribution_(this->generator_);
    wheat_bushel_ -= player_land_sow_ / 2;
    wheat_bushel_ += player_land_sow_ * get_bushel_rate_; // ACR_GET_BUSHEL: 1-6
    rat_eat_percent_ = rat_eat_rate_distribution_(this->generator_);
    wheat_bushel_ *= (1.0 - rat_eat_percent_); // RAT_EAT: 0 - 0.07
    people_died_ = people_ - player_wheal_eat_ / 20;
    p_ += people_died_ / people_;
    if (people_ * 0.45 < people_died_)return false; //завершение игры
    people_ -= people_died_;
    people_arrive_ = (people_died_ / 2) + (5 - get_bushel_rate_) * wheat_bushel_ / 600 + 1;
    if (people_arrive_ <= 0)people_arrive_ = 0;
    if (people_arrive_ >= 50)people_arrive_ = 50;
    chuma_ = false;
    if (chuma_rate_distribution_(this->generator_) > 0.85) {
        chuma_ = true;
        people_ /= 2;
    }
    people_ += people_arrive_;
    land_cost_ = bushel_cost_distribution_(this->generator_);
    return true;
}

bool Logic::final() {
    return max_rounds_ > round_;
}

bool Logic::can_by_acr(uint64_t buy) {
    if (buy * land_cost_ <= wheat_bushel_) {
        player_land_buy_ = buy;
        return true;
    }
    return false;
}

bool Logic::can_sell_acr(uint64_t acrs) {
    if (acrs <= acr_land_) {
        player_land_sell_ = acrs;
        return true;
    }
    return false;
}

bool Logic::can_eat(uint64_t bushels) {
    if (bushels <= wheat_bushel_ + player_land_buy_ * land_cost_ - player_land_sell_ * land_cost_) {
        player_wheal_eat_ = bushels;
        return true;
    }
    return false;
}

bool Logic::can_sow(uint64_t acrs) {
    if (acrs <= acr_land_ && static_cast<double>(acrs) * 0.5 <= static_cast<double>(wheat_bushel_) + static_cast<double>
        (player_land_buy_) * land_cost_ + static_cast<double>(player_wheal_eat_) -
        static_cast<double>(player_land_sell_) * land_cost_) {
        player_land_sow_ = acrs;
        return true;
    }
    return false;
}

uint64_t Logic::calculate_L() {
    return acr_land_ / people_;
}

double Logic::calculate_P() {
    return p_ / max_rounds_;
}
