#include "CodeArch.hpp"

#include <thread>

#include <experimental/coroutine>

#include "Input.hpp"

CodeArch::editor_type & CodeArch::getCode() noexcept {
    static CodeArch myself;

    return myself;
}

CodeArch::ceditor_type & CodeArch::cgetCode() noexcept {
    return static_cast<ceditor_type &>(CodeArch::getCode());
}
#include <iostream>
int CodeArch::mainLoop( [[maybe_unused]] int cArg,
                        [[maybe_unused]] char ** vArg,
                        [[maybe_unused]] char ** vEnv) noexcept {
    ;

    { // initialization

        Window::initCurses();

        /* init window list */
        wList_.emplace_back();

        fLeave_ = false;
        signal_ = 0;

    }

    auto echoFunc = []() -> void {
        // for(int i = 0; i< Input::inputBufferSize(); ++i) {
        //     wchar_t wc = Input::getFirstInput();
        //     mvaddwstr(1, i, &wc);
        //     // mvaddwch(1, i, get_cchar(Input::getFirstInput(), 0, COLOR_PAIR(0)));
        // }
    };

    std::thread inputListener = Input::createListener(echoFunc);

    while(!fLeave_) {
        
        clear();

        std::this_thread::sleep_for(std::chrono::seconds(1));

        refresh();

    }

    // save files/data/etc..

    { // termination
        inputListener.join();

        Window::endCurses();
    }

    return signal_;
}

void CodeArch::exit(int signal) noexcept {

    signal_ = signal;
    fLeave_ = true;

    return;
}

bool CodeArch::isRunning() const noexcept {
    return !fLeave_;
}
