#pragma once
#include <filesystem>
#include <string>

class Configuration {
  public:
    bool        version_only;
    bool        is_debug;
    std::string scf_file_path;

  public:
    std::filesystem::path get_scf_path() const {
        return std::filesystem::path(this->scf_file_path);
    }
};
