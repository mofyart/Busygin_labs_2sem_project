#include "AppInstitution.hpp"

#include <iostream>
#include "InsitutionClass/Institution.hpp"

namespace {

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
void DeleteInstitution(MyHashTable<Institution*>& dataBase) {
    std::cout << "Введите индекс организации, которой хотите удалить" << std::endl;

    int index = {};
    std::cin >> index;

    dataBase.DeleteElement(index);
}

void ReadFile(MyHashTable<Institution*>& dataBase) {
    std::cout << "Введите название страховой компании, количество работников и количество страховщиков" << std::endl;
    InsuranceCompany* newInsuranceCompany = new InsuranceCompany();
    std::cin >> *newInsuranceCompany;
    dataBase.AddElement(newInsuranceCompany);
    std::cout << std::endl;

    InsuranceCompany* newInsuranceCompanyDemo = new InsuranceCompany("Nokia", 12, 343);
    dataBase.AddElement(newInsuranceCompanyDemo);

    std::cout << "Введите название судостроительной компании, количество работников и количество сделанных кораблей" << std::endl;
    ShipBuildingCompany* newShipBuildingCompany = new ShipBuildingCompany();
    std::cin >> *newShipBuildingCompany;
    std::cin.clear();
    dataBase.AddElement(newShipBuildingCompany);
    std::cout << std::endl;

    ShipBuildingCompany* newShipBuildingCompanyDemo = new ShipBuildingCompany("Apple", 3445, 23);
    dataBase.AddElement(newShipBuildingCompanyDemo);

    std::cout << "Введите название завода, количество работников и успешность завода(0/1)" << std::endl;
    Factory* newFactory = new Factory();
    std::cin >> *newFactory;
    dataBase.AddElement(newFactory);
    std::cout << std::endl;

    Factory* newFactoryDemo = new Factory("Tinkoff", 2213, 0);
    dataBase.AddElement(newFactoryDemo);
}

void SelectTask() {
    int numberTask{};
    MyHashTable<Institution*> institutionDB;

    while (true) {
        PrintMenu();

        std::cout << "Выберите операцию" << std::endl;
        std::cin.clear();
        std::cin >> numberTask;
        std::cin.clear();

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
