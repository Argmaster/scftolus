#include "scftolus.hpp"

#define SCFTOLUS_VERSION "1.0.0"

namespace scftolus {
    int Main(int argc, char const* argv[]) {

        Configuration config;

        CLI::App app{"Luscus extension for scf format."};
        app.add_flag("--version", config.version_only,
                     "Print extension version and exit.");
        CLI11_PARSE(app, argc, argv);

        if (config.version_only) {
            std::cout << SCFTOLUS_VERSION << std::endl;
            return 0;
        }

        return 0;
    }
} // namespace scftolus
