#include <gtest/gtest.h>
#include "Soundex.h"

TEST(SoundexTest, HandlesSimpleName) {
    EXPECT_EQ(generateSoundex("Smith"), "S530");
}

TEST(SoundexTest, VowelAndNonMappedLettersIgnored) {
    EXPECT_EQ(generateSoundex("Smyth"), "S530");
}

TEST(SoundexTest, HandlesRepeatingConsonants) {
    EXPECT_EQ(generateSoundex("Ashcraft"), "A261");
}

TEST(SoundexTest,  HandlesShortName) {
    EXPECT_EQ(generateSoundex("Li"), "L000");
}

TEST(SoundexTest,  HandlesSingleLetterName) {
    EXPECT_EQ(generateSoundex("A"), "A000");
}

TEST(SoundexTest, HandlesEmptyString) {
    EXPECT_EQ(generateSoundex(""), "");
}

TEST(SoundexTest, CaseInsensitive) {
    EXPECT_EQ(generateSoundex("Washington"), generateSoundex("washington"));
}

TEST(SoundexTest, HandlesNonMappedLetters) {
    EXPECT_EQ(generateSoundex("Aeio"), "A000");
}

TEST(SoundexTest, HandlesNameWithSpaces) {
    EXPECT_EQ(generateSoundex("  "), "");
}



