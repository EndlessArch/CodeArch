#include <iostream>

#include "src/CodeArch.hpp"

int main(int argc, char * argv[], char * envv[]) {

    // TODO: Locales

    return CodeArch::getCode().mainLoop(argc, argv, envv);
}