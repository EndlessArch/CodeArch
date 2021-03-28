#ifndef SRC_WINDOW_HPP
#define SRC_WINDOW_HPP

#include <list>

class Window {

    ;

public:

    Window();

    static void initCurses() noexcept;

    static void endCurses() noexcept;

};

#endif // SRC_WINDOW_HPP