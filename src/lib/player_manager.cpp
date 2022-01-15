#include "player_manager.h"

namespace NotAgarIOController {

  Player * PlayerManager::get_player_by_username(std::string username) {
    for (auto && player : players) {
      if (player->get_username() == username) {
        return player;
      }
    }

    return add_player(username);
  }

  Player * PlayerManager::add_player(std::string username) {
    Player * player = new Player(username);
    players.push_back(player);
    return player;
  }

  PlayerManager::~PlayerManager(void) {
    for (unsigned int i = 0; i < players.size(); i++) {
      delete players[i];
      players[i] = nullptr;
    }
    players.clear();
  }
};