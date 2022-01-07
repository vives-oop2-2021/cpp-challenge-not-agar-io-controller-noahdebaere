#pragma once
#include "player.h"

namespace NotAgarIOController {

    class Controller {

        public:
            void start(void);
        
        public:
            ~Controller(void);

        private:
            void main_menu(void);
            Menu build_main_menu(void);

        private:
            Player * currentPlayer = nullptr;

    };
};