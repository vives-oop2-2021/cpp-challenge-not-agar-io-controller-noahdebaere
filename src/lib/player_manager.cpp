#include <iostream>
#include <fstream>
#include "player_manager.h"

namespace NotAgarIOController {

  PlayerManager::PlayerManager(void) {
    read_existant_users_from_file();
  }

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

  std::vector<Player *> PlayerManager::get_all_players(void) {
    return this->players;
  }

  void PlayerManager::read_existant_users_from_file(void) {
    std::ifstream input;
    input.open(this->PATH); // Default ios::in

    if(!input) {
      std::cerr << "Something went wrong..." << std::endl;
      return;
    }

    std::string user;
    while (getline(input, user)) {
      add_player(user);
    }

    input.close();
  }

  void PlayerManager::write_users_to_file(void) {
    std::ofstream output;
    output.open(this->PATH, std::ios::out);

    if(!output) {
      std::cerr << "Something went wrong..." << std::endl;
    }

    for (auto && player : this->players) {
      output << player->get_username() << std::endl;
    }

    output.close();
  }

  void PlayerManager::quit(void) {
    write_users_to_file();
  }


  PlayerManager::~PlayerManager(void) {
    for (unsigned int i = 0; i < players.size(); i++) {
      delete players[i];
      players[i] = nullptr;
    }
    players.clear();
  }
};