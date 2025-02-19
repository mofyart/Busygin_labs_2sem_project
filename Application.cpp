#include "Application.hpp"

#include <limits>

namespace {
const char* nameFileSourcePlanet = "infoPlanet.txt";
const char* nameFileFill = "fillFile.txt";
const char* nameFileSourceCandidate = "infoCandidate.txt";
}  // namespace

namespace {
void PrintMenu() {
    std::cout << "----------------------------------------------------------------" << std::endl;
    std::cout << "| Перед вами находится меню операций, которые можете выполнить |" << std::endl;
    std::cout << "----------------------------------------------------------------" << std::endl;

    std::cout << "----------------------------------------------------------------" << std::endl;
    std::cout << "|        Опеоация №1: чтение БД из файла                        |" << std::endl;
    std::cout << "|        Операция №2: запись БД в файл                          |" << std::endl;
    std::cout << "|        Операция №3: сортировка БД                             |" << std::endl;
    std::cout << "|        Операция №4: добавление нового объекта в БД            |" << std::endl;
    std::cout << "|        Операция №5: удаление объекта из БД                    |" << std::endl;
    std::cout << "|        Операция №6: редактирование БД                         |" << std::endl;
    std::cout << "|        Операция №7: вывод БД на экран                         |" << std::endl;
    std::cout << "|        Операция №8: выход из программы                        |" << std::endl;
    std::cout << "-----------------------------------------------------------------" << std::endl;
}
}  // namespace

namespace AppObject {
void InputDBScreen(DataBase<Candidate>& dataBase) {
    std::cout << "----------------------------------------------------------------" << std::endl;
    std::cout << "|                   База данных кандидатов                     |" << std::endl;
    std::cout << "----------------------------------------------------------------" << std::endl;

    std::cout << "----------------------------------------------------------------" << std::endl;
    for (int i = 0; i < dataBase.getCapacity(); ++i) {
        if (dataBase.GetDataBase()[i].getdDiameterPlanet() == 0) {
            continue;
        }

        std::cout << dataBase.GetDataBase()[i].getNamePlanet().getString() << ' ' << dataBase.GetDataBase()[i].getdDiameterPlanet() << ' '
                  << dataBase.GetDataBase()[i].getHumanLifePlanet() << ' ' << dataBase.GetDataBase()[i].getSatelitesPlanet() << std::endl;
    }
    std::cout << "----------------------------------------------------------------" << std::endl;
}

void InputDBScreen(DataBase<Planet>& dataBase) {
    std::cout << "----------------------------------------------------------------" << std::endl;
    std::cout << "|                   База данных планет                         |" << std::endl;
    std::cout << "----------------------------------------------------------------" << std::endl;

    std::cout << "----------------------------------------------------------------" << std::endl;
    for (int i = 0; i < dataBase.getCapacity(); ++i) {
        if (dataBase.GetDataBase()[i].getdDiameterPlanet() == 0) {
            continue;
        }

        std::cout << dataBase.GetDataBase()[i].getNamePlanet().getString() << ' ' << dataBase.GetDataBase()[i].getdDiameterPlanet() << ' '
                  << dataBase.GetDataBase()[i].getHumanLifePlanet() << ' ' << dataBase.GetDataBase()[i].getSatelitesPlanet() << std::endl;
    }
    std::cout << "----------------------------------------------------------------" << std::endl;
}

void EditDB(DataBase<Planet>& dataBase) {
    Planet newPlanet;

    std::cout << std::endl;
    std::cout << "Введите название объекта на английском, которое хотите отредактировать" << std::endl;

    String nameStringPlanet;
    char* namePlanet = new char[1024];
    std::cin >> namePlanet;
    nameStringPlanet.setString(namePlanet);

    newPlanet.setName(nameStringPlanet);

    std::cout << "Введите диаметр планеты" << std::endl;
    int newDiameter{};
    std::cin >> newDiameter;
    newPlanet.setDiameter(newDiameter);

    std::cout << "Введите существует ли человеческая жизнь на этой планете (0/1)" << std::endl;
    bool existingHumanLife;
    std::cin >> existingHumanLife;
    newPlanet.setHumanLife(existingHumanLife);

    std::cout << "Введите какое количество спутников имеет планета" << std::endl;
    int quantitySatelites;
    std::cin >> quantitySatelites;
    newPlanet.setSatelites(quantitySatelites);

    dataBase.EditDataBase(newPlanet);
}

void EditDB(DataBase<Candidate>& dataBase) {
    Candidate newCandidate;
    std::cout << std::endl;
    std::cout << "Введите имя кандидата на английском, которое хотите отредактировать" << std::endl;

    String nameStringCandidate;
    char* nameCandidate = new char[1024];
    std::cin >> nameCandidate;
    nameStringCandidate.setString(nameCandidate);

    newCandidate.setName(nameStringCandidate);

    std::cout << "Введите возраст кандидата" << std::endl;
    int newDiameter{};
    std::cin >> newDiameter;
    newCandidate.setDiameter(newDiameter);

    std::cout << "Введите семейный кандидат или нет(0/1)" << std::endl;
    bool existingHumanLife;
    std::cin >> existingHumanLife;
    newCandidate.setHumanLife(existingHumanLife);

    std::cout << "Введите какое количество избирателей имеет кандидат" << std::endl;
    int quantitySatelites;
    std::cin >> quantitySatelites;
    newCandidate.setSatelites(quantitySatelites);

    dataBase.EditDataBase(newCandidate);
}

void DeleteObject(DataBase<Planet>& dataBase) {
    std::cout << std::endl;

    std::cout << "Введите название объекта на английском, который хотите удалить" << std::endl;
    char* namePlanet = new char[1024];
    std::cin >> namePlanet;

    dataBase.DeleteObject((namePlanet));
}

void DeleteObject(DataBase<Candidate>& dataBase) {
    std::cout << std::endl;

    std::cout << "Введите название объекта на английском, который хотите удалить" << std::endl;
    char* namePlanet = new char[1024];
    std::cin >> namePlanet;

    dataBase.DeleteObject((namePlanet));
}

void AddNewObject(DataBase<Candidate>& dataBase) {
    Candidate newCandidate;
    std::cout << std::endl;
    std::cout << "Введите имя кандидата на английском" << std::endl;

    String nameStringCandidate;
    char* nameCandidate = new char[1024];
    std::cin >> nameCandidate;
    nameStringCandidate.setString(nameCandidate);

    newCandidate.setName(nameStringCandidate);

    std::cout << "Введите возраст кандидата" << std::endl;
    int newDiameter{};
    std::cin >> newDiameter;
    if (std::cin.fail()) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Неверно введённый тип" << std::endl;
        return;
    }
    newCandidate.setDiameter(newDiameter);

