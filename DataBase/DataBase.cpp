#include <cerrno>
#include <cstdlib>
#include <cstring>
#include <iostream>

#include "../StringClass/String.cpp"

namespace {
const int kGrouthFactor = 2;

const int kMaxProcent = 100;
const int kMaxProcentFullnessTable = 70;
}  // namespace

template<typename ClassMode>

class DataBase {
 private:
    ClassMode* database;
    int capacity = 2;
    int count = 0;

 public:
    DataBase() { database = new ClassMode[capacity]; }

    int HashKey(String key) {
        int sumASCIISymbols = 0;
        const char* bufferString = key.getString();

        for (int i = 0; i < std::strlen(bufferString); ++i) {
            sumASCIISymbols += bufferString[i] * (i + 1);
        }

        return sumASCIISymbols % capacity;
    }

    int HashKey(char* key) {
        int sumASCIISymbols = 0;

        char* bufferString = key;

        for (int i = 0; i < std::strlen(key); ++i) {
            sumASCIISymbols += bufferString[i] * (i + 1);
        }

        return sumASCIISymbols % capacity;
    }

    void ReinitializeDataBase() {
        if (count / capacity * kMaxProcent >= kMaxProcentFullnessTable) {
            ClassMode* newDataBase = new ClassMode[capacity * kGrouthFactor];
            std::copy(database, database + count, newDataBase);

            ClassMode* oldWordsDictionary = database;
            database = newDataBase;
            capacity *= kGrouthFactor;

            delete[] oldWordsDictionary;
        }
    }

    void AddNewObject(ClassMode values) {
        ReinitializeDataBase();

        for (int i = 0; i < capacity; ++i) {
            if (std::strncmp(values.getNamePlanet().getString(), database[i].getNamePlanet().getString(),
                             database[i].getNamePlanet().getSize() + 1) == 0) {
                std::cout << std::endl;
                std::cout << "Объект с таким именем уже есть" << std::endl;
                std::cout << std::endl;
                return;
            }
        }

        int hashedIndex = HashKey(values.getNamePlanet());

        if (database[hashedIndex].getNamePlanet().getSize() > 0) {
            int newCount = (hashedIndex == (capacity - 1)) ? 0 : hashedIndex + 1;
            while (database[newCount].getNamePlanet().getSize() > 0) {
                if (newCount == (capacity - 1)) {
                    newCount = -1;
                }
                ++newCount;
            }

            database[newCount].setArguments(values);
        } else {
            database[hashedIndex].setArguments(values);
        }
        ++count;
    }

    ClassMode getObject(char* nameObject) {
        int hashedIndex = HashKey(nameObject);

        if (std::strncmp(nameObject, database[hashedIndex].getNamePlanet().getString(), database[hashedIndex].getNamePlanet().getSize() + 1) == 0) {
            return database[hashedIndex];
        } else {
            for (int i = hashedIndex + 1; i < hashedIndex + capacity; ++i) {
                if (std::strncmp(nameObject, database[i % capacity].getNamePlanet().getString(),
                                 database[i % capacity].getNamePlanet().getSize() + 1) == 0) {
                    return database[i % capacity];
                }
            }
        }

        ClassMode errorObject;
        errorObject.setErrorPlanet();

        return errorObject;
    }

    void DeleteObject(char* nameObject) {
        bool existingPlanet = false;

        for (int i = 0; i < capacity; ++i) {
            if (std::strncmp(nameObject, database[i].getNamePlanet().getString(), database[i].getNamePlanet().getSize() + 1) == 0) {
                existingPlanet = true;
            }
        }

        if (!existingPlanet) {
            std::cout << std::endl;
            std::cout << "Такого объекта не существует" << std::endl;
            return;
        }

        int hashedIndex = HashKey(nameObject);

        if (std::strncmp(nameObject, database[hashedIndex].getNamePlanet().getString(), database[hashedIndex].getNamePlanet().getSize() + 1) == 0) {
            database[hashedIndex].DeletePlanet();
        } else {
            for (int i = hashedIndex + 1; i < hashedIndex + capacity - 1; ++i) {
                if (std::strncmp(nameObject, database[i % capacity].getNamePlanet().getString(),
                                 database[i % capacity].getNamePlanet().getSize() + 1) == 0) {
                    database[i % capacity].DeletePlanet();
                }
            }
        }
        --count;
    }

    void SortDataBase() {
        for (int i = 0; i < capacity; ++i) {
            for (int j = i + 1; j < capacity; ++j) {
                if (database[i] > database[j]) {
                    std::swap(database[i], database[j]);
                }
            }
        }
    }

    void EditDataBase(ClassMode values) {
        bool existingPlanet = false;

        for (int i = 0; i < capacity; ++i) {
            if (std::strncmp(values.getNamePlanet().getString(), database[i].getNamePlanet().getString(),
                             database[i].getNamePlanet().getSize() + 1) == 0) {
                existingPlanet = true;
            }
        }

        if (!existingPlanet) {
            std::cout << std::endl;
            std::cout << "Такого объекта не существует" << std::endl;
            return;
        }

        int hashedIndex = HashKey(values.getNamePlanet());

        if ((database[hashedIndex].getNamePlanet().getSize() == 0) ||
            ((std::strncmp(values.getNamePlanet().getString(), database[hashedIndex].getNamePlanet().getString(),
                           database[hashedIndex].getNamePlanet().getSize() + 1) != 0))) {
            int newCount = (hashedIndex == (capacity - 1)) ? 0 : hashedIndex + 1;

            while ((database[newCount].getNamePlanet().getSize() == 0) ||
                   ((std::strncmp(values.getNamePlanet().getString(), database[newCount].getNamePlanet().getString(),
                                  database[newCount].getNamePlanet().getSize() + 1) != 0))) {
                if (newCount == (capacity - 1)) {
                    newCount = -1;
                }
                ++newCount;
            }

            database[newCount].setArguments(values);
        } else {
            database[hashedIndex].setArguments(values);
        }
    }

    ClassMode* GetDataBase() { return database; }

    int getCout() { return count; }

    int getCapacity() { return capacity; }

    void CleanDB() {
        capacity = 2;
        count = 0;

        ClassMode* newDataBase = new ClassMode[capacity];
        ClassMode* oldDataBase = database;
        database = newDataBase;

        delete[] oldDataBase;
    }

    ~DataBase() {
        delete[] database;
        capacity = 2;
        count = 0;
    }
};
