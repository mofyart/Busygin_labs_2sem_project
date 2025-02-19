#pragma once

#include <fstream>
#include <iostream>
#include <istream>
#include <string>

#include "../StringClass/String.cpp"

class Candidate {
 private:
    String name;
    int age{};
    bool existingFamily{};
    int quantityVoters{};

 public:
    Candidate() = default;

    void setArguments(Candidate candidate) {
        name.setString(candidate.getNamePlanet().getString());
        age = candidate.getdDiameterPlanet();
        existingFamily = candidate.getHumanLifePlanet();
        quantityVoters = candidate.getSatelitesPlanet();
    }

    void setName(String newName) { name.setString(newName.getString()); }

    void setDiameter(int newDiameter) { age = newDiameter; }

    void setHumanLife(bool newHumanLife) { existingFamily = newHumanLife; }

    void setSatelites(int newSatelites) { quantityVoters = newSatelites; }

    String getNamePlanet() { return name; }

    int getdDiameterPlanet() { return age; }

    int getHumanLifePlanet() { return existingFamily; }

    int getSatelitesPlanet() { return quantityVoters; }

    void setErrorPlanet() {
        name.setString("ERROR");
        age = {};
        existingFamily = {};
        quantityVoters = {};
    }

    void DeletePlanet() {
        name.DeleteString();
        age = {};
        existingFamily = {};
        quantityVoters = {};
    }

    friend std::ifstream& operator>>(std::ifstream& in, Candidate& cnadidate) {
        in >> cnadidate.name >> cnadidate.age >> cnadidate.existingFamily >> cnadidate.quantityVoters;
        return in;
    }

    friend std::ofstream& operator<<(std::ofstream& out, Candidate& cnadidate) {
        out << ' ' << cnadidate.name << ' ' << cnadidate.age << ' ' << cnadidate.existingFamily << ' ' << cnadidate.quantityVoters << '\n';
        return out;
    }

    friend bool operator>(Candidate& iCandidate, Candidate& jCandidate) { return iCandidate.age > jCandidate.age; }

    ~Candidate() {
        name.DeleteString();
        age = {};
        existingFamily = {};
        quantityVoters = {};
    }
};
