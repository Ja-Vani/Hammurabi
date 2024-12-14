//
// Created by Ja_Vani on 22.09.2024.
//

#include <fcntl.h>
#include <menu.h>

#include "logic.h"

constinit uint8_t rounds = 10;

int main(int argc, char *argv[]) {
    bool start_info = true;
    _setmode(_fileno(stdout), _O_U16TEXT);
    _setmode(_fileno(stdin), _O_U16TEXT);
    _setmode(_fileno(stderr), _O_U16TEXT);
    if (argc >= 2) {
        for (int i = 1; i < argc; i++) {
            if (!strcmp(argv[i], "-ns")) {
                // none start
                start_info = false;
            }
            if (!strcmp(argv[i], "--rounds")) {
                if (argc < ++i) {
                    rounds = atoi(argv[i]);
                } else {
                    break;
                }
            }
        }
    }
    Menu menu(start_info, Logic(rounds));
    menu.load_game();
    do {
        menu.round_info();
        menu.game_continue();
        menu.player_do();
    } while (menu.next_round());
    menu.results();
}
