#include <gtest/gtest.h>
#include "Soundex.h"

TEST(SoundexTest, SimpleName) {
    EXPECT_EQ(generateSoundex("Smith"), "S530");
}

TEST(SoundexTest, VowelsIgnored) {
    EXPECT_EQ(generateSoundex("Smyth"), "S530");
}

TEST(SoundexTest, RepeatingConsonants) {
    EXPECT_EQ(generateSoundex("Ashcraft"), "A261");
}

TEST(SoundexTest, ShortName) {
    EXPECT_EQ(generateSoundex("Li"), "L000");
}

TEST(SoundexTest, SingleLetterName) {
    EXPECT_EQ(generateSoundex("A"), "A000");
}

TEST(SoundexTest, EmptyString) {
    EXPECT_EQ(generateSoundex(""), "");
}

TEST(SoundexTest, CaseInsensitive) {
    EXPECT_EQ(generateSoundex("Washington"), generateSoundex("washington"));
}

TEST(SoundexTest, NonMatchingLetters) {
    EXPECT_EQ(generateSoundex("Aeio"), "A000");
}

TEST(SoundexTest, NameWithSpaces) {
    EXPECT_EQ(generateSoundex("  "), "");
}



