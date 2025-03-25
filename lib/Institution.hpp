#include"../StringClass/String.hpp"

#include <iostream>
#include <cstring>

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

    ~InsuranceCompany()  override {
        std::cout << "~InsuranceCompany" << std::endl;
    }

    void Show() override {
        std::cout << nameInsitution << ' ' << quantityPeople << ' ' << quantityInsures << std::endl;
    }

    friend std::istream& operator>>(std::istream& cin, InsuranceCompany& other);
};

inline std::istream& operator>>(std::istream& cin, InsuranceCompany& other) {
    cin >> other.nameInsitution >> other.quantityPeople >> other.quantityInsures;
    return cin;
}


class ShipBuildingCompany : public Institution {
    private:
        int quantityCreatedShip;
    public:

    ShipBuildingCompany() = default;

    ~ShipBuildingCompany()  override {
        std::cout << "~ShipBuildingCompany" << std::endl;
    }

    void Show() override {
        std::cout << nameInsitution << ' ' << quantityPeople << ' ' << quantityCreatedShip << std::endl;
    }

    friend std::istream& operator>>(std::istream& cin, ShipBuildingCompany& other);
};

inline std::istream& operator>>(std::istream& cin, ShipBuildingCompany& other) {
    cin >> other.nameInsitution >> other.quantityPeople >> other.quantityCreatedShip;
    return cin;
}

class Factory : public Institution {
    private:
        bool successFactory = false;
    public:
        Factory() = default;

        ~Factory()  override {
            std::cout << "~Factory" << std::endl;
        }

        void Show() override {
            std::cout << nameInsitution << ' ' << quantityPeople << ' ' << successFactory << std::endl;
        }

        friend std::istream& operator>>(std::istream& cin, Factory& other);
};

inline std::istream& operator>>(std::istream& cin, Factory& other) {
    cin >> other.nameInsitution >> other.quantityPeople >> other.successFactory;
    return cin;
}
