#include "controller.h"

namespace NotAgarIOController {

    void Controller::start(void) {
        main_menu();
    }

    void Controller::main_menu(void) {
        MainMenu mainMenu = build_main_menu();

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