#include "menu_item.h"

namespace NotAgarIOController {

    MenuItem::MenuItem(std::string title, Screen nextScreen) {
        this->title = title;
        this->nextScreen = nextScreen;
    }

    std::string MenuItem::get_title(void) {
        return title;
    }

    Screen MenuItem::get_next_screen(void) {
        return nextScreen;
    }
};