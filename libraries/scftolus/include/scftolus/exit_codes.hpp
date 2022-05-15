#pragma once

namespace scftolus {
    enum class EXIT_CODES : int {
        // Fatal errors, 0, logs as info
        SUCCESS                      = 0,
        // Warnings, range <5000, 10000), logs as warning
        // Fatal errors, range <10000, 15000), logs as error
        SCF_NULL_PTR_FAILURE         = 10000,
        SCF_UNKNOWN_FAILURE          = 10001,
        SCF_LOADING_FAILED_NOT_FOUND = 10002,
        SCF_LOADING_FAILED_AMBIGUOUS = 10003,
        SCF_FILE_DOESNT_EXIST        = 10004,
        SCF_IS_NOT_A_FILE            = 10005,
    };
} // namespace scftolus
