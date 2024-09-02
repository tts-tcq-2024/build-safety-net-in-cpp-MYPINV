#include "Soundex.h"
#include <cctype>
#include <cstring>

using namespace std;

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

// pure function to check if the input 'name' is empy
bool isNameEmpty(const std::string& name) {
    return name.empty();
}

// pure function to convert the first character of input 'name' to uppercase
char getFirstCharacterUppercase(const std::string& name) {
    return toupper(name[0]);
}

std::string initializeSoundex(const std::string& name) {
    return std::string(1, getFirstCharacterUppercase(name));
}

char getSoundexCode(char c) {
    static char mapping[256];
    static bool initialized = false;

    if (!initialized) {
        memset(mapping, '0', sizeof(mapping)); // Initialize all to '0'

        mapping['B'] = mapping['F'] = mapping['P'] = mapping['V'] = '1';
        mapping['C'] = mapping['G'] = mapping['J'] = mapping['K'] = mapping['Q'] = mapping['S'] = mapping['X'] = mapping['Z'] = '2';
        mapping['D'] = mapping['T'] = '3';
        mapping['L'] = '4';
        mapping['M'] = mapping['N'] = '5';
        mapping['R'] = '6';

        initialized = true;
    }

    c = toupper(static_cast<unsigned char>(c));
    return mapping[c];
}

std::string appendSoundexCodes(const std::string& soundex, const std::string& name) {
    return soundex + generateSoundexCodes(name);
}

string generateSoundexCodes(const std::string& name) {
    string soundexCodes;
    char prevCode = getSoundexCode(name[1]);

    for (size_t i = 1; i < name.length() && soundexCodes.length() < 3; ++i) {
        char code = getSoundexCode(name[i]);
        if (code != '0' && code != prevCode) {
            soundexCodes += code;
            prevCode = code;
        }
    }
    
    return soundexCodes;
}

std::string padSoundexCode(std::string soundex) {
    while (soundex.length() < 4) {
        soundex += '0';
    }
    return soundex;
}

// main function
std::string generateSoundex(const std::string& name) {
    if (isNameEmpty(name)) return "";
    string soundex = initializeSoundex(name);
    soundex = appendSoundexCodes(soundex, name);
    return padSoundexCode(soundex);
}



































// string generateSoundex(const std::string& name) {
//     if (name.empty()) return "";

//     string soundex(1, toupper(name[0]));
//     char prevCode = getSoundexCode(name[0]);

//     for (size_t i = 1; i < name.length() && soundex.length() < 4; ++i) {
//         char code = getSoundexCode(name[i]);
//         if (code != '0' && code != prevCode) {
//             soundex += code;
//             prevCode = code;
//         }
//     }

//     while (soundex.length() < 4) {
//         soundex += '0';
//     }

//     return soundex;
// }
