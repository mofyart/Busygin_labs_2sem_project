#include <algorithm>
#include <cmath>
#include <cstring>
#include <fstream>
#include <iostream>

namespace {
const int maxQuantityNumberIntegerPart = 2;
}

class Fraction {
private:
  int numerator;
  int denominator;

public:
  Fraction();

  Fraction(int numerator, int denominator);

  Fraction(Fraction &other);

  Fraction(double doubleFraction);

  Fraction(const char *fraction);

  void CalculateGCD();

  void MakeIncorrectFraction(int integerPart);

  int getNumerator();

  int getDenominator();

  void setValues(char *fractionValue);

  Fraction operator+(Fraction &other);

  Fraction &operator+=(const Fraction &other);

  Fraction &operator+=(double doubleFraction);

  Fraction operator+(double doubleFraction);

  friend std::istream &operator>>(std::istream &cin, Fraction &other);

  friend std::ostream &operator<<(std::ostream &cout, Fraction &other);

  friend Fraction operator+(double doubleFraction, Fraction &other);
};
