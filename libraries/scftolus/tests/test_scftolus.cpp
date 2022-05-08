#include <gtest/gtest.h>
#include "scftolus.hpp"

namespace scftolus {

    class ScftolusTest : public ::testing::Test {};

    TEST_F(ScftolusTest, TestMainCallVersion) {
        const char* args[2] = {"path/to/exec", ""};
        auto  retval  = scftolus::Main(2, args);
    }

} // namespace scftolus
