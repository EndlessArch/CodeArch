#include "Window.hpp"

#include "src/Utils.hpp"

Window::Window() {
    ;

    ;
}

void Window::initCurses() noexcept {
    
    initscr();
    echo();

}

void Window::endCurses() noexcept {

    endwin();

}