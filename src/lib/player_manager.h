#pragma once
#include <vector>
#include <string>
#include "player.h"

namespace NotAgarIOController {

  class PlayerManager {

    public:
      PlayerManager(void);

    public:
      void quit(void);

    public:
      Player * get_player_by_username(std::string username);
      std::vector<Player *> get_all_players(void);

    public:
      ~PlayerManager(void);

    private:
      Player * add_player(std::string username);
      void read_existant_users_from_file(void);
      void write_users_to_file(void);

    private:
      const std::string PATH = "./users/users.txt";
      std::vector<Player *> players;
  };
};