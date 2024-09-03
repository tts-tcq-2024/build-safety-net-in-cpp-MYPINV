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

TEST(SoundexTest, UnspecifiedCharacters) {
    EXPECT_EQ(generateSoundex("yhwh"), "Y000");
}


