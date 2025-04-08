#include "./PractiseSTLApp.hpp"
#include "./DateClass/DateClass.hpp"
#include "./TimeClass/TimeClass.hpp"

#include <fstream>
#include <iostream>
#include <limits>
#include <list>
#include <map>
#include <string>
#include <vector>

void PrintMenu() {
  std::cout << "-------------------------------------------------" << std::endl;
  std::cout << "|Введите номер задания, которое хотите выполнить|" << std::endl;
  std::cout << "-------------------------------------------------" << std::endl;
  std::cout << "Задание №1: на каких позициях начинается новое предложение"
            << std::endl;
  std::cout << "Задание №2: взять символы на нечётных позициях" << std::endl;
  std::cout << "Задание №3: заполнение файла без заглавных букв" << std::endl;
  std::cout << "Задание №4: работа с вектором из строк" << std::endl;
  std::cout << "Задание №5: работа с вектором из объектов класса Date"
            << std::endl;
  std::cout << "Задание №6: работа с list из строк" << std::endl;
  std::cout << "Задание №7: работа с list из объектов класса Time" << std::endl;
  std::cout << "Задание №8: вывод map Inventory" << std::endl;
  std::cout << "Задание №9: подсчёт количества учащихся в школе" << std::endl;
  std::cout << "Задание №10: выйти из программы" << std::endl;
  std::cout << std::endl;
}

template <typename T> void PrintList(std::list<T> listString) {
  int countEndString = 1;

  for (T stringElement : listString) {
    std::cout << countEndString << ' ' << stringElement << std::endl;
    ++countEndString;
  }
}

template <typename T> void PrintVector(std::vector<T> vector) {
  int countEndString = 1;
  for (long unsigned int i = 0; i < vector.size(); ++i) {
    std::cout << countEndString << ' ' << vector[i] << std::endl;
    ++countEndString;
  }
}

