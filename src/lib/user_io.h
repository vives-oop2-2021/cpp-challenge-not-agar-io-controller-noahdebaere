#pragma once
#include <string>
#include "menu/main_menu.h"

namespace NotAgarIOController {

  class UserIO {

    public:
      static void welcome_screen(void);
      static void game_instructions(void);
    
    public:
      static std::string get_username(void);
      static MenuItem get_menu_selection(Menu * menu);

    private:
      static void game_title(void);
      static void instructions(std::string instructions);
      static void screen_name(std::string name);
      static void content(std::vector<std::string> lines, bool centered=true);
      static void show_menu(Menu * menu, bool numbered=true);
      static void show_empty_boxed_lines(unsigned int count=1);
      static void show_boxed_text(std::string text, bool center=true);
      static void show_full_box_line(void);

    private:
      static void press_enter_to_continue(void);
      static std::string get_string_input(void);

    private:
      static const unsigned int WIDTH = 52;

  };

};