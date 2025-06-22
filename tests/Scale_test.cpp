//
// Created by alexm on 2025-06-21.
//
#include <gtest/gtest.h>
#include "Scale.h"

TEST (ScaleTest, InvalidRootReturnsEmpty) {
    const auto majorScale = Scale(R"(data/scales/minor.json)");
    std::string root = "Q";
    std::vector<std::string> majorNotes = majorScale.getNotes(root);
    EXPECT_TRUE(majorNotes.empty()) << "Expected no root notes to be empty";

}