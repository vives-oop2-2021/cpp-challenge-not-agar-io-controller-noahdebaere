#pragma once
#include <string>

namespace NotAgarIOController {

    class Player {

        public:
            Player (std::string username);
        
        public:
            std::string get_username(void);
        
        private:
            std::string username = "";
    };
};