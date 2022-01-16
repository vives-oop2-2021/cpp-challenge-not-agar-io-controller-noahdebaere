#pragma once
#include <vector>
#include <string>
#include "player.h"

namespace NotAgarIOController {

  class PlayerManager {

    public:
      Player * get_player_by_username(std::string username);
      std::vector<Player *> get_all_players(void);

    public:
      ~PlayerManager(void);

    private:
      Player * add_player(std::string nickname);

    private:
      std::vector<Player *> players;
  };
};