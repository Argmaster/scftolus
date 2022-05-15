#pragma once
#include <cstdio>
#include <exception>
#include <filesystem>
#include <iostream>
#include <memory>
#include <pugixml.hpp>
#include <cassert>

namespace scftolus {

    class XMLParseError : private std::exception {};

    class SCF_Handler {
      private:
        std::unique_ptr<pugi::xml_document>   doc;
        std::filesystem::path                  file_path;

      public:
        SCF_Handler(std::filesystem::path file_path);
    };
} // namespace scftolus
