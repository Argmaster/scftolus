#include <exception>
#include <fmt/core.h>
#include <scftolus/exit_codes.hpp>
#include <string>

namespace scftolus {

    class DescriptiveException : private std::exception {
      private:
        std::string description;
        EXIT_CODES  exit_code;

      public:
        DescriptiveException()
            : description("Unknown exception occurred."),
              exit_code(EXIT_CODES::SCF_UNKNOWN_FAILURE) {}

        DescriptiveException(std::string description_)
            : description(description_),
              exit_code(EXIT_CODES::SCF_UNKNOWN_FAILURE) {}

        DescriptiveException(EXIT_CODES exit_code_, std::string description_)
            : description(description_),
              exit_code(exit_code_) {}

        template <typename... Args>
        DescriptiveException(std::string description_, Args... args)
            : description(fmt::format(description_, args...)),
              exit_code(EXIT_CODES::SCF_UNKNOWN_FAILURE) {}

        template <typename... Args>
        DescriptiveException(EXIT_CODES exit_code_, std::string description_,
                             Args... args)
            : description(fmt::format(description_, args...)),
              exit_code(exit_code_) {}

        virtual ~DescriptiveException() {}

        virtual const char* what() const throw() {
            return this->description.c_str();
        }
        virtual int get_exit_code() const {
            return (int)this->exit_code;
        }
    };
} // namespace scftolus
