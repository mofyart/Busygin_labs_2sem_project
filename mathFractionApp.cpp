#include "mathFractionApp.hpp"
#include "FractionClass/fractionClass.hpp"

#include <iostream>

namespace MathFraction {
void ProcessFraction() {
  std::cout << "Введите дробь" << std::endl;
  Fraction fractionFirst;
  Fraction fractionSecond(10, 14);

  try {
    std::cin >> fractionFirst;
  } catch (...) {
    std::cout << std::endl;
    std::cout << "Дробь введена некорректно" << std::endl;
    return;
  }

  std::cout << std::endl;
  std::cout << "fr1= " << fractionFirst << std::endl;
  std::cout << "fr2= " << fractionSecond << std::endl;

  Fraction fractionThird = "-1 4/8";
  std::cout << "fr3= " << fractionThird << std::endl;

  Fraction fractionFourth(fractionFirst);
  std::cout << "fr4= " << fractionFourth << std::endl;

  double doubleFraction = -1.25;
  Fraction fractionFifth = doubleFraction;
  std::cout << "fr5= " << fractionFifth << std::endl;

  Fraction fractionSixth;
  fractionSixth = fractionFourth + fractionFirst;
  std::cout << "fr6= " << fractionSixth << std::endl;

  fractionSixth += fractionFourth;
  std::cout << "fr6= " << fractionSixth << std::endl;

  fractionFifth += (doubleFraction / 2);
  std::cout << "fr5= " << fractionFifth << std::endl;

  fractionSixth = fractionFourth + doubleFraction;
  std::cout << "fr6= " << fractionSixth << std::endl;

  fractionSixth = doubleFraction + fractionSixth;
  std::cout << "fr6= " << fractionSixth << std::endl;

  fractionSixth += doubleFraction;
  std::cout << "fr6= " << fractionSixth << std::endl;

  int integerFraction = 5;

  fractionSixth += integerFraction;
  std::cout << "fr6= " << fractionSixth << std::endl;

  fractionSixth = integerFraction + fractionFourth;
  std::cout << "fr6= " << fractionSixth << std::endl;

  fractionSixth = fractionFourth + integerFraction;
  std::cout << "fr6= " << fractionSixth << std::endl;

  fractionSixth += doubleFraction + integerFraction + fractionFourth;
  std::cout << "fr6= " << fractionSixth << std::endl;
}

void StartApp() {
  char decisionContinue = 'y';

  while (decisionContinue == 'y') {
    ProcessFraction();
    std::cout << std::endl;
    std::cout << "Хотите ли ввести новую дробь?" << std::endl;
    std::cin >> decisionContinue;
    std::cout << std::endl;
    std::cin.ignore();
  }
}
} // namespace MathFraction
