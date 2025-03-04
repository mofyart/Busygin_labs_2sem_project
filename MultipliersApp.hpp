#include "MyStack/MyStack.hpp"

namespace MultipliersApp {
enum class NumberCallFunction {
  firstCall = 1,
  secondCall = 2,
};

void OutputMultipliers(MyStack<int> &myStack, int number,
                       int quantityMultipliers);

bool CheckPrimeNumber(int multiplier);

void FindMultipliers(int objectNumber);

void InputTargetNumber();

void StartApp();
} // namespace MultipliersApp
