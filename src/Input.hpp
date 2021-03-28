#ifndef SRC_INPUT_HPP
#define SRC_INPUT_HPP

#include <queue>
#include <thread>
#include <type_traits>

#include "src/CodeArch.hpp"
#include "src/Utils.hpp"
#include <iostream>

class Input {
public:

    using wide_char_t = unsigned;

private:
    
    static std::queue<wide_char_t> input_list_;

public:

    static std::size_t inputBufferSize() noexcept;

    static int getFirstInput() noexcept;

    /* EventDispatcher should have an unary function type */
    template <typename EventDispatcher,
        typename = std::enable_if_t<
            std::is_copy_assignable_v<EventDispatcher> ||
            std::is_move_assignable_v<EventDispatcher>
            >>
    static std::thread createListener(EventDispatcher && dispatcher) noexcept {
        return std::thread(
            std::bind([](EventDispatcher && _dispatcher) -> void {

            while(CodeArch::cgetCode().isRunning()) {

                input_list_.push(static_cast<wide_char_t>(getwchar()));

                _dispatcher();
            }

            return;
        }, std::forward<EventDispatcher>(dispatcher)));
    }

};

#endif // SRC_INPUT_HPP