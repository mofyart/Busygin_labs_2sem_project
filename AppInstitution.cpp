#include "AppInstitution.hpp"

#include <iostream>

namespace {
const int quantityInstitutuions = 4;

void PrintMenu() {
    std::cout << "----------------------------------------------------------------" << std::endl;
    std::cout << "| Перед вами находится меню операций, которые можете выполнить |" << std::endl;
    std::cout << "----------------------------------------------------------------" << std::endl;

    std::cout << "----------------------------------------------------------------" << std::endl;
    std::cout << "|        Опеоация №1: чтение БД из файла                        |" << std::endl;
    std::cout << "|        Операция №2: вывод БД на экран                         |" << std::endl;
    std::cout << "|        Операция №3: удаление объекта из БД                    |" << std::endl;
    std::cout << "|        Операция №4: очистить БД полностью                     |" << std::endl;
    std::cout << "|        Операция №5: выход из программы                        |" << std::endl;
    std::cout << "-----------------------------------------------------------------" << std::endl;
}
}  // namespace

namespace AppInstitution {
void DeleteInstitution(MyVector<Institution*>& dataBase) {
    std::cout << "Введите индекс организации, которой хотите удалить" << std::endl;

    int index = {};
    std::cin >> index;

    dataBase.DeleteElement(index);
}

void ReadFile(MyVector<Institution*>& dataBase) {
    std::cout << "Введите название страховой компании, количество работников и количество страховщиков" << std::endl;
    InsuranceCompany* newInsuranceCompany = new InsuranceCompany();
    std::cin >> *newInsuranceCompany;
    dataBase.AddElement(newInsuranceCompany);
    std::cout << std::endl;

    std::cout << "Введите название судостроительной компании, количество работников и количество сделанных кораблей" << std::endl;
    ShipBuildingCompany* newShipBuildingCompany = new ShipBuildingCompany();
    std::cin >> *newShipBuildingCompany;
    dataBase.AddElement(newShipBuildingCompany);
    std::cout << std::endl;

    std::cout << "Введите название завода, количество работников и успешность завода(0/1)" << std::endl;
    Factory* newFactory = new Factory();
    std::cin >> *newFactory;
    dataBase.AddElement(newFactory);
    std::cout << std::endl;
}

void SelectTask() {
    int numberTask{};
    MyVector<Institution*> institutionDB;

    while (true) {
        PrintMenu();

        std::cout << "Выберите операцию" << std::endl;
        std::cin.clear();
        std::cin >> numberTask;

        switch (static_cast<Tasks>(numberTask)) {
            case Tasks::readFile:
                institutionDB.CleanVector();
                ReadFile(institutionDB);
                break;
            case Tasks::printDB:
                std::cout << institutionDB;
                break;
            case Tasks::deleteObject:
                DeleteInstitution(institutionDB);
                break;
            case Tasks::clenDB:
                institutionDB.CleanVector();
                break;
            case Tasks::exitApp:
                return;
            default:
                std::cout << "Такой операции нет" << std::endl;
        }
    }
}

void StartApp() {
    char decisionContinue = 'y';

    while (decisionContinue == 'y') {
        SelectTask();
        std::cout << std::endl;
        std::cout << "Хотите ли продолжить выполнение программы?" << std::endl;
        std::cin >> decisionContinue;
        std::cout << std::endl;
        std::cin.ignore();
    }
}
}  // namespace AppInstitution
