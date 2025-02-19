#pragma once

#include <fstream>
#include <iostream>
#include <istream>
#include <string>

#include "../StringClass/String.cpp"

class Planet {
 private:
    String name;
    int diameter{};
    bool humanLife{};
    int satelites{};

 public:
    Planet() = default;

    void setArguments(Planet planet) {
        name.setString(planet.getNamePlanet().getString());
        diameter = planet.getdDiameterPlanet();
        humanLife = planet.getHumanLifePlanet();
        satelites = planet.getSatelitesPlanet();
    }

    void setName(String newName) { name.setString(newName.getString()); }

    void setDiameter(int newDiameter) { diameter = newDiameter; }

    void setHumanLife(bool newHumanLife) { humanLife = newHumanLife; }

    void setSatelites(int newSatelites) { satelites = newSatelites; }

    String getNamePlanet() { return name; }

    int getdDiameterPlanet() { return diameter; }

    int getHumanLifePlanet() { return humanLife; }

    int getSatelitesPlanet() { return satelites; }

    void setErrorPlanet() {
        name.setString("ERROR");
        diameter = {};
        humanLife = {};
        satelites = {};
    }

    void DeletePlanet() {
        name.DeleteString();
        diameter = {};
        humanLife = {};
        satelites = {};
    }

    friend std::ifstream& operator>>(std::ifstream& in, Planet& planet) {
        in >> planet.name >> planet.diameter >> planet.humanLife >> planet.satelites;
        return in;
    }

    friend std::ofstream& operator<<(std::ofstream& out, Planet& planet) {
        out << ' ' << planet.name << ' ' << planet.diameter << ' ' << planet.humanLife << ' ' << planet.satelites << '\n';
        return out;
    }

    friend bool operator>(Planet& iPlanet, Planet& jPlanet) { return iPlanet.diameter > jPlanet.diameter; }

    ~Planet() {
        name.DeleteString();
        diameter = {};
        humanLife = {};
        satelites = {};
    }
};
