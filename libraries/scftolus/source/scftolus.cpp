#include "scftolus.hpp"

namespace scftolus {
    int Main(int argc, char const* argv[]) {
        CLI::App app{"App description"};

        std::string filename = "default";
        app.add_option("--version", filename, "Prints externsion version and exit.");

        try {
            app.parse(argc, argv);
        } catch (const CLI::ParseError& e) {
            return app.exit(e);
        }
        return (int)CLI::ExitCodes::Success;
    }
} // namespace scftolus
