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
                    break;
                case Screen::DIFFICULTY:
                    break;
                case Screen::USERS:
                    break;
                case Screen::REGISTER:
                    break;
                case Screen::SCOREBOARD:
                    break;
                case Screen::HELP:
                    break;
                
                default:
                    break;
            }
        } while (next != Screen::EXIT);
    }

    MainMenu Controller::build_main_menu(void) {
        MainMenu mainMenu("Main Menu - Not Agar.io Controller");
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
        
    }
}