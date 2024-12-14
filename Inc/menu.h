//
// Created by Ja_Vani on 23.09.2024.
//

#ifndef MENU_H
#define MENU_H
#include <logic.h>

class Menu {
public:
    ~Menu();

    Menu(bool status, Logic &&logic);

    virtual void load_game();

    virtual void save_game();

    virtual void round_info() noexcept;

    virtual bool next_round() noexcept;

    virtual void player_do();

    virtual void game_continue();

    virtual void results();

private:
    virtual void hello() noexcept;

    bool can_by_acr(const std::wstring &in);

    bool can_sell_acr(const std::wstring &in);

    bool can_eat(const std::wstring &in);

    bool can_sow(const std::wstring &in);

    Logic logic_;
};

#endif //MENU_H
