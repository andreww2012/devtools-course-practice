// Copyright 2017 Kazakov Andrew

#include <gtest/gtest.h>

#include "include/regex_search.h"

//
// Create
//

TEST(RegexSearchTest, can_initialize_with_empty_regexp) {
    // Assert
    ASSERT_NO_THROW(RegexSearch rs);
}

TEST(RegexSearchTest, can_initialize_with_not_empty_regexp) {
    // Assert
    ASSERT_NO_THROW(RegexSearch rs("^abc$"));
}

TEST(RegexSearchTest, can_use_copy_constructor) {
    // Arrange
    RegexSearch rs1("^abc$");

    // Act & Assert
    ASSERT_NO_THROW(RegexSearch rs2(rs1));
}

TEST(RegexSearchTest, can_use_operator_equal) {
    // Arrange
    RegexSearch rs1, rs2("^abc$");

    // Act & Assert
    ASSERT_NO_THROW(rs1 = rs2);
}

//
// Set & Get
//

TEST(RegexSearchTest, can_get_regexp) {
    // Arrange
    RegexSearch rs("^abc$");

    // Act & Assert
    ASSERT_NO_THROW(rs.GetRegex());
}

TEST(RegexSearchTest, can_set_regex) {
    // Arrange
    RegexSearch rs;

    // Act & Assert
    ASSERT_NO_THROW(rs.SetRegex("^abc$"));
}

TEST(RegexSearchTest, get_regex_works_properly) {
    // Arrange
    RegexSearch rs("^abc$");
    std::string rx;

    // Act
    rx = rs.GetRegex();

    // Assert
    EXPECT_EQ(rx, "^abc$");
}

TEST(RegexSearchTest, set_regex_works_properly) {
    // Arrange
    RegexSearch rs;

    // Act
    rs.SetRegex("^abc$");

    // Assert
    EXPECT_EQ(rs.GetRegex(), "^abc$");
}

TEST(RegexSearchTest, copy_constructor_works_properly) {
    // Arrange
    RegexSearch rs1("^abc$");

    // Act
    RegexSearch rs2(rs1);

    // Assert
    EXPECT_EQ(rs2.GetRegex(), "^abc$");
}

TEST(RegexSearchTest, operator_equal_works_properly) {
    // Arrange
    RegexSearch rs1("^abc$"), rs2;

    // Act
    rs2 = rs1;

    // Assert
    EXPECT_EQ(rs2.GetRegex(), "^abc$");
}

//
// Find
//

TEST(RegexSearchTest, can_use_find) {
    // Arrange
    RegexSearch rs("\\b(te)([^ ]*)");
    std::string text;

    // Act
    text = "Some test text.";

    // Assert
    ASSERT_NO_THROW(rs.Find(text));
}

TEST(RegexSearchTest, can_use_find_in_file) {
    // Arrange
    RegexSearch rs("\\b(te)([^ ]*)");
    std::string text;

    // Act
    text = "test_data.txt";

    // Assert
    ASSERT_NO_THROW(rs.FindInFile(text));
}

TEST(RegexSearchTest, it_finds_all_matches_in_text) {
    // Arrange
    RegexSearch rs("\\b(te)([^ ]*)");
    std::string text;

    // Act
    text = "Some test text.";

    // Assert
    ASSERT_EQ(rs.Find(text).size(), 4);
}

TEST(RegexSearchTest, it_finds_all_matches_in_file) {
    // Arrange
    RegexSearch rs("\\b(te)([^ ]*)");
    std::string text;
    std::ofstream out("test_regex-search_data.txt");

    // Act
    out << "This is a test text. Test text, text test." << std::endl;
    text = "test_regex-search_data.txt";

    // Assert
    ASSERT_EQ(rs.FindInFile(text).size(), 10);
}
