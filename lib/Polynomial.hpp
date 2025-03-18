#include <algorithm>
#include <cstring>
#include <iostream>
#include <regex>

#include "../CompositePolynomial.hpp"
#include "Term.hpp"

class Polynomial {
 private:
    Term* dataBaseTerms;
    int capacity;
    int count;
    CompositePolynomial::ModeStorage modeStorage = CompositePolynomial::ModeStorage::ascending;

 public:
    Polynomial();

    Polynomial(Term object);

    Polynomial(Polynomial& other);

    ~Polynomial();

    void AddElement(Term object);

    void setModeStorage(CompositePolynomial::ModeStorage variantModeStorage);

    void ReSize();

    void SortDataBase();

    void SimplificationPolynomial();

    void DeleteZeroTerm();

    Polynomial& operator=(const Polynomial& other);

    Polynomial& operator+=(const Polynomial& other);

    Polynomial& operator*=(const Polynomial& other);

    friend Polynomial operator+(const Polynomial& firstpoly, const Polynomial& secondPoly);

    friend Polynomial operator*(const Polynomial& firstpoly, const Polynomial& secondPoly);

    friend std::istream& operator>>(std::istream& cin, Polynomial& other);

    friend std::ostream& operator<<(std::ostream& cout, Polynomial& other);
};

inline Polynomial::Polynomial(Polynomial& other) {
    Term* oldDataBase = dataBaseTerms;

    Term* newDataBase = new Term[other.capacity];
    std::copy(other.dataBaseTerms, other.dataBaseTerms + other.capacity, newDataBase);

    count = other.count;
    capacity = other.capacity;
    dataBaseTerms = newDataBase;
}

inline Polynomial::Polynomial(Term object) {
    AddElement(object);
}

inline Polynomial::~Polynomial() {
    delete[] dataBaseTerms;
}

inline Polynomial::Polynomial() {
    capacity = 1;
    count = {};
    dataBaseTerms = new Term[capacity];
}

inline void Polynomial::DeleteZeroTerm() {
    Term* newDataBase = new Term[count + 1];

    int countNewDataBase = {};
    for (int i = 0; i < count; ++i) {
        if (dataBaseTerms[i].coefficient != 0) {
            newDataBase[countNewDataBase] = dataBaseTerms[i];
            ++countNewDataBase;
        }
    }

    Term* oldDataBase = dataBaseTerms;

    dataBaseTerms = newDataBase;

    capacity = count + 1;
    count = countNewDataBase;
    delete[] oldDataBase;
}

inline void Polynomial::SimplificationPolynomial() {
    int quantityDegreesPolynomial = 1;

    for (int i = 0; i < count - 1; ++i) {
        if (dataBaseTerms[i].power != dataBaseTerms[i + 1].power) {
            ++quantityDegreesPolynomial;
        }
    }

    Term* newPolynomial = new Term[quantityDegreesPolynomial];

    int countNewPolynomial = 0;
    newPolynomial[0].power = dataBaseTerms[0].power;

    for (int i = 0; i < count; ++i) {
        if (newPolynomial[countNewPolynomial].power != dataBaseTerms[i].power) {
            ++countNewPolynomial;
            newPolynomial[countNewPolynomial].power = dataBaseTerms[i].power;
            newPolynomial[countNewPolynomial] += dataBaseTerms[i];
        } else {
            newPolynomial[countNewPolynomial] += dataBaseTerms[i];
        }
    }

    Term* oldPolynomial = dataBaseTerms;

    dataBaseTerms = newPolynomial;

    count = quantityDegreesPolynomial;
    capacity = quantityDegreesPolynomial + 1;

    delete[] oldPolynomial;
}

inline void Polynomial::SortDataBase() {
    for (int i = 0; i < count; ++i) {
        for (int j = 0; j < count - i - 1; ++j) {
            if (modeStorage == static_cast<CompositePolynomial::ModeStorage>(1)) {
                if (dataBaseTerms[j].power > dataBaseTerms[j + 1].power) {
                    std::swap(dataBaseTerms[j], dataBaseTerms[j + 1]);
                }
            } else {
                if (dataBaseTerms[j].power < dataBaseTerms[j + 1].power) {
                    std::swap(dataBaseTerms[j], dataBaseTerms[j + 1]);
                }
            }
        }
    }
}

inline void Polynomial::ReSize() {
    if (count >= capacity) {
        Term* newDataBase = new Term[this->capacity * 2];
        std::copy(dataBaseTerms, dataBaseTerms + count, newDataBase);

        Term* oldDataBase = dataBaseTerms;

        dataBaseTerms = newDataBase;
        capacity *= 2;

        delete[] oldDataBase;
    }
}

