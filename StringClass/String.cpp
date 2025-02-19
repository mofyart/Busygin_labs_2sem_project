#include <cstring>
#include <fstream>
#include <istream>

#pragma once

class String {
 private:
    char* stringBuffer;
    int sizeBuffer;

 public:
    String() {
        stringBuffer = nullptr;
        sizeBuffer = {};
    }

    void setString(const char* stringBufferValue) {
        if (stringBufferValue == nullptr) {
            return;
        }

        sizeBuffer = std::strlen(stringBufferValue);
        stringBuffer = new char[sizeBuffer + 1]{0};
        std::strncpy(stringBuffer, stringBufferValue, sizeBuffer);
    }

    void DeleteString() {
        stringBuffer = nullptr;
        sizeBuffer = {};
    }

    String(const String& other) {
        sizeBuffer = other.sizeBuffer;
        stringBuffer = new char[sizeBuffer + 1]{0};
        std::strncpy(stringBuffer, other.stringBuffer, sizeBuffer);
    }

    char* getString() { return stringBuffer; }

    int getSize() { return sizeBuffer; }

    friend std::ifstream& operator>>(std::ifstream& in, String& string) {
        char* tempBuffer = new char[1024];
        in >> tempBuffer;

        string.setString(tempBuffer);
        return in;
    }

    friend std::ostream& operator<<(std::ostream& out, String& string) {
        out << string.stringBuffer;

        return out;
    }

    ~String() { delete[] stringBuffer; }
};
