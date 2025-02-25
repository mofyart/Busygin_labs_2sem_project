#include "fractionClass.hpp"

Fraction::Fraction() {
  this->numerator = {};
  this->denominator = 1;
}

Fraction::Fraction(int numerator, int denominator) {
  this->numerator = numerator;

  if (denominator == 0) {
    std::cout << std::endl;
    std::cout << "Знаменатель не может быть равен 0" << std::endl;
    std::cout << std::endl;
    return;
  }

  this->denominator = denominator;
  CalculateGCD();
}

Fraction::Fraction(Fraction &other) {
  this->numerator = other.numerator;
  this->denominator = other.denominator;
}

Fraction::Fraction(double doubleFraction) {
  int integerPart = static_cast<int>(doubleFraction);
  int quantityNumberAfterPoint{};
  while (integerPart != doubleFraction) {
    doubleFraction *= 10;
    integerPart = static_cast<int>(doubleFraction);
    ++quantityNumberAfterPoint;
  }

  this->numerator = integerPart;
  this->denominator = std::pow(10, quantityNumberAfterPoint);
  CalculateGCD();
}

Fraction::Fraction(const char *fraction) {
  char *newFraction = const_cast<char *>(fraction);
  setValues(newFraction);
}

void Fraction::CalculateGCD() {
  int gcd = std::__gcd(std::abs(this->denominator), std::abs(this->numerator));
  this->numerator /= gcd;
  this->denominator /= gcd;
}

void Fraction::MakeIncorrectFraction(int integerPart) {
  if (integerPart < 0) {
    this->numerator = (integerPart * this->denominator) - this->numerator;
  } else {
    this->numerator += integerPart * this->denominator;
  }
}

int Fraction::getNumerator() { return this->numerator; }

int Fraction::getDenominator() { return this->denominator; }

void Fraction::setValues(char *fractionValue) {
  if (fractionValue == nullptr) {
    return;
  }

  int sizeFraction = std::strlen(fractionValue);
  char *newTempFraction = new char[sizeFraction + 1]{0};
  std::strncpy(newTempFraction, fractionValue, sizeFraction);

  char *point = std::strtok(newTempFraction, " ");
  int integerPart{};

  if (std::strrchr(fractionValue, ' ') ||
      sizeFraction <= maxQuantityNumberIntegerPart) {
    integerPart = std::atoi(point);
    if (sizeFraction <= maxQuantityNumberIntegerPart) {
      this->numerator = {};
      this->denominator = 1;
      MakeIncorrectFraction(integerPart);
      return;
    }
  }

  if (std::strrchr(fractionValue, '/')) {
    if (integerPart != 0) {
      point = std::strtok(NULL, "/");
    } else {
      point = std::strtok(newTempFraction, "/");
    }

    if (point == nullptr) {
      throw "INCORRECT";
    }

    this->numerator = std::atoi(point);
    point = std::strtok(NULL, " ");

    if (point == nullptr) {
      throw "INCORRECT";
    }

    this->denominator = std::atoi(point);

    if (this->denominator == 0) {
      throw "INCORRECT";
    }
  } else {
    throw "INCORRECT";
  }

  CalculateGCD();
  MakeIncorrectFraction(integerPart);

  delete[] newTempFraction;
}

Fraction Fraction::operator+(Fraction &other) {
  Fraction newFraction;
  newFraction.denominator = this->denominator * other.denominator;
  newFraction.numerator =
      this->numerator * other.denominator + other.numerator * this->denominator;

  newFraction.CalculateGCD();

  return newFraction;
}

Fraction &Fraction::operator+=(const Fraction &other) {
  Fraction newFraction;
  newFraction.denominator = this->denominator * other.denominator;
  newFraction.numerator =
      this->numerator * other.denominator + other.numerator * this->denominator;

  this->denominator = newFraction.denominator;

  this->numerator = newFraction.numerator;
  CalculateGCD();

  return *this;
}

Fraction &Fraction::operator+=(double doubleFraction) {
  Fraction newFraction(doubleFraction);
  *this += newFraction;
  return *this;
}

Fraction Fraction::operator+(double doubleFraction) {
  Fraction fromDoubleFraction(doubleFraction);
  Fraction newFraction = fromDoubleFraction + *this;

  return newFraction;
}

Fraction operator+(double doubleFraction, Fraction &other) {
  Fraction fromDoubleFraction(doubleFraction);
  Fraction newFraction = fromDoubleFraction + other;

  return newFraction;
}

std::istream &operator>>(std::istream &cin, Fraction &other) {
  char *fractionTemp = new char[128];
  cin.getline(fractionTemp, 128);
  other.setValues(fractionTemp);

  delete[] fractionTemp;
  return cin;
}

std::ostream &operator<<(std::ostream &cout, Fraction &other) {
  std::cout << other.numerator << "/" << other.denominator;
  return cout;
}
