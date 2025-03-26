#pragma once

#include <cstring>
#include <iostream>

#include "../StringClass/String.hpp"

class Institution {
 protected:
    String nameInsitution;
    int quantityPeople = 0;

 public:
    Institution() = default;

    virtual ~Institution();

    virtual void Show() = 0;

    String getName();

    void setNameDefaultSize();
};

inline Institution::~Institution() = default;

inline String Institution::getName() {
    return nameInsitution;
}

inline void Institution::setNameDefaultSize() {
    nameInsitution.setString(nullptr);
}

class InsuranceCompany : public Institution {
 private:
    int quantityInsures = 0;
 public:
    InsuranceCompany() = default;

    InsuranceCompany(char* nameValue, int valueQuantityPeople, int valueQuantityInsures);

    ~InsuranceCompany() override;

    void Show() override;

    friend std::istream& operator>>(std::istream& cin, InsuranceCompany& other);
};

inline InsuranceCompany::InsuranceCompany(char* nameValue, int valueQuantityPeople, int valueQuantityInsures) {
    nameInsitution.setString(nameValue);
    quantityPeople = valueQuantityPeople;
    quantityInsures = valueQuantityInsures;
}

inline InsuranceCompany::~InsuranceCompany() {
    std::cout << "~InsuranceCompany" << std::endl;
}

inline void InsuranceCompany::Show() {
    std::cout << nameInsitution << ' ' << quantityPeople << ' ' << quantityInsures << std::endl;
}

inline std::istream& operator>>(std::istream& cin, InsuranceCompany& other) {
    cin >> other.nameInsitution >> other.quantityPeople >> other.quantityInsures;
    return cin;
}
class ShipBuildingCompany : public Institution {
 private:
    int quantityCreatedShip;

 public:
    ShipBuildingCompany() = default;

    ShipBuildingCompany(char* nameValue, int valueQuantityPeople, int valueQuantityCreatedShip);

    ~ShipBuildingCompany() override;

    void Show() override;

    friend std::istream& operator>>(std::istream& cin, ShipBuildingCompany& other);
};

inline ShipBuildingCompany::ShipBuildingCompany(char* nameValue, int valueQuantityPeople, int valueQuantityCreatedShip) {
    nameInsitution.setString(nameValue);
    quantityPeople = valueQuantityPeople;
    quantityCreatedShip = valueQuantityCreatedShip;
}

inline ShipBuildingCompany::~ShipBuildingCompany() {
    std::cout << "~ShipBuildingCompany" << std::endl;
}

inline void ShipBuildingCompany::Show() {
    std::cout << nameInsitution << ' ' << quantityPeople << ' ' << quantityCreatedShip << std::endl;
}

inline std::istream& operator>>(std::istream& cin, ShipBuildingCompany& other) {
    cin >> other.nameInsitution >> other.quantityPeople >> other.quantityCreatedShip;
    return cin;
}

class Factory : public Institution {
 private:
    bool succesFactory = false;

 public:
    Factory() = default;

    Factory(char* nameValue, int valueQuantityPeople, bool valueSuccesFactory);

    ~Factory() override;

    void Show() override;

    friend std::istream& operator>>(std::istream& cin, Factory& other);
};

inline Factory::Factory(char* nameValue, int valueQuantityPeople, bool valueSuccesFactory) {
    nameInsitution.setString(nameValue);
    quantityPeople = valueQuantityPeople;
    succesFactory= valueSuccesFactory;
}

inline Factory::~Factory() {
    std::cout << "~Factory" << std::endl;
}

inline void Factory::Show() {
    std::cout << nameInsitution << ' ' << quantityPeople << ' ' << succesFactory << std::endl;
}

inline std::istream& operator>>(std::istream& cin, Factory& other) {
    cin >> other.nameInsitution >> other.quantityPeople >> other.succesFactory;
    return cin;
}
