#include "user_io.h"
#include <iostream>
#include "helpers/terminal-help.h"
#include "helpers/string-help.h"

using namespace std;

namespace NotAgarIOController {


  void UserIO::welcome_screen(void) {
    game_title();
    instructions("PRESS ENTER TO CONTINUE");

    std::vector<std::string> content;
    content.push_back("This terminal application serves as the controller for the Not Agar.io Game!");
    content.push_back("");
    content.push_back("Be mindful, this game has been tested on both Windows and Ubuntu terminals");
    content.push_back("");
    content.push_back("Have fun playing and eating blobs :)");
    show_content(content);

    press_enter_to_continue();
  }

  void UserIO::help_screen(void) {
    game_title();
    instructions("Below you can find all of the commands necessary for using the controller!");

    std::vector<std::string> content;
    content.push_back("\"help\" - show the available commands");
    content.push_back("");
    content.push_back("\"clear\" - clears the terminal");
    content.push_back("");
    content.push_back("\"register <username>\" - register a player in the game");
    content.push_back("");
    content.push_back("\"players\" - get a list of all players");
    content.push_back("");
    content.push_back("\"move <blob> <direction> <distance>\" - move your blob around");
    content.push_back("");
    content.push_back("\"shoot <your_blob> <username> <their_blob>\" - shoot an enemies' blob");
    content.push_back("");
    content.push_back("\"exit\" - exit the game and go back to the main menu");
    content.push_back("");
    content.push_back("Press ENTER to go back!");

    show_content(content);
    press_enter_to_continue();
  }

  void UserIO::help_screen_in_game(void) {
    game_title_without_clear();
    instructions("Below you can find all of the commands necessary for using the controller!");

    std::vector<std::string> content;
    content.push_back("\"help\" - show the available commands");
    content.push_back("");
    content.push_back("\"clear\" - clears the terminal");
    content.push_back("");
    content.push_back("\"register <username>\" - register a player in the game");
    content.push_back("");
    content.push_back("\"players\" - get a list of all players");
    content.push_back("");
    content.push_back("\"move <blob> <direction> <distance>\" - move your blob around");
    content.push_back("");
    content.push_back("\"shoot <your_blob> <username> <their_blob>\" - shoot an enemies' blob");
    content.push_back("");
    content.push_back("\"exit\" - exit the game and go back to the main menu");

    show_content(content);
  }

  void UserIO::to_do_screen(void) {
    game_title();
    instructions("!THIS PAGE IS STILL UNDER CONSTRUCTION!");

    std::vector<std::string> content;
    content.push_back("TO DO...");
    content.push_back("");
    content.push_back("Press ENTER to go back!");

    show_content(content); 
    press_enter_to_continue();
  }

  void UserIO::set_game_screen(void) {
    game_title();
    instructions("Type your next command in the terminal below! Type \"help\" for more information...");
  }

  Commands UserIO::get_user_command(void) {
    std::string command = "";
    Commands nextCommand;
    do {
      cout << endl << "not-agar.io controller|>  ";
      command = get_string_input();
      nextCommand = return_command_by_string_input(command);
    } while(command == "");

    return nextCommand;    
  }
  
  std::string UserIO::get_username(void) {
    std::string username = "";
    do {
      game_title();
      instructions("Please enter the username with which you would like to play.");

      cout << endl << "Username: ";
      username = get_string_input();
    } while(username == "");

    return username;
  }

  MenuItem UserIO::get_menu_selection(MainMenu * menu) {
    Terminal::Key key;
    do {
      game_title();
      instructions("Use the arrow keys to navigate through the menu and ENTER to select an item.");
      screen_name(menu->get_title());
      show_menu(menu);
      key = Terminal::pressed_key();
      if (key == Terminal::Key::DOWN) {
        menu->next_item();
      } else if (key == Terminal::UP) {
        menu->previous_item();
      }
    } while (key != Terminal::Key::ENTER);

    return menu->get_selected_item();
  }

  void UserIO::game_instructions(void) {
    game_title();
    instructions("PRESS ENTER TO START");
    screen_name("Instructions");

    std::vector<std::string> content;
    content.push_back("Use the commands to attack other players their blobs and destroy them!");
    content.push_back("");
    content.push_back("Hit ENTER to start typing your commands to attack the other blobs <_<");
    show_content(content);

    press_enter_to_continue();
  }

  void UserIO::game_title(void) {
    Terminal::clear();
    show_full_box_line();
    show_boxed_text("Not Agar.io Controller - Noah Debaere");
    show_full_box_line();
  }

  void UserIO::game_title_without_clear(void) {
    show_full_box_line();
    show_boxed_text("Not Agar.io Controller - Noah Debaere");
    show_full_box_line();
  }

  void UserIO::instructions(std::string instructions) {
    show_empty_boxed_lines();
    show_boxed_text(instructions);
    show_empty_boxed_lines();
    show_full_box_line();
  }

  void UserIO::screen_name(std::string name) {
    show_boxed_text(name);
    show_full_box_line();
  }

  void UserIO::show_content(std::vector<std::string> lines, bool centered) {
    show_empty_boxed_lines();
    for (auto && line : lines) {
      show_boxed_text(line, centered);
    }
    show_empty_boxed_lines();
    show_full_box_line();
  }

  void UserIO::show_menu(MainMenu * menu, bool numbered) {
    std::vector<std::string> content = menu->get_title_items();

    for (unsigned int i = 0; i < content.size(); i++) {
      std::string prefix = "";
      if (menu->get_selected_item().get_title() == content[i]) {
        prefix = "   ==> ";
      } else {
        prefix = "       ";
      }

      if (numbered) {
        prefix = prefix + std::to_string(i+1) + ". ";
      }
      content[i] = prefix + content[i];
    }
    show_content(content, false);
  }

  void UserIO::press_enter_to_continue(void) {
    get_string_input();
  }

  std::string UserIO::get_string_input(void) {
    std::string input;
    getline(cin, input);
    return input;
  }

  Commands UserIO::return_command_by_string_input(std::string command) {
    if (command == "help") {
      return Commands::HELP;
    } else if (command == "exit") {
      return Commands::EXIT;
    } else if (command == "players") {
      return Commands::PLAYERS;
    } else if (command == "clear") {
      return Commands::CLEAR;
    } else if (command == "exit") {
      return Commands::EXIT;
    } else if (command.substr(0,7) == "register") {
      return Commands::REGISTER;
    } else if (command.substr(0,3) == "move") {
      return Commands::MOVE;
    } else if (command.substr(0,4) == "shoot") {
      return Commands::SHOOT;
    } else {
      cout << "Unknown command, please fix your typo or enter \"help\" to see all valid commands..." << endl;
      return Commands::UNKNOWN;
    }
  }

  void UserIO::show_boxed_text(std::string text, bool center) {
    std::vector<std::string> lines = StringHelper::wrap_text(text, WIDTH-4);
    for (auto && line : lines) {
      if (center) {
        cout << "| " << StringHelper::center_text(line, WIDTH-4) << " |" << endl;
      } else {
        cout << "| " << StringHelper::pad_text(line, WIDTH-4) << " |" << endl;
      }
    }
  }

  void UserIO::show_empty_boxed_lines(unsigned int count) {
    for (unsigned int i = 0; i < count; i++) {
      cout << "|" << StringHelper::generate_single_character_string(' ', WIDTH-2) << "|" << endl;
    }
  }

  void UserIO::show_full_box_line(void) {
    cout << StringHelper::generate_single_character_string('-', WIDTH) << endl;
  }

};