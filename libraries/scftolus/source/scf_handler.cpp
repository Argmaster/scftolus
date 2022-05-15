#include "scftolus/scf_handler.hpp"

namespace scftolus {

    SCF_Handler::SCF_Handler(std::filesystem::path file_path__) {
        if (!std::filesystem::exists(file_path__)) {
            throw ScfLoadingFailure(EXIT_CODES::SCF_FILE_DOESNT_EXIST,
                                    "File '{}' doesn't exist.",
                                    file_path__.c_str());
        }

        if (std::filesystem::is_directory(file_path__)) {
            throw ScfLoadingFailure(EXIT_CODES::SCF_IS_NOT_A_FILE,
                                    "'{}' is not a file, it's a directory.",
                                    file_path__.c_str());
        }
        this->file_path =
            std::filesystem::canonical(file_path__).make_preferred();

        this->doc = pugi::xml_document{};
        this->doc.load_file(file_path.c_str());
        auto node_set = this->doc.select_nodes("/module[@value='scf']");

        if (node_set.size() == 0) {
            throw ScfLoadingFailure(EXIT_CODES::SCF_LOADING_FAILED_NOT_FOUND,
                                    "Failed to find <module value=\"scf\"> "
                                    "section in XML file {0}",
                                    file_path.c_str());

        } else if (node_set.size() > 1) {
            throw ScfLoadingFailure(
                EXIT_CODES::SCF_LOADING_FAILED_AMBIGUOUS,
                "Total of {0} <module value=\"scf\"> sections in XML file "
                "{1} "
                "makes parsing ambiguous, can't proceed",
                node_set.size(), file_path.c_str());
        }

        this->scf_data = node_set[0].node();

        if (spdlog::get_level() == spdlog::level::debug) {
            std::stringstream ss;
            this->scf_data.print(ss);
            spdlog::info("Successfully loaded XML data from '{}' and found XML "
                         "<module value='scf'> node.\n{}",
                         this->file_path.c_str(), ss.str());
        }
    }
} // namespace scftolus
