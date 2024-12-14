//
// Created by Ja_Vani on 22.09.2024.
//

#ifndef LOGIC_H
#define LOGIC_H
#include <cstdint>
#include <random>

//People, acr of land, bushel of wheat
class Logic {
public:
    uint16_t max_rounds_ = 0;
    uint16_t round_ = 0;

    uint16_t land_cost_ = 0;
    uint64_t people_died_ = 0;
    uint64_t people_arrive_ = 0;

    uint64_t acr_land_;
    uint64_t people_;
    uint64_t wheat_bushel_;

    uint64_t get_bushel_rate_;
    double rat_eat_percent_;

    bool chuma_;

    double p_ = 0.;

    bool can_by_acr(uint64_t buy);

    bool can_sell_acr(uint64_t acrs);

    bool can_eat(uint64_t bushels);

    bool can_sow(uint64_t acrs);

    virtual bool next_round();

    virtual bool final();

    virtual uint64_t calculate_L();

    virtual double calculate_P();

    Logic(uint8_t rounds);

    Logic(Logic &logic) = default;

    Logic(Logic &&logic) = default;

    Logic &operator=(Logic &logic) = default;

    Logic &operator=(Logic &&logic) = default;

    ~Logic() = default;

private:
    uint64_t player_land_buy_ = 0;
    uint64_t player_land_sell_ = 0;
    uint64_t player_wheal_eat_ = 0;
    uint64_t player_land_sow_ = 0;

    std::default_random_engine generator_;
    std::uniform_int_distribution<uint64_t> get_bushel_rate_distribution_;
    std::uniform_int_distribution<uint64_t> bushel_cost_distribution_;
    std::uniform_real_distribution<double> rat_eat_rate_distribution_;
    std::uniform_real_distribution<double> chuma_rate_distribution_;
};


#endif //LOGIC_H
