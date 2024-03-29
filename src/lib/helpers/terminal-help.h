#pragma once

namespace NotAgarIOController {

    class Terminal {

        public: enum Key {
            UP,
            DOWN,
            ENTER,
            UNKNOWN
        };

        public:
            static Key pressed_key(void);
            static void clear(void);

#ifdef __linux__
      static char getch(void);
#endif

    };
};