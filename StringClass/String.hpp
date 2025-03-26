#include <cstring>
#include <istream>

#pragma once

class String {
 private:
    char* stringBuffer;
    int sizeBuffer = 0;

 public:
    String();

    void setString(char* stringBufferValue);

    void setSize(int sizeValue);

    void DeleteString();

    String(const String& other);

    char* getString();

    int getSize();

    ~String();

    friend std::istream& operator>>(std::istream& cin, String& string);

    friend std::ostream& operator<<(std::ostream& out, String& string);
};

inline void String::setSize(int sizeValue = 0) {
    sizeBuffer = 0;
}

inline String::String() {
    stringBuffer = nullptr;
    sizeBuffer = {};
}

inline void String::setString(char* stringBufferValue) {
    if (stringBufferValue == nullptr) {
        return;
    }

    sizeBuffer = std::strlen(stringBufferValue);
    stringBuffer = new char[sizeBuffer + 1]{0};
    std::copy(stringBufferValue, stringBufferValue + sizeBuffer, stringBuffer);
}

inline void String::DeleteString() {
    stringBuffer = nullptr;
    sizeBuffer = {};
}

inline String::String(const String& other) {
    sizeBuffer = other.sizeBuffer;
    stringBuffer = new char[sizeBuffer + 1]{0};
    std::strncpy(stringBuffer, other.stringBuffer, sizeBuffer);
}

inline char* String::getString() {
    return stringBuffer;
}

inline int String::getSize() {
    return sizeBuffer;
}

inline String::~String() {
    delete[] stringBuffer;
}

inline std::istream& operator>>(std::istream& cin, String& string) {
    char* tempBuffer = new char[1024];

    int index = {};
    int quantitySymbols = {};
    char symbol;

    while (symbol != ' ') {
        cin.get(symbol);
        tempBuffer[index++] = symbol;
        ++quantitySymbols;
    }

    char* newTempBuffer = new char[quantitySymbols]{};

    for (int i = 1; i < quantitySymbols - 1; ++i) {
        newTempBuffer[i - 1] = tempBuffer[i];
    }

    string.setString(newTempBuffer);

    delete[] tempBuffer;
    return cin;
}

inline std::ostream& operator<<(std::ostream& out, String& string) {
    out << string.stringBuffer;

    return out;
}
