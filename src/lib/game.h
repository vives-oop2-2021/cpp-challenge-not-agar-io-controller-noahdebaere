#pragma once
#include "player_manager.h"

namespace NotAgarIOController {

  class Game {

    public:
      Game(Player * player, PlayerManager * playerManager);

    public:
      void play(void);

    private:
      std::vector<std::string> split_command(std::string arguments);

    private:
      Player * player = nullptr;
      PlayerManager * playerManager = nullptr;
  };
};