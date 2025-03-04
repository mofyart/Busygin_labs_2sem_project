#include "MultipliersApp.hpp"
#include "MyStack/MyStack.hpp"

#include <iostream>
#include <limits>

namespace MultipliersApp {
void OutputMultipliers(MyStack<int> &myStack, int number,
                       int quantityMultipliers) {
  std::cout << std::endl;
  std::cout << number << " = ";
  for (int i = 0; i < quantityMultipliers; ++i) {
    std::cout << myStack.GetInformationNode();

    if (i != quantityMultipliers - 1) {
      std::cout << " * ";
    }
  }
  std::cout << std::endl;
}

bool CheckPrimeNumber(int multiplier) {
  int quantityDivisors{};

  for (int j = 1; j < multiplier / 2 + 1; ++j) {
    if (multiplier % j == 0) {
      ++quantityDivisors;

      if (quantityDivisors > 1) {
        return false;
      }
    }
  }

  return true;
}

void FindMultipliers(int objectNumber, int numberCallFunction) {
  MyStack<int> myStack;
  int quantityMultipliers{};
  int initialNumber = objectNumber;

  switch (static_cast<NumberCallFunction>(numberCallFunction)) {
  case NumberCallFunction::firstCall:
    for (int i = 2; i < objectNumber + 1;) {
      int multiplier = i;

      if (objectNumber % multiplier != 0) {
        ++i;
        continue;
      }

      if (CheckPrimeNumber(multiplier)) {
        ++quantityMultipliers;
        objectNumber /= multiplier;

        myStack.PushObject(multiplier);

        if (objectNumber == 1) {
          break;
        }
      }
    }
    break;
  case NumberCallFunction::secondCall:
    for (int i = objectNumber; i > 1;) {
      int multiplier = i;

      if (objectNumber % multiplier != 0) {
        --i;
        continue;
      }

      if (CheckPrimeNumber(multiplier)) {
        ++quantityMultipliers;
        objectNumber /= multiplier;

        myStack.PushObject(multiplier);

        if (objectNumber == 1) {
          break;
        }
      } else {
        --i;
      }
    }
    break;
  default:
    std::cerr << "Ошибка" << std::endl;
    return;
  }

  OutputMultipliers(myStack, initialNumber, quantityMultipliers);
}

void InputTargetNumber() {
  int objectNumber{};
  std::cout << "Введите число, у котрого хотите найти множители" << std::endl;
  std::cin >> objectNumber;

  if (std::cin.fail()) {
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cout << std::endl;
    std::cout << "Некоректно введены данные" << std::endl;
    return;
  }

  for (int i = 1; i <= 2; ++i) {
    FindMultipliers(objectNumber, i);
  }
}

void StartApp() {
  char decisionContinue = 'y';

  while (decisionContinue == 'y') {
    InputTargetNumber();
    std::cout << std::endl;
    std::cout << "Хотите ли ввести новое число?" << std::endl;
    std::cin >> decisionContinue;
    std::cout << std::endl;
    std::cin.ignore();
  }
}
} // namespace MultipliersApp
