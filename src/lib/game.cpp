#include <iostream>
#include "game.h"
#include "user_io.h"
#include "helpers/commands.h"

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
          case Commands::UNKNOWN:
            break;
        }
      } while (command != Commands::EXIT);
  }
};