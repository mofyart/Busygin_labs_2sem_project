#include <fstream>
#include <iostream>

#include "String.cpp"

String::String(const String& other);

void String::setString(const char* stringBufferValue);

void String::DeleteString();

char* String::getString();

int String::getSize();

friend std::ifstream& operator>>(std::ifstream& in, String& string);

friend std::ostream& operator<<(std::ostream& out, String& string);
