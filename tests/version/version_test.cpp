/**
 * @file version_test.cpp
 * @brief Unit tests for SDL3_static_extensions::Version.
 */

#include "SDL3_static_extensions/version.hpp"

#include <gtest/gtest.h>
#include <string>
#include <string_view>

namespace
{

TEST(VersionTest, IsNonEmpty)
{
    const std::string_view version = SDL3_static_extensions::Version();
    EXPECT_FALSE(version.empty());
}

TEST(VersionTest, MatchesComponentConstants)
{
    // Version() is generated from the root VERSION file; constants must agree.
    const std::string expected = std::to_string(SDL3_static_extensions::kVersionMajor) + "." +
                                 std::to_string(SDL3_static_extensions::kVersionMinor) + "." +
                                 std::to_string(SDL3_static_extensions::kVersionPatch);
    EXPECT_EQ(std::string_view{SDL3_static_extensions::Version()}, expected);
    EXPECT_GE(SDL3_static_extensions::kVersionMajor, 0);
    EXPECT_GE(SDL3_static_extensions::kVersionMinor, 0);
    EXPECT_GE(SDL3_static_extensions::kVersionPatch, 0);
}

TEST(VersionTest, HasThreeNumericComponents)
{
    const std::string_view version = SDL3_static_extensions::Version();
    EXPECT_NE(version.find('.'), std::string_view::npos);
    EXPECT_NE(version.rfind('.'), std::string_view::npos);
    EXPECT_NE(version.find('.'), version.rfind('.'));
}

} // namespace
