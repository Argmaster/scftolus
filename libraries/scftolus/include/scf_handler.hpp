#pragma once
#include "descriptive_exception.hpp"
#include "exit_codes.hpp"
#include <cassert>
#include <cstdio>
#include <exception>
#include <filesystem>
#include <iostream>
#include <memory>
#include <pugixml.hpp>
#include <spdlog/spdlog.h>

namespace scftolus {

    class ScfLoadingFailure : public virtual DescriptiveException {
      public:
        using DescriptiveException::DescriptiveException;
    };

    class SCF_Handler {
      private:
        std::unique_ptr<pugi::xml_document> doc;
        std::filesystem::path               file_path;

      public:
        SCF_Handler(std::filesystem::path file_path);
    };
} // namespace scftolus