    std::cout << "Введите семейный кандидат или нет(0/1)" << std::endl;
    bool existingHumanLife;
    std::cin >> existingHumanLife;
    newCandidate.setHumanLife(existingHumanLife);

    std::cout << "Введите какое количество избирателей имеет кандидат" << std::endl;
    int quantitySatelites;
    std::cin >> quantitySatelites;
    if (std::cin.fail()) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Неверно введённый тип" << std::endl;
        return;
    }
    newCandidate.setSatelites(quantitySatelites);

    dataBase.AddNewObject(newCandidate);
}

void AddNewObject(DataBase<Planet>& dataBase) {
    Planet newPlanet;
    std::cout << std::endl;
    std::cout << "Введите название объекта на английском" << std::endl;

    String nameStringPlanet;
    char* namePlanet = new char[1024];
    std::cin >> namePlanet;
    nameStringPlanet.setString(namePlanet);

    newPlanet.setName(nameStringPlanet);

    std::cout << "Введите диаметр планеты" << std::endl;
    int newDiameter{};
    std::cin >> newDiameter;
    if (std::cin.fail()) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Неверно введённый тип" << std::endl;
        return;
    }
    newPlanet.setDiameter(newDiameter);

    std::cout << "Введите существует ли человеческая жизнь на этой планете (0/1)" << std::endl;
    bool existingHumanLife;
    std::cin >> existingHumanLife;
    newPlanet.setHumanLife(existingHumanLife);

    std::cout << "Введите какое количество спутников имеет планета" << std::endl;
    int quantitySatelites;
    std::cin >> quantitySatelites;
    if (std::cin.fail()) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Неверно введённый тип" << std::endl;
        return;
    }
    newPlanet.setSatelites(quantitySatelites);

    dataBase.AddNewObject(newPlanet);
}

void FillFile(DataBase<Planet>& dataBase) {
    std::ofstream target(nameFileFill);

    if (!target) {
        std::cout << "Такого файла нет" << std::endl;
        return;
    }

    for (int i = 0; i < dataBase.getCapacity(); ++i) {
        if (dataBase.GetDataBase()[i].getdDiameterPlanet() == 0) {
            continue;
        }

        target << dataBase.GetDataBase()[i];
    }
    target.close();
}

