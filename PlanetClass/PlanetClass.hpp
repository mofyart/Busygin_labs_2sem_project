#include "PlanetClass.cpp"
#include "../StringClass/String.cpp"

void Planet::setArguments(Planet planet);

void Planet::setName(String newName);

void Planet::setDiameter(int newDiameter);

void Planet::setHumanLife(bool newHumanLife);

void Planet::setSatelites(int newSatelites);

String Planet::getNamePlanet();

int Planet::getdDiameterPlanet();

int Planet::getHumanLifePlanet();

int Planet::getSatelitesPlanet();

void Planet::setErrorPlanet();

void Planet::DeletePlanet();

friend std::ifstream &operator>>(std::ifstream& in, Planet& planet);

friend std::ofstream &operator<<(std::ofstream& out, Planet& planet);

friend bool operator>(Planet& iPlanet, Planet& jPlanet);
