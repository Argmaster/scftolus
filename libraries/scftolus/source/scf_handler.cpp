#include "scf_handler.hpp"

namespace scftolus {

    SCF_Handler::SCF_Handler(std::filesystem::path file_path__)
        : doc(nullptr),
          file_path(file_path__) {

        this->doc = std::make_unique<pugi::xml_document>();
        assert(this->doc != nullptr);

        auto path_ptr = file_path.generic_string();
        this->doc->load_file(path_ptr.c_str());

        auto node_set = this->doc->select_nodes("/module[@value='scf']");
        if (node_set.size() == 0) {
            std::cout << "Failed to find scf component in XML file."
        }
        for (auto& val : node_set) {
            val.node().print(std::cout);
        }
    }
} // namespace scftolus
