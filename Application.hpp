#include <cstddef>
#include <cstring>
#include <fstream>
#include <iostream>

#include "CandidateClass/CandidateClass.cpp"
#include "DataBase/DataBase.cpp"
#include "PlanetClass/PlanetClass.cpp"
#include "StringClass/String.cpp"

namespace AppObject {
enum class TypeMode {
    classPlanet = 1,
    classCandidate = 2,
    exitApp = 3,
};
enum class NumberTask {
    readDBFile = 1,
    outputDBFile = 2,
    sortDB = 3,
    addNewObject = 4,
    deleteObject = 5,
    editBD = 6,
    inputDBScreen = 7,
    exitMode = 8,
};

void ReadFile(DataBase<Planet>& dataBase);
void ReadFile(DataBase<Candidate>& dataBase);

void FillFile(DataBase<Planet>& dataBase);
void FillFile(DataBase<Candidate>& dataBase);

void AddNewObject(DataBase<Planet>& dataBase);
void AddNewObject(DataBase<Candidate>& dataBase);

void DeleteObject(DataBase<Planet>& dataBase);
void DeleteObject(DataBase<Candidate>& dataBase);

void InputDBScreen(DataBase<Planet>& dataBase);
void InputDBScreen(DataBase<Candidate>& dataBase);

void EditDB(DataBase<Planet>& dataBase);
void EditDB(DataBase<Candidate>& dataBase);

void ReadFile(DataBase<Planet>& dataBase);
void ReadFile(DataBase<Candidate>& dataBase);

void RunApp();

void SelectTask();
}  // namespace AppObject
