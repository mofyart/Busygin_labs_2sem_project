#include <iostream>

#include "MyVector.hpp"

template<typename TypeElement>
class MySet : public MyVector<TypeElement> {
    public:
        MySet() : MyVector<TypeElement>::MyVector() {}

        MySet(TypeElement object) : MyVector<TypeElement>::MyVector(object) {}


        void AddElement(TypeElement object) {
            MyVector<TypeElement>::AddElement(object);
        }

        friend std::ostream &operator<<(std::ostream& cout, MySet& other) {
            for (int i = 0; i < other.getCount(); ++i) {
                std::cout << other.dataBase[i] << ' ';
            }

            return cout;
        }

        void DeleteElement(TypeElement object) {
            for (int i = 0; i < this->count; ++i) {
                if (this->dataBase[i] == object) {
                    for (int j = i; j < this->capacity - 1; ++j) {
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

                    return;
                }
            }

            std::cout << "Такого элемента нет" << std::endl;
        }

        friend MySet operator-(MySet& mySet1, MySet& mySet2) {
            MySet newMyset;

            for (int i = 0; i < m)

        }
        // bool operator==(MySet& other) {
        //     for (int i = 0; i < other.count)
        // }
};

// class MySet : public MyVector {
//  public:
//   MySet(char *el = NULL) : MyVector(el){};

//   MySet &operator+=(MySet &s);
//   MySet &operator-=(MySet &s);
//   MySet &operator*=(MySet &s);
//   void add_element(char *el);
//   void delete_element(char *el);
//   bool is_element(char *el);

//   friend MySet operator+(MySet &s1, MySet &s2);

//   friend MySet operator*(MySet &s1, MySet &s2);
// };
