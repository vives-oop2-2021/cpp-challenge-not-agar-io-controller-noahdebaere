#pragma once
#include <sstream>
#include <vector>
#include <string>
#include "player.h"

namespace NotAgarIOController {

    class Interact {

        public:
            static void move_blob(Player * player, std::string blobColor, std::string direction, unsigned int distance);

        private:
    };
};