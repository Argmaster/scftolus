#include "scftolus.hpp"

#define SCFTOLUS_VERSION "1.0.0"

namespace scftolus {
    int Main(int argc, char const* argv[]) {

        Configuration config;

        CLI::App app{"Luscus extension for scf format."};
        app.add_option("file_path", config.scf_file_path,
                       "Path to XML file containing SCF data.")
            ->required();
        app.add_flag("--version", config.version_only,
                     "Print extension version and exit.");
        CLI11_PARSE(app, argc, argv);

        if (config.version_only) {
            std::cout << SCFTOLUS_VERSION << std::endl;
            return 0;
        } else {
            auto        scf_path = config.get_scf_path();
            SCF_Handler scf_handler(scf_path);
        }

        return 0;
    }

} // namespace scftolus
