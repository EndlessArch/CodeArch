#ifndef SRC_CODEARCH_HPP
#define SRC_CODEARCH_HPP

#include <list>

#include "src/Window.hpp"

class CodeArch final {

    std::list<Window> wList_;

    bool fLeave_;
    int signal_;

public:

    using editor_type = CodeArch;
    using ceditor_type = const CodeArch;

    ~CodeArch() = default;

    static
    editor_type & getCode() noexcept;

    static
    ceditor_type & cgetCode() noexcept;

    /* main loop */
    int mainLoop(int, char **, char **) noexcept;

    /* exit with signal integer */
    void exit(int) noexcept;

    bool isRunning() const noexcept;

private:

    explicit CodeArch() {}

};

#endif // SRC_CODEARCH_HPP