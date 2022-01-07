#include "main_menu.h"

namespace NotAgarIOController {

    MainMenu::MainMenu(std::string title) {
        this->title = title;
    }

    void MainMenu::add(std::string item, Screen nextScreen) {
        menuItems.push_back({item, nextScreen});
        currentlySelected = 0;
    }

    std::vector<std::string> MainMenu::get_title_items(void) {
        std::vector<std::string> items;
        for (auto && item : menuItems) {
            items.push_back(item.get_title());
        }
        return items;
    }

    void MainMenu::next_item(void) {
        currentlySelected = ((currentlySelected + 1) % menuItems.size());
    }

    void MainMenu::previous_item(void) {
        currentlySelected--;
        if(currentlySelected < 0) {
            currentlySelected = menuItems.size() - 1;
        }
    }

    MenuItem MainMenu::get_selected_item(void) {
        if (currentlySelected < 0) return {"", Screen::NOT_SET};

        return menuItems[currentlySelected];
    }
    std::string MainMenu::get_title(void) {
        return title;
    }
};