#pragma once
#include "player.h"
#include "menu/main_menu.h"

namespace NotAgarIOController {

    class Controller {

        public:
            void start(void);
        
        public:
            ~Controller(void);

        private:
            void main_menu(void);
            MainMenu build_main_menu(void);

        private:
            Player * currentPlayer = nullptr;

    };
};