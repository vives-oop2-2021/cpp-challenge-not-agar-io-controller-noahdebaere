#pragma once
#include <string>
#include "helpers/commands.h"
#include "menu/main_menu.h"
#include "player_manager.h"

namespace NotAgarIOController {

  class UserIO {

    public:
      static void welcome_screen(void);
      static void game_instructions(void);
      static void register_screen(void);
      static void help_screen(void);
      static void help_screen_in_game(void);
      static void users_screen(PlayerManager * playerManager);
      static void users_screen_in_game(PlayerManager * playerManager);
      static void to_do_screen(void);
      static void set_game_screen(void);
    
    public:
      static std::string get_username(void);
      static std::string get_user_command(void);
      static MenuItem get_menu_selection(MainMenu * menu);
      static Commands return_command_by_string_input(std::string command);

    private:
      static void game_title(void);
      static void game_title_without_clear(void);
      static void instructions(std::string instructions);
      static void screen_name(std::string name);
      static void show_content(std::vector<std::string> lines, bool centered=true);
      static void show_menu(MainMenu * menu, bool numbered=true);
      static void show_empty_boxed_lines(unsigned int count=1);
      static void show_boxed_text(std::string text, bool center=true);
      static void show_full_box_line(void);

    private:
      static void press_enter_to_continue(void);
      static std::string get_string_input(void);

    private:
      static const unsigned int WIDTH = 64;

  };

};