#include "CompositePolynomial.hpp"

#include <iostream>
#include <limits>

#include "lib/Polynomial.hpp"

namespace CompositePolynomial {
void AppPolynomial() {
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    Polynomial polynomFirst;
    std::cout << "В каком виде хотите хранить поленом?" << std::endl;
    std::cout << "Вариант №1: по возрастанию степени" << std::endl;
    std::cout << "Вариант №2: по убыванию степени" << std::endl;
    std::cout << std::endl;
    int variantModeStorage = {};
    std::cin >> variantModeStorage;
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    switch (static_cast<ModeStorage>(variantModeStorage)) {
        case ModeStorage::ascending:
            polynomFirst.setModeStorage(ModeStorage::ascending);
            break;
        case ModeStorage::descending:
            polynomFirst.setModeStorage(ModeStorage::descending);
            break;
        default:
            std::cout << "Такогог варианта нет" << std::endl;
            break;
    }

    std::cout << "Введите поленом" << std::endl;
    std::cin >> polynomFirst;

    std::cout << std::endl;
    std::cout << "Обработанный поленом: " << polynomFirst << std::endl;

    Polynomial polynomSecond;
    Polynomial polynomThird;
    std::cout << std::endl;
    std::cout << "Введите ещё один поленом" << std::endl;
    std::cin >> polynomSecond;

    polynomThird = polynomFirst + polynomSecond;

    std::cout << "Обработанный поленом 2:" << polynomSecond << std::endl;
    std::cout << "Обработанный поленом 3:" << polynomThird << std::endl;

    Polynomial polynomFifth;

    polynomFifth = polynomFirst * polynomThird;
    std::cout << std::endl;
    std::cout << "Обработанный поленом 1:" << polynomFirst << std::endl;
    std::cout << "Обработанный поленом 3:" << polynomThird << std::endl;
    std::cout << "Обработанный поленом 5:" << polynomFifth << std::endl;

    Polynomial polynomSixth(polynomFifth);
    std::cout << std::endl;
    std::cout << "Обработанный поленом 6:" << polynomSixth << std::endl;

    polynomSixth += polynomSecond;
    std::cout << std::endl;
    std::cout << "Обработанный поленом 6:" << polynomSixth << std::endl;
    std::cout << "Обработанный поленом 2:" << polynomSecond << std::endl;

    polynomSecond *= polynomFirst;
    std::cout << std::endl;
    std::cout << "Обработанный поленом 2:" << polynomSecond << std::endl;
    std::cout << "Обработанный поленом 1:" << polynomFirst << std::endl;
}

void StartApp() {
    char decisionContinue = 'y';

    while (decisionContinue == 'y') {
        AppPolynomial();

        std::cout << "Хотите продолжить выполнение работы программы (y/n)" << std::endl;
        std::cin >> decisionContinue;
    }
}
}  // namespace CompositePolynomial
