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
    // Mapping array for Soundex codes
    static char mapping[256];
    static bool initialized = false;

    // Initialize the mapping array only once
    if (!initialized) {
        for (int i = 0; i < 256; ++i) {
            mapping[i] = '0'; // Default value for non-specified characters
            cout << mapping[i] << endl;
        }
        // Define specific mappings
        mapping['B'] = mapping['F'] = mapping['P'] = mapping['V'] = '1';
        mapping['C'] = mapping['G'] = mapping['J'] = mapping['K'] = mapping['Q'] = mapping['S'] = mapping['X'] = mapping['Z'] = '2';
        mapping['D'] = mapping['T'] = '3';
        mapping['L'] = '4';
        mapping['M'] = mapping['N'] = '5';
        mapping['R'] = '6';
        initialized = true;
    }

    // Convert character to uppercase
    c = toupper(static_cast<unsigned char>(c));
    cout << endl << mapping[c];
    // Return the corresponding Soundex code
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
