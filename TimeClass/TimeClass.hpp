#include <iostream>

class Time {
  int hour;
  int minute;
  int second;

public:
  Time() : hour(0), minute(0), second(0) {}

  Time(int hourValue, int minuteValue, int secondValue)
      : hour(hourValue), minute(minuteValue), second(secondValue) {}

  bool operator<(Time &other);

  bool operator==(Time &other);

  friend std::ostream &operator<<(std::ostream &cout, Time &other);
};

inline bool Time::operator<(Time &other) {
  if (other.hour < hour) {
    return true;
  }

  return false;
}

inline bool Time::operator==(Time &other) {
  if ((other.second == second) && (other.minute == minute) &&
      (other.hour == hour)) {
    return true;
  }

  return false;
}

inline std::ostream &operator<<(std::ostream &cout, Time &other) {
  if (other.hour < 10) {
    std::cout << '0' << other.hour << ':';
  } else {
    std::cout << other.hour << ':';
  }

  if (other.minute < 10) {
    std::cout << '0' << other.minute << ':';
  } else {
    std::cout << other.minute << ':';
  }

  std::cout << other.second;

  return cout;
}
