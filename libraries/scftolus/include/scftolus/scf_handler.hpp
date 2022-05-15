#pragma once
#include "scftolus/descriptive_exception.hpp"
#include "scftolus/exit_codes.hpp"
#include <exception>
#include <filesystem>
#include <iostream>
#include <memory>
#include <pugixml.hpp>
#include <spdlog/spdlog.h>
#include <sstream>

namespace scftolus {

    class ScfLoadingFailure : public virtual DescriptiveException {
      public:
        using DescriptiveException::DescriptiveException;
    };

    class SCF_Handler {
      private:
        pugi::xml_document     doc;
        std::filesystem::path file_path;
        pugi::xml_node        scf_data;

      public:
        SCF_Handler(std::filesystem::path file_path);
    };
} // namespace scftolus
