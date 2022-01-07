#pragma once
#include "player.h"
#include "menu/main_menu.h"
#include "player_manager.h"
#include "game.h"
#include "menu/loading-screen.h"

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
            Game * game = nullptr;
            PlayerManager playerManager;
            LoadingScreen lscreen;

    };
};