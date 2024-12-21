//
// Created by Ja_Vani on 23.09.2024.
//

#include "menu.h"

#include <fstream>
#include <iostream>

Menu::Menu(bool status, Logic &&logic): logic_(std::move(logic)) {
    if (status) hello();
}

void Menu::hello() noexcept {
    std::wcout << L" Товарищ, поздравляю вас с назначением на такое ответственное задание." << std::endl;
    std::wcout <<
            L" В связи с вашим неожиданным назначением, думаю что вам необходима вводная информация по этому месту."
            << std::endl;
    std::wcout << L"Да/Нет" << std::endl;
    std::wstring in;
    std::wcin >> in;
    if (in != L"Нет") {
        // Туториал
    }
}

void Menu::load_game() {
    std::wcout << L"Необходимо ли начать с последней точки сохранения?" << std::endl;
    std::wcout << L"Да/Нет" << std::endl;
    std::wstring in;
    std::wcin >> in;
    if (in == L"Да") {
        std::wcout << L"Введите название сохранения:" << std::endl;
        std::wcin >> in;
        try {
            std::ifstream input(in.c_str());
            input >> logic_.max_rounds_ >> logic_.round_ >> logic_.land_cost_ >>
                    logic_.people_died_ >> logic_.people_arrive_ >> logic_.acr_land_ >>
                    logic_.people_ >> logic_.wheat_bushel_ >>
                    logic_.chuma_ >> logic_.get_bushel_rate_ >> logic_.rat_eat_percent_ >> logic_.p_;
            std::wcout << L"Сохранение успешно загружено" << std::endl;
        } catch (const std::ifstream::failure &ex) {
            std::wcout << L"Ошибка при чтении данных сохранения" << std::endl;
            std::cerr << ex.what() << std::endl;
        } catch (const std::exception &ex) {
            std::wcout << L"ERROR";
            std::cerr << ex.what() << std::endl;
            exit(1);
        }
    }
}

void Menu::save_game() {
    std::wstring in;
    std::wcout << L"Введите название сохранения:" << std::endl;
    std::wcin >> in;
    try {
        std::ofstream output(in.c_str());
        output << logic_.max_rounds_ << " " << logic_.round_ << " " << logic_.land_cost_ << " " << logic_.people_died_
                << " " << logic_.people_arrive_ << " " <<
                logic_.acr_land_ << " " << logic_.people_ << " " << logic_.wheat_bushel_ << " " << logic_.chuma_ <<
                " " << logic_.get_bushel_rate_ << " " << logic_.rat_eat_percent_ << " " << logic_.p_;
        std::wcout << L"Сохранение успешно совершено" << std::endl;
    } catch (const std::ofstream::failure &ex) {
        std::wcout << L"Ошибка при записи данных сохранения" << std::endl;
        std::cerr << ex.what() << std::endl;
    } catch (const std::exception &ex) {
        std::wcout << L"ERROR";
        std::cerr << ex.what() << std::endl;
        exit(1);
    }
    exit(0);
}

void Menu::game_continue() {
    std::wcout << L"Хотите продолжить?" << std::endl;
    std::wcout << L"Да/Нет" << std::endl;
    std::wstring in;
    std::wcin >> in;
    if (in == L"Нет") {
        save_game();
    }
}

void Menu::round_info() noexcept {
    std::wcout << L"Номер пятилетки: " << logic_.round_ << std::endl;
    std::wcout << L"Количество пойманных контрреволюционеров: " << logic_.people_died_ << std::endl;
    std::wcout << L"Количество новых жителей нашей республики: " << logic_.people_arrive_ << std::endl;
    if (logic_.chuma_) {
        std::wcout << L"Был раскрыт антиправительственный заговор" << std::endl;
    } else {
        std::wcout << L"В нашей Республике нет заговорщиков" << std::endl;
    }
    std::wcout << L"Население Республики: " << logic_.people_ << std::endl;
    std::wcout << L"Всего пшеницы: " << logic_.wheat_bushel_ << L" Собрано с гектара: " << logic_.get_bushel_rate_ <<
            std::endl;
    std::wcout << L"Пшеницы уничтожено контрреволюционерами: " << logic_.rat_eat_percent_ <<
            std::endl;
    std::wcout << L"Нынешние размеры нашей Республики: " << logic_.acr_land_ << std::endl;
    std::wcout << L"Цена выкупа гектара земли у соседних республик: " << logic_.land_cost_ << std::endl;
}

bool Menu::next_round() noexcept {
    if (!logic_.next_round()) {
        std::wcout << L"Вы обвиняетесь в контрреволюционной деятельности, за огромные человеческие потери в Республике";
        exit(0);
    }
    return logic_.final();
}

bool Menu::can_by_acr(const std::wstring &in) {
    try {
        return logic_.can_by_acr(std::stoll(in));
    } catch (const std::exception &ex) {
        std::wcout << L"Ошибка введённого типа данных" << std::endl;
        return false;
    }
}

bool Menu::can_sell_acr(const std::wstring &in) {
    try {
        return logic_.can_sell_acr(std::stoll(in));
    } catch (const std::exception &ex) {
        std::wcout << L"Ошибка введённого типа данных" << std::endl;
        return false;
    }
}

bool Menu::can_eat(const std::wstring &in) {
    try {
        return logic_.can_eat(std::stoll(in));
    } catch (const std::exception &ex) {
        std::wcout << L"Ошибка введённого типа данных" << std::endl;
        return false;
    }
}

bool Menu::can_sow(const std::wstring &in) {
    try {
        return logic_.can_sow(std::stoll(in));
    } catch (const std::exception &ex) {
        std::wcout << L"Ошибка введённого типа данных" << std::endl;
        return false;
    }
}

void Menu::player_do() {
    std::wstring in;
    do {
        std::wcout << L"Введите количество гектаров земли, которые будут выкуплены у капиталистов: " << std::endl;
        std::wcin >> in;
    } while (!this->can_by_acr(in));
    do {
        std::wcout << L"Введите количество гектаров земли, которые будут проданы капиталистам: " << std::endl;
        std::wcin >> in;
    } while (!this->can_sell_acr(in));
    do {
        std::wcout << L"Введите количество пшеницы, которая пойдёт на прокорм крестьян: " << std::endl;
        std::wcin >> in;
    } while (!this->can_eat(in));
    do {
        std::wcout << L"Введите количество гектаров земли, которые будут засажены пшеницей: " << std::endl;
        std::wcin >> in;
    } while (!this->can_sow(in));
}

Menu::~Menu() = default ;

void Menu::results() {
    int64_t l = logic_.calculate_L();
    double p = logic_.calculate_P();
    if (l < 7 || p > 0.33) {
        std::wcout <<
                L"Из-за вашей некомпетентности вас обвинили в контрреволюционной деятельности. Вы сумели сбежать, но теперь всегда будете волочить своё жалкое существование"
                << std::endl;
        return;
    }
    if (l < 9 || p > 0.1) {
        std::wcout <<
                L"Вас сняли с поста. Вы проживёте спокойную жизнь на низких постах, но о вашем уходе никто не будет сожалеть."
                << std::endl;
        return;
    }
    if (l < 10 || p > 0.03) {
        std::wcout <<
                L"Вы сослужили хорошую службу Республике. Да всё ещё существуют недоброжелатели, которые стремятся вас уничтожить, но их не очень много."
                << std::endl;
        return;
    }
    std::wcout <<
            L"Превосходно, под вашим командованием наша советская Республика, добилась максимальных результатов. О ваших достижениях будут поминть потомку спустя века."
            << std::endl;
}