void FillFile(DataBase<Candidate>& dataBase) {
    std::ofstream target(nameFileFill);

    if (!target) {
        std::cout << "Такого файла нет" << std::endl;
        return;
    }

    for (int i = 0; i < dataBase.getCapacity(); ++i) {
        if (dataBase.GetDataBase()[i].getdDiameterPlanet() == 0) {
            continue;
        }

        target << dataBase.GetDataBase()[i];
    }
    target.close();
}

void ReadFile(DataBase<Candidate>& dataBase) {
    std::ifstream source(nameFileSourceCandidate, std::ios::in);

    if (!source) {
        std::cout << "Такого файла нет" << std::endl;
        return;
    }

    while (source) {
        Candidate newCandidate;
        source >> newCandidate;

        if (newCandidate.getdDiameterPlanet() == 0) {
            break;
        }

        dataBase.AddNewObject(newCandidate);
    }
    source.close();
}

void ReadFile(DataBase<Planet>& dataBase) {
    std::ifstream source(nameFileSourcePlanet, std::ios::in);

    if (!source) {
        std::cout << "Такого файла нет" << std::endl;
        return;
    }

    while (source) {
        Planet newPlanet;
        source >> newPlanet;
        if (newPlanet.getdDiameterPlanet() == 0) {
            break;
        }

        dataBase.AddNewObject(newPlanet);
    }
    source.close();
}

void SelectTask(int variantMode) {
    int numberTask = {};

    switch (static_cast<TypeMode>(variantMode)) {
        case TypeMode::classPlanet: {
            DataBase<Planet> dataBasePlanet;

            while (true) {
                PrintMenu();

                std::cout << "Выберите операцию" << std::endl;
                std::cin >> numberTask;

                switch (static_cast<NumberTask>(numberTask)) {
                    case NumberTask::readDBFile:
                        dataBasePlanet.CleanDB();
                        ReadFile(dataBasePlanet);
                        break;
                    case NumberTask::outputDBFile:
                        FillFile(dataBasePlanet);
                        break;
                    case NumberTask::sortDB:
                        dataBasePlanet.SortDataBase();
                        break;
                    case NumberTask::addNewObject:
                        AddNewObject(dataBasePlanet);
                        break;
                    case NumberTask::deleteObject:
                        DeleteObject(dataBasePlanet);
                        break;
                    case NumberTask::editBD:
                        EditDB(dataBasePlanet);
                        break;
                    case NumberTask::inputDBScreen:
                        InputDBScreen(dataBasePlanet);
                        break;
                    case NumberTask::exitMode:
                        return;
                    default:
                        std::cout << "Такой операции нет" << std::endl;
                }
            }

            break;
        }
        case TypeMode::classCandidate: {
            DataBase<Candidate> dataBaseCandidate;

            while (true) {
                PrintMenu();

                std::cout << "Выберите операцию" << std::endl;
                std::cin >> numberTask;

                switch (static_cast<NumberTask>(numberTask)) {
                    case NumberTask::readDBFile:
                        dataBaseCandidate.CleanDB();
                        ReadFile(dataBaseCandidate);
                        break;
                    case NumberTask::outputDBFile:
                        FillFile(dataBaseCandidate);
                        break;
                    case NumberTask::sortDB:
                        dataBaseCandidate.SortDataBase();
                        break;
                    case NumberTask::addNewObject:
                        AddNewObject(dataBaseCandidate);
                        break;
                    case NumberTask::deleteObject:
                        DeleteObject(dataBaseCandidate);
                        break;
                    case NumberTask::editBD:
                        EditDB(dataBaseCandidate);
                        break;
                    case NumberTask::inputDBScreen:
                        InputDBScreen(dataBaseCandidate);
                        break;
                    case NumberTask::exitMode:
                        return;
                    default:
                        std::cout << "Такой операции нет" << std::endl;
                }
            }
            break;
        }
    }
}

void RunApp() {
    int varinatMode{};

    while (true) {
        std::cout << "Какое задание хотите выполнить ?" << std::endl;
        std::cout << std::endl;
        std::cout << "Вариант №1: использовать класс Планет" << std::endl;
        std::cout << "Вариант №2: использовать класс Кандедат" << std::endl;
        std::cout << "Вариант №3: Выйти из программы" << std::endl;
        std::cout << std::endl;
        std::cout << "Введите номер варианта" << std::endl;
        std::cin >> varinatMode;

        switch (static_cast<TypeMode>(varinatMode)) {
            case TypeMode::classPlanet:
                SelectTask(varinatMode);
                break;
            case TypeMode::classCandidate:
                SelectTask(varinatMode);
                break;
            case TypeMode::exitApp:
                return;
        }
    }
}
}  // namespace AppObject
