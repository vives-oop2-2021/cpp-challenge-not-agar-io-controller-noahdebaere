#include "game.h"
#include "user_io.h"

namespace NotAgarIOController {

  Game::Game(Player * player, PlayerManager * playerManager) {
      this->player = player;
      this->playerManager = playerManager;
  }

  void Game::play(void) {
    UserIO::show_game_instructions();
};