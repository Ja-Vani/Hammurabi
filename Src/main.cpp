//
// Created by Ja_Vani on 22.09.2024.
//

#include <iostream>
#include <cstring>

#include "logic.h"

constinit int rounds = 10;

/// @brief Приветственные фразы
void hello_func();

void game_cycle();

int main(int argc, char *argv[]) {
    bool start_info = true;
    if(argc >= 2) {
        for(int i = 1; i < argc; i++) {
            if(!strcmp(argv[i], "-ns")) { // none start
                start_info = false;
            }
            if(!strcmp(argv[i], "--rounds")) {
                if(argc < ++i) {
                    rounds = atoi(argv[i]);
                } else {
                    break;
                }
            }
        }
    }
    if(start_info)hello_func();
    //загрузка новой игры, или старт нынешней
    logic log = logic();
    while (log.round <= rounds) {
        log.round_info();
        // возможность сохраниться и выйти
        log.player_do();
        log.next_round();
    }
    log.results();
}

void hello_func() {
    std::cout << " Товарищ, поздравляю вас с назначением на такое ответственное задание." << std::endl;
    std::cout << " В связи с вашим неожиданным назначением, думаю что вам необходима вводная информация по этому месту." << std::endl;
    std::cout << "Да/Нет" << std::endl;
    std::string in;
    std::cin >> in;
    if(in != "Нет") { // Туториал

    }
}

void game_cycle() {

}