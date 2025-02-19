#pragma once

#include "../StringClass/String.cpp"
#include "CandidateClass.cpp"

void Candidate::CansetArguments(Candidate candidate);

void Candidate::setName(String newName);

void Candidate::setDiameter(int newDiameter);

void Candidate::setHumanLife(bool newHumanLife);

void Candidate::setSatelites(int newSatelites);

String Candidate::getNamePlanet();

int Candidate::getdDiameterPlanet();

int Candidate::getHumanLifePlanet();

int Candidate::getSatelitesPlanet();

void Candidate::setErrorPlanet();

void Candidate::DeletePlanet();

friend std::ifstream& operator>>(std::ifstream& in, Candidate& cnadidate) {
    in >> cnadidate.name >> cnadidate.age >> cnadidate.existingFamily >> cnadidate.quantityVoters;
    return in;
}

friend std::ofstream& operator<<(std::ofstream& out, Candidate& cnadidate) {
    out << ' ' << cnadidate.name << ' ' << cnadidate.age << ' ' << cnadidate.existingFamily << ' ' << cnadidate.quantityVoters << '\n';
    return out;
}

friend bool operator>(Candidate& iCandidate, Candidate& jCandidate) {
    return iCandidate.age > jCandidate.age;
}
