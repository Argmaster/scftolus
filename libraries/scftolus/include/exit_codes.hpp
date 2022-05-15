#pragma once

namespace scftolus {
    enum class EXIT_CODES : int {
        SCF_NULL_PTR_FAILURE         = -0xFFE,
        SCF_UNKNOWN_FAILURE          = -0xFFF,
        SCF_LOADING_FAILED_NOT_FOUND = -0x1000,
        SCF_LOADING_FAILED_AMBIGUOUS = -0x1001,
    };
} // namespace scftolus
