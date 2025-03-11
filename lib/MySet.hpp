#include "MyVector.hpp"
#include <iostream>

template <typename TypeElement> class MySet : public MyVector<TypeElement> {
public:
  MySet() : MyVector<TypeElement>::MyVector() {}

  MySet(TypeElement object) : MyVector<TypeElement>::MyVector(object) {}

  void AddElement(TypeElement object);

  void DeleteElement(TypeElement object);

  bool ExistingElement(TypeElement element);

  template <typename T>
  friend std::ostream &operator<<(std::ostream &cout, const MySet<T> &other);

  template <typename T>
  friend MySet<T> operator-(MySet<T> &mySet1, MySet<T> &mySet2);

  template <typename T>
  friend MySet<T> operator+(MySet<T> &mySet1, MySet<T> &mySet2);

  template <typename T>
  friend MySet<T> operator*(MySet<T> &mySet1, MySet<T> &mySet2);

  MySet &operator+=(MySet &otherMySet);

  MySet &operator*=(MySet &otherMySet);

  MySet &operator-=(MySet &otherMySet);

  MySet &operator=(const MySet &otherMySet);

  TypeElement operator[](int index);

  bool operator==(MySet &other);
};

template <typename TypeElement>
void MySet<TypeElement>::AddElement(TypeElement object) {
  if (MyVector<TypeElement>::CheckExistObject(object)) {
    MyVector<TypeElement>::AddElement(object);
    return;
  }

  std::cout << "Такой элемент уже есть" << std::endl;
}

template <typename TypeElement>
void MySet<TypeElement>::DeleteElement(TypeElement object) {
  for (int i = 0; i < this->count; ++i) {
    if (this->dataBase[i] == object) {
      for (int j = i; j < this->capacity - 1; ++j) {
        std::swap(this->dataBase[j], this->dataBase[j + 1]);
      }
      --this->count;

      if (this->count < (this->capacity / 4)) {
        this->capacity = this->capacity / 2;
        TypeElement *newVector = new TypeElement[this->capacity];
        std::copy(this->dataBase, this->dataBase + this->capacity, newVector);
        TypeElement *oldVector;

        oldVector = this->dataBase;
        this->dataBase = newVector;

        delete[] oldVector;
      }

      return;
    }
  }

  std::cout << "Такого элемента нет" << std::endl;
}

template <> void MySet<char *>::DeleteElement(char *object) {
  for (int i = 0; i < this->count; ++i) {
    if (std::strncmp(object, this->dataBase[i],
                     std::strlen(this->dataBase[i])) == 0) {
      for (int j = i; j < this->capacity - 1; ++j) {
        std::swap(this->dataBase[j], this->dataBase[j + 1]);
      }
      --this->count;

      if (this->count < (this->capacity / 4)) {
        this->capacity = this->capacity / 2;
        char **newVector = new char *[this->capacity];
        std::copy(this->dataBase, this->dataBase + this->capacity, newVector);

        for (int i = 0; i < this->count; ++i) {
          std::strcpy(newVector[i], dataBase[i]);
        }

        char **oldVector;

        oldVector = this->dataBase;

        for (int i = 0; i < this->count + 1; ++i) {
          oldVector[i] = this->dataBase[i];
        }

        this->dataBase = newVector;
        for (int i = 0; i < this->count; ++i) {
          this->dataBase[i] = newVector[i];
        }

        for (int i = 0; i < this->count + 1; ++i) {
          delete[] oldVector[i];
        }

        delete[] oldVector;
      }

      return;
    }
  }

  std::cout << "Такого элемента нет" << std::endl;
}

template <typename TypeElement>
bool MySet<TypeElement>::ExistingElement(TypeElement element) {
  return MyVector<TypeElement>::FindElement(element);
}

template <> bool MySet<char *>::ExistingElement(char *element) {
  for (int i = 0; i < this->count; ++i) {
    if (std::strncmp(element, this->dataBase[i],
                     std::strlen(this->dataBase[i])) == 0) {
      return true;
    }
  }

  return false;
}

