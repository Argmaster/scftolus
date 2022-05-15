#pragma once
#include "scftolus/configuration.hpp"
#include "scftolus/scf_handler.hpp"
#include <CLI/App.hpp>
#include <CLI/Config.hpp>
#include <CLI/Formatter.hpp>
#include <memory>
#include <string>

namespace scftolus {
    int  Main(int argc, char const* argv[]);
    void Main(const Configuration& config);
} // namespace scftolus
