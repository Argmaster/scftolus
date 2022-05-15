#include "scftolus/scftolus.hpp"

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
        app.add_flag("--debug", config.is_debug,
                     "Use debug mode with extensive logging.");
        CLI11_PARSE(app, argc, argv);

        if (config.version_only) {
            std::cout << SCFTOLUS_VERSION << std::endl;
            return (int)EXIT_CODES::SUCCESS;
        }
        try {
            Main(config);
        } catch (const DescriptiveException& e) {
            auto exit_code = e.get_exit_code();
            if (exit_code == 0) {
                spdlog::info(e.what());
            } else if (exit_code >= 5000 && exit_code < 10000) {
                spdlog::warn(e.what());
            } else if (exit_code >= 10000 && exit_code < 15000) {
                spdlog::error(e.what());
            }
            return exit_code;
        }
        return (int)EXIT_CODES::SUCCESS;
    }

    void Main(const Configuration& config) {
        if (config.is_debug) {
            spdlog::set_level(spdlog::level::debug);
        } else {
            spdlog::set_level(spdlog::level::off);
        }
        SCF_Handler scf_handler{config.get_scf_path()};
    }
} // namespace scftolus
