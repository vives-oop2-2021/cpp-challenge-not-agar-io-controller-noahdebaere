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
        command = UserIO::get_user_command();
        switch (command) {
          case Commands::HELP:
            UserIO::help_screen_in_game();
            break;
          case Commands::CLEAR:
            UserIO::set_game_screen();
            break;
          case Commands::PLAYERS:
            UserIO::users_screen_in_game(&playerManager);
            break;
          case Commands::UNKNOWN:
            break;
        }
      } while (command != Commands::EXIT);
  }
};