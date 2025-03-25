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

    virtual ~Institution() = 0;

    virtual void Show() = 0;
};

inline Institution::~Institution() = default;

class InsuranceCompany : public Institution {
 private:
    int quantityInsures = 0;

 public:
    InsuranceCompany() = default;

    ~InsuranceCompany() override;

    void Show() override;

    friend std::istream& operator>>(std::istream& cin, InsuranceCompany& other);
};

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

    ~ShipBuildingCompany() override;

    void Show() override;

    friend std::istream& operator>>(std::istream& cin, ShipBuildingCompany& other);
};

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
    bool successFactory = false;

 public:
    Factory() = default;

    ~Factory() override;

    void Show() override;

    friend std::istream& operator>>(std::istream& cin, Factory& other);
};

inline Factory::~Factory() {
    std::cout << "~Factory" << std::endl;
}

inline void Factory::Show() {
    std::cout << nameInsitution << ' ' << quantityPeople << ' ' << successFactory << std::endl;
}

inline std::istream& operator>>(std::istream& cin, Factory& other) {
    cin >> other.nameInsitution >> other.quantityPeople >> other.successFactory;
    return cin;
}
