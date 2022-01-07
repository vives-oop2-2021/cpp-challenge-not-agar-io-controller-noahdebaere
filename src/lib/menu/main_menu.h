#pragma once
#include <vector>
#include <string>
#include "menu_item.h"

namespace NotAgarIOController {

    class MainMenu {

        public:
            MainMenu(std::string title);

        public:
            void add(std::string item, Screen nextScreen);
            std::vector<std::string> get_title_items(void);

        public:
            void next_item(void);
            void previous_item(void);
            MenuItem get_selected_item(void);
            std::string get_title(void);
        
        private:
            std::string title = "";
            std::vector<MenuItem> menuItems;
            int currentlySelected = -1;
    };
};
