#include "terminal-help.h"
#include <cstdlib>

#ifdef __linux__
  #include <unistd.h>
  #include <termios.h>
  #include <iostream>
#elif _WIN32
  #include <conio.h>
#endif

namespace NotAgarIOController {

    // Windows implementation
#ifdef _WIN32

    Terminal::Key Terminal::pressed_key(void) {
        int key = _getch();
        if(key == 224) {
            key = _getch();
            switch (key) {
                case 72: return Key::UP;
                case 80: return Key::DOWN;
            }
        } else {
            switch (key) {
                case 13: return Key::ENTER;
            }
        }

        return Key::UNKNOWN;
    }
#endif

    void Terminal::clear(void) {
        system("clear");
    }

  // Linux implementation
#ifdef __linux__
  Terminal::Key Terminal::pressed_key(void) {
    int key = getch();
    if (key == 27 && getch() == 91) {
      key = getch();
      switch (key) {
        case 65: return Key::UP;
        case 66: return Key::DOWN;
      }
    } else {
      switch (key) {
        case 10: return Key::ENTER;
      }
    }
    return Key::UNKNOWN;
  }
#endif

#ifdef __linux__
  char Terminal::getch(void) {
    // Source: https://stackoverflow.com/questions/7469139/what-is-the-equivalent-to-getch-getche-in-linux
    char buf = 0;
    struct termios old = {0};
    fflush(stdout);
    if(tcgetattr(0, &old) < 0)
        perror("tcsetattr()");
    old.c_lflag &= ~ICANON;
    old.c_lflag &= ~ECHO;
    old.c_cc[VMIN] = 1;
    old.c_cc[VTIME] = 0;
    if(tcsetattr(0, TCSANOW, &old) < 0)
        perror("tcsetattr ICANON");
    if(read(0, &buf, 1) < 0)
        perror("read()");
    old.c_lflag |= ICANON;
    old.c_lflag |= ECHO;
    if(tcsetattr(0, TCSADRAIN, &old) < 0)
        perror("tcsetattr ~ICANON");
    return buf;
  }
#endif
};