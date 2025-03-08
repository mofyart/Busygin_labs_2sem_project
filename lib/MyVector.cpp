#include <iostream>
#include <cstring>
#include <algorithm>

template<typename TypeElement>
class MyVector {
    protected:
        int capacity;
        int count;
        TypeElement* dataBase;

    public:
        MyVector() {
            this->capacity = 1;
            this->count = {};
            this->dataBase = new TypeElement[this->capacity];
        }

        MyVector(TypeElement object) {
            this->capacity = 1;
            this->count = {};
            this->dataBase = new TypeElement[this->capacity];
            AddElement(object);
        }

        MyVector(MyVector& other) {
            this->capacity = other.capacity;
            this->count = other.count;
            this->dataBase = new TypeElement[this->capacity];

            std::copy(other.dataBase, other.dataBase + other.capacity, this->dataBase);
        }

        ~MyVector() {
            delete[] this->dataBase;
        }

        void ReSize() {
            if (this->count >= this->capacity) {
                TypeElement* newDataBase = new TypeElement[this->capacity * 2];
                std::copy(this->dataBase, this->dataBase + this->count, newDataBase);

                TypeElement* oldDataBase = this->dataBase;

                this->dataBase = newDataBase;
                this->capacity *= 2;

                delete[] oldDataBase;
            }
        }

        bool CheckExistObject(TypeElement object) {
            for (int i = 0; i < this->count; ++i) {
                if (this->dataBase[i] == object) {
                    return false;
                }
            }

            return true;
        }

        void AddElement(TypeElement object) {
            if (CheckExistObject(object)) {
                ReSize();
                this->dataBase[this->count] = object;
                ++this->count;
                SortDataBase();

                return;
            }

            std::cout << "Такой элемент уже есть" << std::endl;
        }

        bool DeleteElement(int indexDeletedElement) {
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

        // char* operator[](int i);

        void SortDataBase() {
            for (int i = 0; i < this->count; ++i) {
                for (int j = 1; j < this->count - i; ++j) {
                    if (this->dataBase[j - 1] > this->dataBase[j]) {
                        std::swap(this->dataBase[j], this->dataBase[j - 1]);
                    }
                }
            }
        }

        int getCount() { return this->count; }

        int getCapacity() { return this->capacity; }

        int FindElement(TypeElement object) {
            int leftBoundary = 0;
            int rightBoudary = this->count - 1;
            int middleElement{};
            while (rightBoudary - leftBoundary > 1) {
                middleElement = (rightBoudary + leftBoundary) / 2;

                if (this->dataBase[middleElement] == object) {
                    return middleElement;
                } else if (this->dataBase[middleElement] > object) {
                    leftBoundary = middleElement;
                } else {
                    rightBoudary = middleElement;
                }
            }
        }

        MyVector& operator=(MyVector& other) {
            this->capacity = other.capacity;
            this->count = other.count;
            this->dataBase = new TypeElement[this->capacity];

            std::copy(other.dataBase, other.dataBase + other.capacity, this->dataBase);

            return *this;
        }

        friend std::ostream &operator<<(std::ostream& cout, MyVector& other) {
            for (int i = 0; i < other.getCount(); ++i) {
                std::cout << other.dataBase[i] << ' ';
            }



            return cout;
        };
};
