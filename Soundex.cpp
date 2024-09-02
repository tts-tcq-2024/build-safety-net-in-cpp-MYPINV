#include "Soundex.h"
#include <cctype>

// char getSoundexCode(char c) {
//     c = toupper(c);
//     switch (c) {
//         case 'B': case 'F': case 'P': case 'V': return '1';
//         case 'C': case 'G': case 'J': case 'K': case 'Q': case 'S': case 'X': case 'Z': return '2';
//         case 'D': case 'T': return '3';
//         case 'L': return '4';
//         case 'M': case 'N': return '5';
//         case 'R': return '6';
//         default: return '0'; // For A, E, I, O, U, H, W, Y 
//     }
// }

// Function to get the Soundex code for a given character
char getSoundexCode(char c) {
    static const char mapping[256] = {
        // Initialize with '0' for all characters
        ['A'] = '0', ['E'] = '0', ['I'] = '0', ['O'] = '0', ['U'] = '0',
        ['H'] = '0', ['W'] = '0', ['Y'] = '0', // Vowels and ignored letters
        ['B'] = '1', ['F'] = '1', ['P'] = '1', ['V'] = '1',
        ['C'] = '2', ['G'] = '2', ['J'] = '2', ['K'] = '2', ['Q'] = '2',
        ['S'] = '2', ['X'] = '2', ['Z'] = '2',
        ['D'] = '3', ['T'] = '3',
        ['L'] = '4',
        ['M'] = '5', ['N'] = '5',
        ['R'] = '6'
    };
    c = toupper(static_cast<unsigned char>(c)); // Ensure valid range for unsigned char
    return mapping[c];
}


std::string generateSoundex(const std::string& name) {
    if (name.empty()) return "";

    std::string soundex(1, toupper(name[0]));
    char prevCode = getSoundexCode(name[0]);

    for (size_t i = 1; i < name.length() && soundex.length() < 4; ++i) {
        char code = getSoundexCode(name[i]);
        if (code != '0' && code != prevCode) {
            soundex += code;
            prevCode = code;
        }
    }

    while (soundex.length() < 4) {
        soundex += '0';
    }

    return soundex;
}
