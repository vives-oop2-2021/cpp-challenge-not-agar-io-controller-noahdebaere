#include "terminal-help.h"
#include <cstdlib>
#include <conio.h> // Only Windows, TODO implement Linux terminal game

namespace NotAgarIOController {

    Terminal::Key Terminal::pressed_key(void) {
        int key = getch();
        if(key == 0) {
            key = getch();
            switch (key) {
                case 72: return Key::UP;
                case 80: return Key::DOWN;
            }
        } else {
            switch (key) {
            case 13: return Key::ENTER;
            }
        }

        return Key::UNKNOWN;
    }

    void Terminal::clear(void) {
        system("clear");
    }
};