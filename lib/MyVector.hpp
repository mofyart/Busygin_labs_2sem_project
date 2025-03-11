
#include <algorithm>
#include <cstring>
#include <iostream>
#include <typeinfo>

template <typename TypeElement> class MyVector {
protected:
  int capacity;
  int count;
  TypeElement *dataBase;

public:
  MyVector() {
    this->capacity = 1;
    this->count = {};
    this->dataBase = new TypeElement[this->capacity];
  }

  bool CheckExistObject(TypeElement object);

  void AddElement(TypeElement object);

  MyVector(TypeElement object);

  MyVector(MyVector &other);

  ~MyVector();

  void ReSize();

  bool DeleteElement(int indexDeletedElement);

  TypeElement operator[](int i);

  void SortDataBase();

  bool FindElement(TypeElement object);

  MyVector &operator=(const MyVector &other);

  template <typename T>
  friend std::ostream &operator<<(std::ostream &cout, MyVector<T> &other);
};

template <typename TypeElement>
std::ostream &operator<<(std::ostream &cout, MyVector<TypeElement> &other) {
  for (int i = 0; i < other.count; ++i) {
    std::cout << other.dataBase[i] << ' ';
  }
  return cout;
}

template <typename TypeElement>
void MyVector<TypeElement>::AddElement(TypeElement object) {
  ReSize();

  this->dataBase[this->count] = object;
  ++this->count;
}

template <> void MyVector<char *>::AddElement(char *object) {
  ReSize();
  this->dataBase[this->count] = new char[std::strlen(object) + 1]{};
  std::strcpy(dataBase[this->count], object);
  ++this->count;
}

template <typename TypeElement> void MyVector<TypeElement>::ReSize() {
  if (this->count >= this->capacity) {
    TypeElement *newDataBase = new TypeElement[this->capacity * 2];
    std::copy(this->dataBase, this->dataBase + this->count, newDataBase);

    TypeElement *oldDataBase = this->dataBase;

    this->dataBase = newDataBase;
    this->capacity *= 2;

    delete[] oldDataBase;
  }
}

template <typename TypeElement>
MyVector<TypeElement>::MyVector(TypeElement object) {
  this->capacity = 1;
  this->count = {};
  this->dataBase = new TypeElement[this->capacity];
  this->AddElement(object);
}

template <> MyVector<char *>::MyVector(char *object) {
  if (object == nullptr) {
    std::cout << "Нельзя передавать пустую строку" << std::endl;
    return;
  }

  this->capacity = 1;
  this->count = {};
  this->dataBase = new char *[this->capacity];
  this->AddElement(object);
}

template <typename TypeElement>
bool MyVector<TypeElement>::CheckExistObject(TypeElement object) {
  for (int i = 0; i < this->count; ++i) {
    if (this->dataBase[i] == object) {
      return false;
    }
  }

  return true;
}

template <> bool MyVector<char *>::CheckExistObject(char *object) {
  for (int i = 0; i < this->count; ++i) {
    if (std::strncmp(this->dataBase[i], object, std::strlen(object)) == 0) {
      return false;
    }
  }

  return true;
}

template <typename TypeElement> MyVector<TypeElement>::~MyVector() {
  delete[] this->dataBase;
}

template <> MyVector<char *>::~MyVector() {
  for (int i = 0; i < this->count; ++i) {
    delete[] this->dataBase[i];
  }

  delete[] this->dataBase;
}

template <typename TypeElement>
MyVector<TypeElement>::MyVector(MyVector &other) {
  this->capacity = other.capacity;
  this->count = other.count;
  this->dataBase = new TypeElement[this->capacity];

  std::copy(other.dataBase, other.dataBase + other.capacity, this->dataBase);
}

template <typename TypeElement>
bool MyVector<TypeElement>::DeleteElement(int indexDeletedElement) {
  for (int j = indexDeletedElement; j < this->capacity - 1; ++j) {
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

  return true;
}

template <typename TypeElement>
TypeElement MyVector<TypeElement>::operator[](int i) {
  return this->dataBase[i];
}

template <typename TypeElement> void MyVector<TypeElement>::SortDataBase() {
  for (int i = 0; i < this->count; ++i) {
    for (int j = 1; j < this->count - i; ++j) {
      if (this->dataBase[j - 1] > this->dataBase[j]) {
        std::swap(this->dataBase[j], this->dataBase[j - 1]);
      }
    }
  }
}

template <typename TypeElement>
MyVector<TypeElement> &MyVector<TypeElement>::operator=(const MyVector &other) {

  this->capacity = other.capacity;
  this->count = other.count;

  TypeElement *oldDatabase = this->dataBase;

  this->dataBase = new TypeElement[this->capacity];
  std::copy(other.dataBase, other.dataBase + other.capacity, this->dataBase);

  delete[] oldDatabase;

  return *this;
}

template <>
MyVector<char *> &MyVector<char *>::operator=(const MyVector<char *> &other) {
  if (this != &other) {

    for (int i = 0; i < count; ++i) {
      delete[] dataBase[i];
    }
    delete[] dataBase;

    count = other.count;
    capacity = other.capacity;
    dataBase = new char *[capacity];
    for (int i = 0; i < count; ++i) {
      dataBase[i] = new char[std::strlen(other.dataBase[i]) + 1];
      std::strcpy(dataBase[i], other.dataBase[i]);
    }
  }
  return *this;
}

template <typename TypeElement>
bool MyVector<TypeElement>::FindElement(TypeElement object) {
  int leftBoundary = 0;
  int rightBoudary = this->count - 1;
  int middleElement{};

  if (rightBoudary - leftBoundary == 0) {
    if (object == this->dataBase[middleElement]) {
      return true;
    }
  }

  int quanityElementsChecking = this->count;
  while (quanityElementsChecking != 0) {
    middleElement = (rightBoudary + leftBoundary) / 2;

    if (this->dataBase[middleElement] == object) {
      return true;
    } else if (this->dataBase[middleElement] > object) {
      leftBoundary = middleElement;
    } else {
      rightBoudary = middleElement;
    }

    --quanityElementsChecking;
  }

  return false;
}
