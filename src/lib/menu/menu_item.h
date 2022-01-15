#pragma once
#include <string>
#include "screen.h"

namespace NotAgarIOController {

    class MenuItem {

        public:
            MenuItem(std::string title, Screen nextScreen);
        
        public:
            std::string get_title(void);
            Screen get_next_screen(void);

        private:
            std::string title = "";
            Screen nextScreen = Screen::NOT_SET;
    };
};