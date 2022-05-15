#pragma once
#include <CLI/App.hpp>
#include <CLI/Config.hpp>
#include <CLI/Formatter.hpp>
#include <filesystem>
#include <string>

class Configuration {
  public:
    bool        version_only;
    std::string scf_file_path;

  public:
    std::filesystem::path get_scf_path() {
        return std::filesystem::canonical(this->scf_file_path)
            .make_preferred();
    }
};
