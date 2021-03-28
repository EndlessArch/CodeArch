#include "Input.hpp"

std::queue<Input::wide_char_t> Input::input_list_;

std::size_t Input::inputBufferSize() noexcept {
    return input_list_.size();
}

int Input::getFirstInput() noexcept {
    auto result = input_list_.back();
    input_list_.pop();
    return result;
}