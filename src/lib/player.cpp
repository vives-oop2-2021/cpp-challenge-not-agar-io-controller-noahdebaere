#include "player.h"

namespace NotAgarIOController {

    Player::Player(std::string username) {
        this->username = username;
    }

    std::string Player::get_username(void) {
        return username;
    }
};