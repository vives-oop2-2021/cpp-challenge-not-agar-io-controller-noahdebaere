#include <iostream>
#include <sstream>
#include "game.h"
#include "user_io.h"
#include "helpers/commands.h"
#include "interact.h"

namespace NotAgarIOController {

  Game::Game(Player * player, PlayerManager * playerManager) {
      this->player = player;
      this->playerManager = playerManager;
  }

  void Game::play(void) {
      UserIO::game_instructions();
      UserIO::set_game_screen();
      Commands command;
      do {
        std::string fullCommand = UserIO::get_user_command();
        command = UserIO::return_command_by_string_input(fullCommand);
        switch (command) {
          case Commands::HELP:
            UserIO::help_screen_in_game();
            break;
          case Commands::CLEAR:
            UserIO::set_game_screen();
            break;
          case Commands::PLAYERS:
            UserIO::users_screen_in_game(this->playerManager);
            break;
          case Commands::REGISTER:
            this->playerManager->get_player_by_username(fullCommand.substr(9));
            break;
          case Commands::MOVE:
            Interact::move_blob(player, split_command(fullCommand)[1], split_command(fullCommand)[2], std::stoi(split_command(fullCommand)[3]));
            break;
          case Commands::SHOOT:
            break;

          default:
            break;
        }
      } while (command != Commands::EXIT);
  }

  std::vector<std::string> Game::split_command(std::string command) {
    std::vector<std::string> arguments;
    std::stringstream temp(command);
    std::string word;
    while(temp >> word) {
      arguments.push_back(word);
    }
    return arguments;
  }

};