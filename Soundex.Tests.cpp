#include <gtest/gtest.h>
#include "Soundex.h"


TEST(SoundexTest, HandlesEmptyString) {
    EXPECT_EQ(generateSoundex(""), "");
}

TEST(SoundexTest, HandlesSingleCharacter) {
    EXPECT_EQ(generateSoundex("A"), "A000");
    EXPECT_EQ(generateSoundex("F"), "F000");
}

TEST(SoundexTest, AllVowels) {
    EXPECT_EQ(generateSoundex("Aeio"), "A000");
    EXPECT_EQ(generateSoundex("Euio"), "E000");
}

TEST(SoundexTest, UndefinedCharacters) {
    EXPECT_EQ(generateSoundex("yhwh"), "Y000");
}

TEST(SoundexTest, CaseInsensitive) {
    EXPECT_EQ(generateSoundex("SINGH"), "S520");
    EXPECT_EQ(generateSoundex("PriNcE"), "P652");
    EXPECT_EQ(generateSoundex("cAtS"), "C320");
}


