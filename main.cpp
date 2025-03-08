#include <iostream>
#include "lib/MySet.hpp"

int main([[maybe_unused]] int argc, [[maybe_unused]] char** argv) {
    MyVector<float> vector(1);
    vector.AddElement(1.12f);
    vector.AddElement(10.34f);
    vector.AddElement(10.34f);
    vector.AddElement(10.34f);
    vector.AddElement(10.34f);
    std::cout << "Вектор v: " << vector << std::endl;
    vector.AddElement(20.1f);
    vector.AddElement(20.1f);
    vector.AddElement(20.1f);
    std::cout << "Вектор v: " << vector << std::endl;
    MyVector v1 = vector;
    std::cout << "Вектор v1: " << v1 << std::endl;
    v1.DeleteElement(20.1f);

    std::cout << "Вектор v1: " << v1 << std::endl;

    MySet<float> mySet(1.34f), mySet1, mySet2;
    mySet.AddElement(23.23f);
    mySet.AddElement(5.12f);
    mySet.AddElement(9);
    double number = 8.1f;
    mySet.AddElement(number);
    std::cout << "Множество s: " << mySet << std::endl;
    mySet1.AddElement(4.2f);
    mySet1.AddElement(1.5f);
    mySet1.AddElement(5.5f);

    std::cout << "Множество s1: " << mySet1 << std::endl;
    mySet2 = mySet1 - mySet;
    // std::cout << "Множество s2=s1-s: " << s2 << std::endl;
    // std::cout << "Множество s1: " << s1 << std::endl;
    // std::cout << "Множество s: " << s << std::endl;
    // s2 = s - s1;
    // std::cout << "Множество s2=s-s1: " << s2 << std::endl;
    // std::cout << "Множество s1: " << s1 << std::endl;
    // std::cout << "Множество s: " << s << std::endl;
    // s2 = s1 + s;
    // std::cout << "Множество s2=s1+s: " << s2 << std::endl;
    // std::cout << "Множество s1: " << s1 << std::endl;
    // std::cout << "Множество s: " << s << std::endl;
    // s2 = s1 * s;
    // std::cout << "Множество s2=s1*s: " << s2 << std::endl;
    // std::cout << "Множество s1: " << s1 << std::endl;
    // std::cout << "Множество s: " << s << std::endl;
    // MySet s3 = s2;
    // std::cout << "Множество s3=s2: " << s3 << std::endl;
    // if (s3 == s2)
    //     std::cout << "Множество s3=s2\n";
    // else
    //     std::cout << "Множество s3!=s2\n";
    // if (s3 == s1)
    //     std::cout << "Множество s3=s1\n";
    // else
    //     std::cout << "Множество s3!=s1\n";
    // if (s1 == s3)
    //     std::cout << "Множество s1=s3\n";
    // else
    //     std::cout << "Множество s1!=s3\n";


    // MySet<int> set;
    // set.AddElement(10);
    // set.AddElement(2);
    // set.AddElement(3);
    // std::cout << set << std::endl;
    return 0;
}
