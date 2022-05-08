#pragma once
#include "CLI/App.hpp"
#include "CLI/Config.hpp"
#include "CLI/Formatter.hpp"

namespace scftolus {
    enum class EXIT_CODE : int {
        SUCCESS          = 0,
        INTERNAL_FAILURE = 32,
        NOT_ENOUGH_ARGS  = 33
    };

    EXIT_CODE Main(int argc, char const* argv[]);

} // namespace scftolus