template <typename TypeElement>
std::ostream &operator<<(std::ostream &cout, const MySet<TypeElement> &other) {
  for (int i = 0; i < other.count; ++i) {
    std::cout << other.dataBase[i] << ' ';
  }

  return cout;
}

template <typename TypeElement>
MySet<TypeElement> operator-(MySet<TypeElement> &mySet1,
                             MySet<TypeElement> &mySet2) {
  MySet<TypeElement> newMyset;

  for (int i = 0; i < mySet1.count; ++i) {
    bool existIntersections = false;
    for (int j = 0; j < mySet2.count; ++j) {
      if (mySet1.dataBase[i] == mySet2.dataBase[j]) {
        existIntersections = true;
      }
    }

    if (existIntersections == false) {
      newMyset.AddElement(mySet1.dataBase[i]);
    }
  }

  return newMyset;
}

template <>
MySet<char *> operator-(MySet<char *> &mySet1, MySet<char *> &mySet2) {
  MySet<char *> newMyset;

  for (int i = 0; i < mySet1.count; ++i) {
    bool existIntersections = false;
    for (int j = 0; j < mySet2.count; ++j) {
      if (std::strncmp(mySet1.dataBase[i], mySet2.dataBase[j],
                       std::strlen(mySet1.dataBase[i])) == 0) {
        existIntersections = true;
      }
    }

    if (existIntersections == false) {
      newMyset.AddElement(mySet1.dataBase[i]);
    }
  }

  return newMyset;
}

template <typename TypeElement>
MySet<TypeElement> operator+(MySet<TypeElement> &mySet1,
                             MySet<TypeElement> &mySet2) {
  MySet<TypeElement> newMySet;

  for (int i = 0; i < mySet1.count; ++i) {
    newMySet.AddElement(mySet1.dataBase[i]);
  }

  for (int i = 0; i < mySet2.count; ++i) {
    newMySet.AddElement(mySet2.dataBase[i]);
  }

  return newMySet;
}

template <typename TypeElement>
MySet<TypeElement> operator*(MySet<TypeElement> &mySet1,
                             MySet<TypeElement> &mySet2) {
  MySet<TypeElement> newMySet;

  for (int i = 0; i < mySet1.count; ++i) {
    bool existIntersections = false;
    for (int j = 0; j < mySet2.count; ++j) {
      if (mySet1.dataBase[i] == mySet2.dataBase[j]) {
        newMySet.AddElement(mySet1.dataBase[i]);
      }
    }
  }

  return newMySet;
}

template <>
MySet<char *> operator*(MySet<char *> &mySet1, MySet<char *> &mySet2) {
  MySet<char *> newMySet;

  for (int i = 0; i < mySet1.count; ++i) {
    bool existIntersections = false;
    for (int j = 0; j < mySet2.count; ++j) {
      if (std::strncmp(mySet1.dataBase[i], mySet2.dataBase[j],
                       std::strlen(mySet1.dataBase[i])) == 0) {
        newMySet.AddElement(mySet1.dataBase[i]);
      }
    }
  }

  return newMySet;
}

template <typename TypeElement>
MySet<TypeElement> &
MySet<TypeElement>::operator+=(MySet<TypeElement> &otherMySet) {
  for (int i = 0; i < otherMySet.count; ++i) {
    AddElement(otherMySet.dataBase[i]);
  }

  return *this;
}

template <typename TypeElement>
MySet<TypeElement> &
MySet<TypeElement>::operator*=(MySet<TypeElement> &otherMySet) {
  TypeElement *copyDataBase = new TypeElement[this->count];
  std::copy(this->dataBase, this->dataBase + this->count, copyDataBase);
  int initialCount = this->count;

  delete[] this->dataBase;

  this->capacity = 1;
  this->count = 0;
  this->dataBase = new TypeElement[this->capacity];

  for (int i = 0; i < initialCount; ++i) {
    bool existIntersections = false;
    for (int j = 0; j < otherMySet.count; ++j) {
      if (copyDataBase[i] == otherMySet.dataBase[j]) {
        AddElement(copyDataBase[i]);
      }
    }
  }

  return *this;
}

