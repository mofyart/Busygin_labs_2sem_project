#include <cstring>
#include <iostream>
#include <regex>

class Term {
 private:
    friend class Polynomial;
    int coefficient;
    int power;

 public:
    Term(int coefficentValue = 0, int powerValue = 0) : coefficient(coefficentValue), power(powerValue) {}

    int getCoefficient();

    friend void operator>>(char* term, Term& other);

    friend std::ostream& operator<<(std::ostream& cout, Term& other);

    Term& operator+=(Term& other);

    friend Term operator*(const Term& firstTerm, const Term& secondTerm);
};

inline int Term::getCoefficient() {
    return coefficient;
}

inline void operator>>(char* term, Term& other) {
    size_t sizeTerm = std::strlen(term);
    if (std::strchr(term, 'x') == nullptr) {
        other.coefficient = std::stoi(term);
        return;
    }

    const char* constTerm = term;

    std::match_results<const char*> result;
    std::regex regular(R"(([-+]?\d*)x\^?([-]?\d*)?|([-+])?x\^([-]?\d*))");

    while (std::regex_search(constTerm, constTerm + std::strlen(constTerm), result, regular)) {
        std::sub_match<const char*> matchCoefficient = result[1];
        size_t sizeCoefficient = matchCoefficient.length();

        char* coefficient = new char[sizeCoefficient + 1]{};
        std::memcpy(coefficient, matchCoefficient.first, sizeCoefficient);

        std::sub_match<const char*> matchPower = result[2];
        size_t sizePower = matchPower.length();

        char* power = new char[sizePower + 1]{};
        std::memcpy(power, matchPower.first, sizePower);

        if (power[0] == '\0') {
            if (coefficient[0] == '\0' || coefficient[1] == '\0') {
                if (coefficient[0] == '-') {
                    other.power = 1;
                    other.coefficient = -1;
                    return;
                }

                other.power = 1;
                other.coefficient = 1;
                return;
            }

            other.power = 1;
            other.coefficient = std::stoi(coefficient);
        } else if ((coefficient[0] == '\0') || (coefficient[0] == '+' && !std::isdigit(coefficient[1]))) {
            other.power = std::stoi(power);
            other.coefficient = 1;
        } else if (coefficient[0] == '-' && !std::isdigit(coefficient[1])) {
            other.power = std::stoi(power);
            other.coefficient = -1;
        } else {
            other.power = std::stoi(power);
            other.coefficient = std::stoi(coefficient);
        }

        delete[] coefficient;
        delete[] power;

        constTerm = result.suffix().first;
    }
}

inline std::ostream& operator<<(std::ostream& cout, Term& other) {
    if (other.power == 0) {
        if (other.coefficient > 0) {
            std::cout << '+' << other.coefficient;
            return cout;
        }

        std::cout << other.coefficient;
    } else if (other.coefficient == -1) {
        if (other.power == 1) {
            std::cout << "-x";
            return cout;
        }

        std::cout << "-x^" << other.power;
    } else if (other.coefficient == 1) {
        if (other.power == 1) {
            std::cout << "+x";
            return cout;
        }
        std::cout << "+x^" << other.power;
    } else {
        if (other.coefficient > 0) {
            if (other.power == 1) {
                std::cout << '+' << other.coefficient << "x";
                return cout;
            }
            std::cout << '+' << other.coefficient << "x^" << other.power;
            return cout;
        }

        if (other.power == 1) {
            std::cout << other.coefficient << "x";
            return cout;
        }

        std::cout << other.coefficient << "x^" << other.power;
    }

    return cout;
}

inline Term& Term::operator+=(Term& other) {
    coefficient += other.coefficient;
    return *this;
}

inline Term operator*(const Term& firstTerm, const Term& secondTerm) {
    Term newTerm;

    newTerm.coefficient = firstTerm.coefficient * secondTerm.coefficient;
    newTerm.power = firstTerm.power + secondTerm.power;

    return newTerm;
}
