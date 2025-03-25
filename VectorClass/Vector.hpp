#include <algorithm>
#include <cstring>
#include <iostream>

#include "../InsitutionClass/Institution.hpp"

template<typename TypeElement>
class MyVector {
 protected:
    int capacity;
    int count;
    TypeElement* dataBase;

 public:
    MyVector();

    bool CheckExistObject(TypeElement object);

    void AddElement(TypeElement object);

    MyVector(TypeElement object);

    MyVector(MyVector& other);

    ~MyVector();

    void ReSize();

    void CleanVector();

    bool DeleteElement(int indexDeletedElement);

    TypeElement operator[](int i);

    void SortDataBase();

    bool FindElement(TypeElement object);

    MyVector& operator=(const MyVector& other);

    template<typename T>
    friend std::ostream& operator<<(std::ostream& cout, MyVector<T>& other);
};

template<typename TypeElement>
MyVector<TypeElement>::MyVector() {
    capacity = 2;
    count = {};
    dataBase = new TypeElement[capacity];
}

template<typename TypeElement>
std::ostream& operator<<(std::ostream& cout, MyVector<TypeElement>& other) {
    for (int i = 0; i < other.count; ++i) {
        std::cout << other.dataBase[i] << ' ';
    }
    return cout;
}

template<>
inline std::ostream& operator<<(std::ostream& cout, MyVector<Institution*>& other) {
    std::cout << std::endl;
    std::cout << "--------------------------" << std::endl;
    std::cout << "| Содержимое базы данных |" << std::endl;
    std::cout << "--------------------------" << std::endl;

    for (int i = 0; i < other.count; ++i) {
        std::cout << i + 1 << ' ';
        other.dataBase[i]->Show();
    }

    std::cout << std::endl;
    return cout;
}

template<typename TypeElement>
void MyVector<TypeElement>::AddElement(TypeElement object) {
    ReSize();

    this->dataBase[this->count] = object;
    ++this->count;
}

template<typename TypeElement>
void MyVector<TypeElement>::ReSize() {
    if (count >= capacity) {
        TypeElement* newDataBase = new TypeElement[capacity * 2];
        std::copy(dataBase, dataBase + count, newDataBase);

        TypeElement* oldDataBase = dataBase;

        dataBase = newDataBase;
        capacity *= 2;

        delete[] oldDataBase;
    }
}

template<typename TypeElement>
void MyVector<TypeElement>::CleanVector() {
    for (int i = 0; i < count; ++i) {
        delete dataBase[i];
    }

    delete[] dataBase;

    capacity = 2;
    count = {};
    dataBase = new TypeElement[capacity];
}

template<typename TypeElement>
MyVector<TypeElement>::MyVector(TypeElement object) {
    this->capacity = 1;
    this->count = {};
    this->dataBase = new TypeElement[this->capacity];
    this->AddElement(object);
}

template<typename TypeElement>
bool MyVector<TypeElement>::CheckExistObject(TypeElement object) {
    for (int i = 0; i < this->count; ++i) {
        if (this->dataBase[i] == object) {
            return false;
        }
    }

    return true;
}

template<typename TypeElement>
MyVector<TypeElement>::~MyVector() {
    delete[] dataBase;
}

template<>
inline MyVector<Institution*>::~MyVector() {
    for (int i = 0; i < count; ++i) {
        delete dataBase[i];
    }

    delete[] dataBase;
}

template<typename TypeElement>
MyVector<TypeElement>::MyVector(MyVector& other) {
    this->capacity = other.capacity;
    this->count = other.count;
    this->dataBase = new TypeElement[this->capacity];

    std::copy(other.dataBase, other.dataBase + other.capacity, this->dataBase);
}

template<typename TypeElement>
bool MyVector<TypeElement>::DeleteElement(int indexDeletedElement) {
    for (int j = indexDeletedElement; j < this->capacity - 1; ++j) {
        std::swap(this->dataBase[j], this->dataBase[j + 1]);
    }
    --this->count;

    if (this->count < (this->capacity / 4)) {
        this->capacity = this->capacity / 2;
        TypeElement* newVector = new TypeElement[this->capacity];
        std::copy(this->dataBase, this->dataBase + this->capacity, newVector);
        TypeElement* oldVector;

        oldVector = this->dataBase;
        this->dataBase = newVector;

        delete[] oldVector;
    }

    return true;
}

template<typename TypeElement>
TypeElement MyVector<TypeElement>::operator[](int i) {
    return this->dataBase[i];
}

template<typename TypeElement>
void MyVector<TypeElement>::SortDataBase() {
    for (int i = 0; i < this->count; ++i) {
        for (int j = 1; j < this->count - i; ++j) {
            if (this->dataBase[j - 1] > this->dataBase[j]) {
                std::swap(this->dataBase[j], this->dataBase[j - 1]);
            }
        }
    }
}

template<typename TypeElement>
MyVector<TypeElement>& MyVector<TypeElement>::operator=(const MyVector& other) {
    this->capacity = other.capacity;
    this->count = other.count;

    TypeElement* oldDatabase = this->dataBase;

    this->dataBase = new TypeElement[this->capacity];
    std::copy(other.dataBase, other.dataBase + other.capacity, this->dataBase);

    delete[] oldDatabase;

    return *this;
}

template<typename TypeElement>
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
