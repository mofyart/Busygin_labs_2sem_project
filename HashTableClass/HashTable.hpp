#include <algorithm>
#include <cstring>
#include <iostream>

#include "../InsitutionClass/Institution.hpp"

template<typename TypeElement>
class MyHashTable {
 protected:
    int capacity;
    int count;
    TypeElement* dataBase;

 public:
    MyHashTable();

    int HashKey(String key);

    void AddElement(TypeElement object);

    MyHashTable(TypeElement object);

    MyHashTable(MyHashTable& other);

    ~MyHashTable();

    void ReSize();

    void CleanVector();

    bool DeleteElement(int indexDeletedElement);

    TypeElement operator[](int i);

    bool FindElement(TypeElement object);

    MyHashTable& operator=(const MyHashTable& other);

    template<typename T>
    friend std::ostream& operator<<(std::ostream& cout, MyHashTable<T>& other);
};


template<>
inline MyHashTable<Institution*>::MyHashTable() {
    capacity = 6;
    count = {};
    dataBase = new Institution*[capacity]();
}

template<typename TypeElement>
std::ostream& operator<<(std::ostream& cout, MyHashTable<TypeElement>& other) {
    for (int i = 0; i < other.count; ++i) {
        std::cout << other.dataBase[i] << ' ';
    }
    return cout;
}

template<>
inline std::ostream& operator<<(std::ostream& cout, MyHashTable<Institution*>& other) {
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
inline int MyHashTable<TypeElement>::HashKey(String key) {
    int sumASCIISymbols = 0;
    const char* bufferString = key.getString();

    for (int i = 0; i < std::strlen(bufferString); ++i) {
        sumASCIISymbols += bufferString[i] * (i + 1);
    }

    return sumASCIISymbols % capacity;
}

template<typename TypeElement>
void MyHashTable<TypeElement>::ReSize() {
    if (count / capacity * 100 >= 70) {
        TypeElement* newDataBase = new TypeElement[capacity * 2];
        std::copy(dataBase, dataBase + count, newDataBase);

        TypeElement* oldDataBase = dataBase;

        dataBase = newDataBase;
        capacity *= 2;

        delete[] oldDataBase;
    }
}

template<>
inline void MyHashTable<Institution*>::ReSize() {
    if (count / capacity * 100 >= 70) {
        Institution** newDataBase = new Institution*[capacity * 2]();
        Institution** oldDataBase = dataBase;
        dataBase = newDataBase;

        for (int i = 0; i < capacity; ++i) {
            dataBase[i] = oldDataBase[i];
        }

        capacity *= 2;

        delete[] oldDataBase;
    }
}

template<>
inline void MyHashTable<Institution*>::AddElement(Institution* object) {
    ReSize();

    int hashedIndex = HashKey(object->getName());

    if (dataBase[hashedIndex] != nullptr) {
        int newCount = (hashedIndex == (capacity - 1)) ? 0 : hashedIndex + 1;
        while (dataBase[newCount] != nullptr) {
            if (newCount == (capacity - 1)) {
                newCount = -1;
            }
            ++newCount;
        }

        dataBase[newCount] = object;
    } else {
        dataBase[hashedIndex] = object;
    }
    ++count;
}



template<typename TypeElement>
void MyHashTable<TypeElement>::CleanVector() {
    for (int i = 0; i < count; ++i) {
        delete dataBase[i];
    }

    delete[] dataBase;

    capacity = 2;
    count = {};
    dataBase = new TypeElement[capacity];
}

template<typename TypeElement>
MyHashTable<TypeElement>::MyHashTable(TypeElement object) {
    this->capacity = 4;
    this->count = {};
    this->dataBase = new TypeElement[this->capacity];
    this->AddElement(object);
}


template<typename TypeElement>
MyHashTable<TypeElement>::~MyHashTable() {
    delete[] dataBase;
}

template<>
inline MyHashTable<Institution*>::~MyHashTable() {
    for (int i = 0; i < count; ++i) {
        delete dataBase[i];
    }

    delete[] dataBase;
}

template<typename TypeElement>
MyHashTable<TypeElement>::MyHashTable(MyHashTable& other) {
    this->capacity = other.capacity;
    this->count = other.count;
    this->dataBase = new TypeElement[this->capacity];

    std::copy(other.dataBase, other.dataBase + other.capacity, this->dataBase);
}

template<typename TypeElement>
bool MyHashTable<TypeElement>::DeleteElement(int indexDeletedElement) {
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
TypeElement MyHashTable<TypeElement>::operator[](int i) {
    return this->dataBase[i];
}


template<typename TypeElement>
MyHashTable<TypeElement>& MyHashTable<TypeElement>::operator=(const MyHashTable& other) {
    this->capacity = other.capacity;
    this->count = other.count;

    TypeElement* oldDatabase = this->dataBase;

    this->dataBase = new TypeElement[this->capacity];
    std::copy(other.dataBase, other.dataBase + other.capacity, this->dataBase);

    delete[] oldDatabase;

    return *this;
}

template<typename TypeElement>
bool MyHashTable<TypeElement>::FindElement(TypeElement object) {
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