template <>
MySet<char *> &MySet<char *>::operator*=(MySet<char *> &otherMySet) {
  char **copyDataBase = new char *[this->count];
  std::copy(this->dataBase, this->dataBase + this->count, copyDataBase);
  for (int i = 0; i < this->count; ++i) {
    copyDataBase[i] = new char[std::strlen(this->dataBase[i]) + 1];
    std::strcpy(copyDataBase[i], this->dataBase[i]);
  }

  int initialCount = this->count;

  for (int i = 0; i < initialCount; ++i) {
    delete[] this->dataBase[i];
  }

  delete[] this->dataBase;

  this->capacity = 1;
  this->count = 0;
  this->dataBase = new char *[this->capacity];

  for (int i = 0; i < initialCount; ++i) {
    for (int j = 0; j < otherMySet.count; ++j) {
      if (std::strncmp(copyDataBase[i], otherMySet.dataBase[j],
                       std::strlen(copyDataBase[i])) == 0) {
        AddElement(copyDataBase[i]);
      }
    }
  }

  return *this;
}

template <typename TypeElement>
MySet<TypeElement> &
MySet<TypeElement>::operator-=(MySet<TypeElement> &otherMySet) {
  TypeElement *copyDataBase = new TypeElement[this->count];
  std::copy(this->dataBase, this->dataBase + this->count, copyDataBase);
  int initialCount = this->count;

  delete[] this->dataBase;

  this->capacity = 1;
  this->count = 0;
  this->dataBase = new TypeElement[this->capacity];

  for (int i = 0; i < initialCount; ++i) {
    bool existIntersections = false;
    for (int j = 0; j < otherMySet.count; ++j) {
      if (copyDataBase[i] == otherMySet.dataBase[j]) {
        existIntersections = true;
      }
    }

    if (existIntersections == false) {
      AddElement(copyDataBase[i]);
    }
  }

  return *this;
}

template <>
MySet<char *> &MySet<char *>::operator-=(MySet<char *> &otherMySet) {
  char **copyDataBase = new char *[this->count];
  std::copy(this->dataBase, this->dataBase + this->count, copyDataBase);
  for (int i = 0; i < this->count; ++i) {
    copyDataBase[i] = new char[std::strlen(this->dataBase[i]) + 1];
    std::strcpy(copyDataBase[i], this->dataBase[i]);
  }

  int initialCount = this->count;

  for (int i = 0; i < initialCount; ++i) {
    delete[] this->dataBase[i];
  }

  delete[] this->dataBase;

  this->capacity = 1;
  this->count = 0;
  this->dataBase = new char *[this->capacity];

  for (int i = 0; i < initialCount; ++i) {
    bool existIntersections = false;
    for (int j = 0; j < otherMySet.count; ++j) {
      if (std::strncmp(copyDataBase[i], otherMySet.dataBase[j],
                       std::strlen(copyDataBase[i])) == 0) {
        existIntersections = true;
      }
    }

    if (existIntersections == false) {
      AddElement(copyDataBase[i]);
    }
  }

  return *this;
}

template <typename TypeElement>
MySet<TypeElement> &
MySet<TypeElement>::operator=(const MySet<TypeElement> &otherMySet) {
  MyVector<TypeElement>::operator=(otherMySet);

  return *this;
}

template <typename TypeElement>
TypeElement MySet<TypeElement>::operator[](int index) {
  return MyVector<TypeElement>::operator[](index);
}

template <typename TypeElement>
bool MySet<TypeElement>::operator==(MySet<TypeElement> &other) {
  if (other.count != this->count) {
    return false;
  }

  for (int i = 0; i < other.count; ++i) {
    if (this->dataBase[i] != other.dataBase[i]) {
      return false;
    }
  }

  return true;
}

template <> bool MySet<char *>::operator==(MySet<char *> &other) {
  if (other.count != this->count) {
    return false;
  }

  for (int i = 0; i < other.count; ++i) {
    if (std::strncmp(this->dataBase[i], other.dataBase[i],
                     std::strlen(this->dataBase[i])) != 0) {
      return false;
    }
  }

  return true;
}
