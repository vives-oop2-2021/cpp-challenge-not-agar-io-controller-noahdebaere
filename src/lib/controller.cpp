#include "controller.h"
#include "user_io.h"

namespace NotAgarIOController {

    void Controller::start(void) {
        UserIO::welcome_screen();
        main_menu();
    }

    void Controller::main_menu(void) {
        MainMenu mainMenu = build_main_menu();
        Screen next;
        do {
            next = UserIO::get_menu_selection(&mainMenu).get_next_screen();

            switch (next) {
                case Screen::PLAY:
                    currentPlayer = playerManager.get_player_by_username(UserIO::get_username());
                    game = new Game(currentPlayer, &playerManager);
                    game->play();
                    break;
                case Screen::DIFFICULTY:
                    UserIO::to_do_screen();
                    break;
                case Screen::USERS:
                    UserIO::users_screen(&playerManager);
                    break;
                case Screen::REGISTER:
                    UserIO::register_screen();
                    break;
                case Screen::SCOREBOARD:
                    UserIO::to_do_screen();
                    break;
                case Screen::HELP:
                    UserIO::help_screen();
                    break;
                
                default:
                    break;
            }
        } while (next != Screen::EXIT);
        playerManager.quit();
        system("clear");
        lscreen.print();
    }

    MainMenu Controller::build_main_menu(void) {
        MainMenu mainMenu("Main Menu - Controller");
        mainMenu.add("Play New Game", Screen::PLAY);
        mainMenu.add("Set Difficulty", Screen::DIFFICULTY);
        mainMenu.add("Show All Players", Screen::USERS);
        mainMenu.add("Register New Player", Screen::REGISTER);
        mainMenu.add("Show Scoreboard", Screen::SCOREBOARD);
        mainMenu.add("Get Help (Noobie Status Achieved)", Screen::HELP);
        mainMenu.add("Exit The Controller", Screen::EXIT);

        return mainMenu;
    }

    Controller::~Controller(void) {
        delete game;        
    }
}