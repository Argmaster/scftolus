#include "scf_handler.hpp"

namespace scftolus {

    SCF_Handler::SCF_Handler(std::filesystem::path file_path__)
        : doc(nullptr),
          file_path(file_path__) {

        this->doc = std::make_unique<pugi::xml_document>();
        assert(this->doc != nullptr);

        this->doc->load_file(file_path.c_str());

        auto node_set = this->doc->select_nodes("/module[@value='scf']");
        if (node_set.size() == 0) {
            throw ScfLoadingFailure(EXIT_CODES::SCF_LOADING_FAILED_NOT_FOUND,
                                    "Failed to find <module value=\"scf\"> "
                                    "section in XML file {0}",
                                    file_path.c_str());

        } else if (node_set.size() > 1) {
            throw ScfLoadingFailure(
                EXIT_CODES::SCF_LOADING_FAILED_AMBIGUOUS,
                "Total of {0} <module value=\"scf\"> sections in XML file {1} "
                "makes parsing ambiguous, can't proceed",
                node_set.size(), file_path.c_str());
        }

        for (auto& val : node_set) {
            val.node().print(std::cout);
        }
    }
} // namespace scftolus