namespace PractiseSTLApp {
void CountQuantityStudents() {
  std::cout << std::endl;
  std::map<std::string, int> school{
      {"1а", 21}, {"1б", 20}, {"2", 25},  {"3a", 20}, {"3б", 23}, {"4а", 25},
      {"4б", 25}, {"5a", 26}, {"5б", 25}, {"6a", 19}, {"6б", 18}, {"7а", 26},
      {"7б", 25}, {"8", 25},  {"9", 17},  {"10", 15}, {"11", 14}};

  int result{};
  std::cout << "Школа" << std::endl;
  for (const auto &[className, quanity] : school) {
    std::cout << className << ": " << quanity << std::endl;
    result += quanity;
  }
  std::cout << std::endl;

  std::cout << "Количество учеников в школе: " << result << std::endl;
  std::cout << std::endl;
}

void ShowInventory() {
  std::cout << std::endl;
  std::map<std::string, int> inventory{{"Отверка", 0}, {"Молоток", 10},
                                       {"Гайки", 100}, {"Профиль", 0},
                                       {"Уголок", 9},  {"Доска", 17}};

  for (const auto &[name, quantity] : inventory) {
    if (quantity != 0) {
      std::cout << name << " - " << quantity << std::endl;
    }
  }
  std::cout << std::endl;
}

void CreateTimelist() {
  std::list<Time> timeList;
  Time d1(1, 2, 63);
  timeList.push_back(d1);
  Time d2(14, 57, 19);
  timeList.push_back(d2);
  Time d3(7, 32, 20);
  timeList.push_back(d3);
  Time d4(5, 13, 23);
  timeList.push_back(d4);
  Time d5(10, 19, 45);
  timeList.push_back(d5);
  Time d6(19, 9, 59);
  timeList.push_back(d6);
  std::cout << std::endl;
  PrintList(timeList);
  std::cout << std::endl;

  std::cout << "Cписок с подходящим временем" << std::endl;
  std::list<Time> timeListNew;
  Time beginMorningTime;
  Time endMorningTime(5, 0, 0);
  for (Time timeVal : timeList) {
    if ((timeVal < beginMorningTime) && (endMorningTime < timeVal)) {
      timeListNew.push_back(timeVal);
    }
  }

  PrintList(timeListNew);
}

void CreateListStrings() {
  std::list<std::string> stringsList;
  std::string stringElement;
  std::cout << std::endl;
  std::cout << "Введите строки" << std::endl;

  std::cin.clear();
  std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

  while (std::getline(std::cin, stringElement)) {
    if (stringElement == "") {
      break;
    }
    stringsList.push_back(stringElement);
  }

  PrintList(stringsList);
  std::cout << std::endl;

  if (stringsList.size() < 3) {
    std::cout << "Введённое вами количетсво строк не позволит выполнить задание"
              << std::endl;
    std::cout << std::endl;
    PrintList(stringsList);
    return;
  }

  auto it = stringsList.begin();
  std::advance(it, 2);

  stringsList.erase(it);
  PrintList(stringsList);
}

void CreateDateVector() {
  std::vector<Date> dateVector;
  Date d1(1, 2, 1963);
  dateVector.push_back(d1);
  Date d2(14, 7, 1995);
  dateVector.push_back(d2);
  Date d3(7, 12, 2088);
  dateVector.push_back(d3);
  Date d4(5, 3, 2030);
  dateVector.push_back(d4);
  Date d5(24, 9, 2013);
  dateVector.push_back(d5);
  Date d6(19, 9, 2020);
  dateVector.push_back(d6);
  std::cout << std::endl;
  PrintVector(dateVector);
  std::cout << std::endl;

  std::cout << "Вектор с будущими датами" << std::endl;
  std::vector<Date> dateVectorNew;
  Date nowDate(8, 4, 2025);
  for (long unsigned int i = 0; i < dateVector.size(); ++i) {
    if (dateVector[i] < nowDate) {
      dateVectorNew.push_back(dateVector[i]);
    }
  }

  PrintVector(dateVectorNew);
}

void CreateVectorStrings() {
  std::vector<std::string> stringsVector;
  std::string stringElement;
  std::cout << std::endl;
  std::cout << "Введите строки" << std::endl;

  std::cin.clear();
  std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

  while (std::getline(std::cin, stringElement)) {
    if (stringElement == "") {
      break;
    }
    stringsVector.push_back(stringElement);
  }
  PrintVector(stringsVector);
  std::cout << std::endl;

  if (stringsVector.size() < 3) {
    std::cout << "Введённое вами количетсво строк не позволит выполнить задание"
              << std::endl;
    std::cout << std::endl;
    PrintVector(stringsVector);
    return;
  }
  stringsVector.erase(stringsVector.begin() + 2);
  PrintVector(stringsVector);
}

void FillFile() {
  std::ifstream source("source.txt", std::ios::binary);
  std::ofstream result("result.txt", std::ios::out);

  std::cin.clear();
  std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
  std::string text;

  while (std::getline(source, text) || !source.eof()) {
    for (long unsigned int i = 0; i < text.length(); ++i) {
      if (int(text[i]) >= 65 && int(text[i]) <= 90) {
        result << char(std::tolower(text[i]));
        continue;
      }
      result << text[i];
    }
    result << '\n';
  }

  std::cout << std::endl;
  std::cout << "Заггляните, пожалуйста в файл" << std::endl;
  std::cout << std::endl;
}

void FindPositionSentence() {
  std::cout << std::endl;
  std::cout << "Введите текст" << std::endl;

  std::cin.clear();
  std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

  std::string sentence;
  std::getline(std::cin, sentence);
  std::cout << std::endl;

  int start{};

  while ((sentence.find('.', start) != std::string::npos) ||
         (sentence.find('?', start) != std::string::npos) ||
         (sentence.find('!', start) != std::string::npos)) {
    int posPoint =
        std::min(sentence.find('.', start), sentence.find('?', start));
    posPoint = std::min(static_cast<unsigned long>(posPoint),
                        sentence.find('!', start));

    for (int i = start; i < posPoint; ++i) {
      if (std::isdigit(sentence[i]) || std::isalpha(sentence[i])) {
        std::cout << i << ' ';
        break;
      }
    }
    start = posPoint + 1;
  }

  std::cout << std::endl;

  if (start == 0) {
    std::cout << "В этом тексте нет предложений" << std::endl;
  }
}

void CreateString() {
  std::cout << std::endl;
  std::cout << "Введите текст" << std::endl;

  std::cin.clear();
  std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

  std::string text;
  std::getline(std::cin, text);
  std::cout << std::endl;

  std::string newText{""};

  for (long unsigned int i = 0; i < text.length(); ++i) {
    if (i % 2 != 0) {
      newText.append(1, text[i]);
    }
  }

  std::cout << "Получившийся текст: " << newText << std::endl;
  std::cout << std::endl;
}

void SelectApp() {
  int numberTask = 2;
  PrintMenu();

  std::cin >> numberTask;
  std::cin.clear();

  while (numberTask) {
    switch (static_cast<Tasks>(numberTask)) {
    case Tasks::cinText:
      FindPositionSentence();
      break;

    case Tasks::createString:
      CreateString();
      break;

    case Tasks::fillFile:
      FillFile();
      break;

    case Tasks::createVectorStrings:
      CreateVectorStrings();
      break;

    case Tasks::createDateVector:
      CreateDateVector();
      break;
    case Tasks::createListStrings:
      CreateListStrings();
      break;
    case Tasks::createTimelist:
      CreateTimelist();
      break;
    case Tasks::showInventory:
      ShowInventory();
      break;
    case Tasks::countStudents:
      CountQuantityStudents();
      break;
    case Tasks::exitApp:
      return;
    default:
      std::cout << std::endl;
      std::cout << "Такого варианта нет" << std::endl;
      std::cout << std::endl;
    }

    PrintMenu();
    std::cin >> numberTask;
    std::cin.clear();
  }
}
} // namespace PractiseSTLApp