inline void Polynomial::AddElement(Term object) {
    ReSize();

    dataBaseTerms[count] = object;
    ++count;
}

inline void Polynomial::setModeStorage(CompositePolynomial::ModeStorage variantModeStorage) {
    modeStorage = variantModeStorage;
}

inline Polynomial& Polynomial::operator*=(const Polynomial& other) {
    Polynomial newPoly;

    for (int i = 0; i < count; ++i) {
        for (int j = 0; j < other.count; ++j) {
            newPoly.AddElement(dataBaseTerms[i] * other.dataBaseTerms[j]);
        }
    }

    delete[] dataBaseTerms;

    dataBaseTerms = new Term[newPoly.capacity];
    std::copy(newPoly.dataBaseTerms, newPoly.dataBaseTerms + newPoly.capacity, dataBaseTerms);

    capacity = newPoly.capacity;
    count = newPoly.count;

    SortDataBase();
    SimplificationPolynomial();

    return *this;
}

inline Polynomial& Polynomial::operator+=(const Polynomial& other) {
    for (int i = 0; i < other.count; ++i) {
        AddElement(other.dataBaseTerms[i]);
    }

    SortDataBase();
    SimplificationPolynomial();
    DeleteZeroTerm();

    return *this;
}

inline Polynomial& Polynomial::operator=(const Polynomial& other) {
    for (int i = 0; i < other.count; ++i) {
        AddElement(other.dataBaseTerms[i]);
    }

    return *this;
}

inline Polynomial operator+(const Polynomial& firstPoly, const Polynomial& secondPoly) {
    Polynomial newPoly;

    for (int i = 0; i < firstPoly.count; ++i) {
        newPoly.AddElement(firstPoly.dataBaseTerms[i]);
    }
    for (int i = 0; i < secondPoly.count; ++i) {
        newPoly.AddElement(secondPoly.dataBaseTerms[i]);
    }

    newPoly.SortDataBase();
    newPoly.SimplificationPolynomial();
    newPoly.DeleteZeroTerm();

    return newPoly;
}

inline Polynomial operator*(const Polynomial& firstPoly, const Polynomial& secondPoly) {
    Polynomial newPoly;

    for (int i = 0; i < firstPoly.count; ++i) {
        for (int j = 0; j < secondPoly.count; ++j) {
            newPoly.AddElement(firstPoly.dataBaseTerms[i] * secondPoly.dataBaseTerms[j]);
        }
    }

    newPoly.SortDataBase();
    newPoly.SimplificationPolynomial();

    return newPoly;
}

inline std::istream& operator>>(std::istream& cin, Polynomial& other) {
    char* bufferPolynomial = new char[128]{};

    cin.getline(bufferPolynomial, 128);

    int quantitySignificantsymbols = {};
    int quantitySpaces = {};

    for (int i = 0; i < 128; ++i) {
        if (bufferPolynomial[i] != '\0') {
            ++quantitySignificantsymbols;
        }

        if (bufferPolynomial[i] == ' ') {
            ++quantitySpaces;
        }
    }

    char* clinedBufferPolynomial = new char[quantitySignificantsymbols + 1 - quantitySpaces]{};
    int countNewBuffer = {};

    for (int i = 0; i < std::strlen(bufferPolynomial); ++i) {
        if (bufferPolynomial[i] != ' ') {
            clinedBufferPolynomial[countNewBuffer] = bufferPolynomial[i];
            ++countNewBuffer;
        }
    }

    std::match_results<const char*> result;
    std::regex regular(R"(([-+]?\d*)x\^?([-]?\d+)?|([-+]?\d+))");

    const char* constBufferPolunomial = clinedBufferPolynomial;
    const char* searchStart = constBufferPolunomial;

    while (std::regex_search(searchStart, constBufferPolunomial + std::strlen(constBufferPolunomial), result, regular)) {
        std::sub_match<const char*> match = result[0];
        std::size_t sizeMatch = match.length();

        char* memberPoly = new char[sizeMatch + 1]{};
        std::memcpy(memberPoly, match.first, sizeMatch);

        Term term;

        memberPoly >> term;

        if (term.getCoefficient() == 0) {
            delete[] memberPoly;

            searchStart = result.suffix().first;
            continue;
        }

        other.AddElement(term);

        delete[] memberPoly;

        searchStart = result.suffix().first;
    }

    other.SortDataBase();

    other.SimplificationPolynomial();

    other.DeleteZeroTerm();

    delete[] clinedBufferPolynomial;
    delete[] bufferPolynomial;
    return cin;
}

inline std::ostream& operator<<(std::ostream& cout, Polynomial& other) {
    for (int i = 0; i < other.count; ++i) {
        std::cout << other.dataBaseTerms[i] << ' ';
    }

    return cout;
}
