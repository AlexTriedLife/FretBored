//
// Created by alexm on 2025-06-21.
//
#include <gtest/gtest.h>
#include <iostream>
#include "Scale.h"

TEST (ScaleTest, InvalidRootReturnsEmpty) {
    const auto minorScale = Scale(R"(../data/scales/minor.json)");
    std::string root = "Q";
    std::vector<std::string> minorNotes = minorScale.getNotes(root);
    EXPECT_TRUE(minorNotes.empty()) << "Expected no root notes to be empty";
}
TEST (ScaleTest, validMajorScale) {
    const auto majorScale = Scale(R"(../data/scales/major.json)");
    std::string root = "C";
    std::vector<std::string> majorNotes = majorScale.getNotes(root);
    std::vector<std::string> correctScale = {"C","D","E","F","G","A","B"};
    ASSERT_EQ(majorNotes, correctScale);
}
TEST (ScaleTest, validMinorScale) {
    const auto minorScale = Scale(R"(../data/scales/minor.json)");
    std::string root = "A";
    std::vector<std::string> minorNotes = minorScale.getNotes(root);
    std::vector<std::string> correctScale = {"A","B","C","D","E","F","G"};
    ASSERT_EQ(minorNotes, correctScale);
}

