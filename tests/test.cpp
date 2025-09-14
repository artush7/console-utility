#include <gtest/gtest.h>
#include "main.hpp"

TEST(console_utility, word)
{
    auto result = to_lower("Something");
    EXPECT_EQ(result,"something");
}
TEST(console_utility,line)
{
    std::string input = "one Two Apple";
    std::string expected = "Apple one Two";

    EXPECT_EQ(sort_line(input), expected);
}