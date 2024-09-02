#include "Soundex.h"
#include <cctype>
#include <cstring>

using namespace std;

// pure function to check if the input 'name' is empy
bool isNameEmpty(const string& name) {
    return name.empty();
}

// pure function to convert the first character of input 'name' to uppercase
char getFirstCharacterUppercase(const string& name) {
    return toupper(name[0]);
}

string initializeSoundex(const string& name) {
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

string generateSoundexCodes(const std::string& name) {
    string soundexCodes;
    char prevCode = getSoundexCode(name[0]);

    for (size_t i = 1; i < name.length() && soundexCodes.length() < 3; ++i) {
        char code = getSoundexCode(name[i]);
        if (code != '0' && code != prevCode) {
            soundexCodes += code;
            prevCode = code;
        }
    }
    
    return soundexCodes;
}

string appendSoundexCodes(const string& soundex, const string& name) {
    return soundex + generateSoundexCodes(name);
}

std::string padSoundexCode(string soundex) {
    while (soundex.length() < 4) {
        soundex += '0';
    }
    return soundex;
}

// main function
string generateSoundex(const string& name) {
    if (isNameEmpty(name)) return "";
    string soundex = initializeSoundex(name);
    soundex = appendSoundexCodes(soundex, name);
    return padSoundexCode(soundex);
}
