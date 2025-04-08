#include <iostream>

class Date {
  int day;
  int mounth;
  int year;

public:
  Date() : day(1), mounth(1), year(1979) {}

  Date(int dayValue, int mountValue, int yearValue)
      : day(dayValue), mounth(mountValue), year(yearValue) {}

  bool operator<(Date &other);

  bool operator==(Date &other);

  friend std::ostream &operator<<(std::ostream &cout, Date &other);
};

inline bool Date::operator<(Date &other) {
  if (other.year < year) {
    return true;
  } else if (other.year == year) {
    if (other.mounth < mounth) {
      return true;
    } else if (other.mounth == mounth) {
      if (other.day < day) {
        return true;
      }
    }
  }

  return false;
}

inline bool Date::operator==(Date &other) {
  if ((other.year == year) && (other.mounth == mounth) && (other.day == day)) {
    return true;
  }

  return false;
}

inline std::ostream &operator<<(std::ostream &cout, Date &other) {
  if (other.day < 10) {
    std::cout << '0' << other.day << '.';
  } else {
    std::cout << other.day << '.';
  }

  if (other.mounth < 10) {
    std::cout << '0' << other.mounth << '.';
  } else {
    std::cout << other.mounth << '.';
  }

  std::cout << other.year;

  return cout;
}
