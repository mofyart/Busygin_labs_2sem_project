#include "lib/MySet.hpp"
#include <iostream>
#include <string>

int main([[maybe_unused]] int argc, [[maybe_unused]] char **argv) {
  // MyVector<std::string> vector("asd");
  // vector.AddElement("asd");
  // vector.AddElement("asd");
  // vector.AddElement("asd");
  // vector.AddElement("asd");
  // std::cout << std::endl;
  // std::cout << "Вектор v: " << vector << std::endl;

  // vector.AddElement("qwe");
  // vector.AddElement("qwe");
  // vector.AddElement("qwe");
  // // vector.AddElement(20);
  // // vector.AddElement(20);
  // std::cout << std::endl;
  // std::cout << "Вектор v: " << vector << std::endl;

  // MyVector<std::string> v1 = vector;
  // std::cout << std::endl;
  // std::cout << "второй элемент вектора:" << v1[1] << std::endl;
  // std::cout << std::endl;
  // std::cout << "Вектор v1: " << v1 << std::endl;
  // v1.DeleteElement(0);

  // std::cout << "Вектор v1: " << v1 << std::endl;
  // std::cout << std::endl;
  // MySet<std::string> mySet("art"), mySet1, mySet2;
  // mySet.AddElement("dff");
  // mySet.AddElement("dqwe");
  // mySet.AddElement("ert");
  // std::string number = "yui";
  // mySet.AddElement(number);
  // std::cout << std::endl;

  // std::cout << "Множество s: " << mySet << std::endl;
  // mySet.DeleteElement("yui");

  // std::cout << "Множество s: " << mySet << std::endl;
  // mySet1.AddElement("csd");
  // mySet1.AddElement("swa");
  // mySet1.AddElement("ert");
  // std::cout << std::endl;
  // std::cout << "Множество s1: " << mySet1 << std::endl;
  // mySet2 = mySet1 - mySet;

  // std::cout << std::endl;
  // std::cout << "Множество s2=s1-s: " << mySet2 << std::endl;
  // std::cout << "Множество s1: " << mySet1 << std::endl;
  // std::cout << "Множество s: " << mySet << std::endl;
  // std::cout << std::endl;

  // mySet2 = mySet - mySet1;
  // std::cout << "Множество s2=s-s1: " << mySet2 << std::endl;
  // std::cout << "Множество s1: " << mySet1 << std::endl;
  // std::cout << "Множество s: " << mySet << std::endl;
  // std::cout << std::endl;

  // mySet2 = mySet1 + mySet;
  // std::cout << "Множество s2=s1+s: " << mySet2 << std::endl;
  // std::cout << "Множество s1: " << mySet1 << std::endl;
  // std::cout << "Множество s: " << mySet << std::endl;
  // std::cout << std::endl;

  // mySet2 = mySet1 * mySet;
  // std::cout << "Множество s2=s1*s: " << mySet2 << std::endl;
  // std::cout << "Множество s1: " << mySet1 << std::endl;
  // std::cout << "Множество s: " << mySet << std::endl;
  // std::cout << std::endl;

  // MySet mySet3 = mySet2;
  // std::cout << "Множество s3=s2: " << mySet3 << std::endl;
  // std::cout << std::endl;

  // if (mySet3 == mySet2) {
  //   std::cout << "Множество s3=s2\n";
  // } else {
  //   std::cout << "Множество s3!=s2\n";
  // }
  // std::cout << std::endl;
  // if (mySet3 == mySet1) {
  //   std::cout << "Множество s3=s1\n";
  // } else {
  //   std::cout << "Множество s3!=s1\n";
  // }
  // std::cout << std::endl;
  // if (mySet1 == mySet3) {
  //   std::cout << "Множество s1=s3\n";
  // } else {
  //   std::cout << "Множество s1!=s3\n";
  // }

  // std::cout << std::endl;
  // mySet2 += mySet1;
  // std::cout << "Множество s2+=s1: " << mySet2 << std::endl;
  // std::cout << "Множество s1: " << mySet1 << std::endl;

  // std::cout << std::endl;
  // mySet2 = mySet;
  // mySet2 *= mySet1;
  // std::cout << "Множество s2*=s1: " << mySet2 << std::endl;
  // std::cout << "Множество s1: " << mySet1 << std::endl;
  // std::cout << "Множество s: " << mySet << std::endl;

  // std::cout << std::endl;
  // mySet1 -= mySet2;
  // std::cout << "Множество s1-=s2: " << mySet1 << std::endl;
  // std::cout << "Множество s1: " << mySet2 << std::endl;
  // std::cout << std::endl;

  // if (mySet1.ExistingElement("csd")) {
  //   std::cout << "Такой элемент есть" << std::endl;
  // } else {
  //   std::cout << "Такого элемента нет" << std::endl;
  // }

  std::cout << std::endl;
  std::cout << "-----------------------------------------" << std::endl;
  std::cout << std::endl;

  MyVector<char *> v("Hello!");
  v.AddElement("Привет!");
  v.AddElement("Привет!");
  v.AddElement("Привет!");
  std::cout << "Вектор v: " << v << std::endl;
  std::cout << std::endl;
  v.AddElement("Привет!");
  v.AddElement("Привет!");
  v.AddElement("Привет!");
  std::cout << "Вектор v: " << v << std::endl;
  std::cout << std::endl;

  MyVector<char *> vector2 = v;
  std::cout << "Вектор v2: " << vector2 << std::endl;
  std::cout << std::endl;
  vector2.DeleteElement(0);
  std::cout << "Вектор v2: " << vector2 << std::endl;
  std::cout << std::endl;

  MySet<char *> mySetChar("Yes"), mySetChar1, mySetChar2;
  mySetChar.AddElement("Привет!");
  mySetChar.AddElement("No");

  std::cout << "Множество s: " << mySetChar << std::endl;
  mySetChar.DeleteElement("No");
  std::cout << "Множество s: " << mySetChar << std::endl;
  mySetChar.AddElement("No");
  std::cout << std::endl;

  char *str = "Hello!";
  mySetChar.AddElement(str);
  std::cout << "Множество s: " << mySetChar << std::endl;
  std::cout << std::endl;

  mySetChar1.AddElement("Cat");
  mySetChar1.AddElement("No");
  mySetChar1.AddElement("Привет!");
  std::cout << "Множество s1: " << mySetChar1 << std::endl;
  std::cout << std::endl;

  std::cout << "Множество s2=s1-s: " << mySetChar2 << std::endl;
  mySetChar2 = mySetChar1 - mySetChar;
  std::cout << "Множество s2=s1-s: " << mySetChar2 << std::endl;
  std::cout << "Множество s1: " << mySetChar1 << std::endl;
  std::cout << "Множество s: " << mySetChar << std::endl;
  std::cout << std::endl;

  mySetChar2 = mySetChar - mySetChar1;
  std::cout << "Множество s2=s-s1: " << mySetChar2 << std::endl;
  std::cout << "Множество s1: " << mySetChar1 << std::endl;
  std::cout << "Множество s: " << mySetChar << std::endl;
  std::cout << std::endl;

  mySetChar2 = mySetChar1 + mySetChar;
  std::cout << "Множество s2=s1+s: " << mySetChar2 << std::endl;
  std::cout << "Множество s1: " << mySetChar1 << std::endl;
  std::cout << "Множество s: " << mySetChar << std::endl;
  std::cout << std::endl;

  std::cout << mySetChar2 << std::endl;
  mySetChar2 = mySetChar1 * mySetChar;
  std::cout << "Множество s2=s1*s: " << mySetChar2 << std::endl;
  std::cout << "Множество s1: " << mySetChar1 << std::endl;
  std::cout << "Множество s: " << mySetChar << std::endl;
  std::cout << std::endl;

  MySet mySetChar3 = mySetChar2;
  std::cout << "Множество s3=s2: " << mySetChar3 << std::endl;

  if (mySetChar3 == mySetChar2) {
    std::cout << "Множество s3=s2\n";
  } else {
    std::cout << "Множество s3!=s2\n";
  }

  if (mySetChar3 == mySetChar1) {
    std::cout << "Множество s3=s1\n";
  } else {
    std::cout << "Множество s3!=s1\n";
  }

  if (mySetChar1 == mySetChar3) {
    std::cout << "Множество s1=s3\n";
  } else {
    std::cout << "Множество s1!=s3\n";
  }

  std::cout << std::endl;
  mySetChar2 += mySetChar1;
  std::cout << "Множество s2+=s1: " << mySetChar2 << std::endl;
  std::cout << "Множество s1: " << mySetChar1 << std::endl;

  std::cout << std::endl;
  mySetChar2 = mySetChar;
  mySetChar2 *= mySetChar1;
  std::cout << "Множество s2*=s1: " << mySetChar2 << std::endl;
  std::cout << "Множество s1: " << mySetChar1 << std::endl;
  std::cout << "Множество s: " << mySetChar << std::endl;

  std::cout << std::endl;
  mySetChar1 -= mySetChar2;
  std::cout << "Множество s1-=s2: " << mySetChar1 << std::endl;
  std::cout << "Множество s2: " << mySetChar2 << std::endl;
  std::cout << std::endl;
  std::cout << "Первый элемент в веткоре:" << mySetChar1[0] << std::endl;

  std::cout << std::endl;
  if (mySetChar1.ExistingElement("Cat")) {
    std::cout << "Такой элемент есть" << std::endl;
  } else {
    std::cout << "Такого элемента нет" << std::endl;
  }

  MyVector<char *> v4;
  char *str1 = new char[]{"Hi"};
  char *str2 = new char[]{"Hello"};
  char *str3 = new char[]{"Bye"};
  v4.AddElement(str1);
  v4.AddElement(str2);
  v4.AddElement(str3);
  delete[] str1;
  delete[] str2;
  delete[] str3;
  std::cout << v4 << std::endl;

  // std::cout << std::endl;
  // std::cout << "-----------------------------------------" << std::endl;
  // std::cout << std::endl;

  // MyVector<const char*> vector("asd");
  // vector.AddElement("asd");
  // vector.AddElement("asd");
  // vector.AddElement("asd");
  // vector.AddElement("asd");
  // std::cout << std::endl;
  // std::cout << "Вектор v: " << vector << std::endl;

  // vector.AddElement("qwe");
  // vector.AddElement("qwe");
  // vector.AddElement("qwe");
  // std::cout << std::endl;
  // std::cout << "Вектор v: " << vector << std::endl;

  // MyVector<const char*> v1 = vector;
  // std::cout << std::endl;
  // std::cout << "второй элемент вектора:" << v1[1] << std::endl;
  // std::cout << std::endl;
  // std::cout << "Вектор v1: " << v1 << std::endl;
  // v1.DeleteElement(0);

  // std::cout << "Вектор v1: " << v1 << std::endl;
  // std::cout << std::endl;
  // MySet<const char*> mySet("art"), mySet1, mySet2;
  // mySet.AddElement("dff");
  // mySet.AddElement("dqwe");
  // mySet.AddElement("ert");
  // const char* number = "yui";
  // mySet.AddElement(number);
  // std::cout << std::endl;

  // std::cout << "Множество s: " << mySet << std::endl;
  // mySet.DeleteElement("yui");

  // std::cout << "Множество s: " << mySet << std::endl;
  // mySet1.AddElement("csd");
  // mySet1.AddElement("swa");
  // mySet1.AddElement("ert");
  // std::cout << std::endl;
  // std::cout << "Множество s1: " << mySet1 << std::endl;
  // mySet2 = mySet1 - mySet;

  // std::cout << std::endl;
  // std::cout << "Множество s2=s1-s: " << mySet2 << std::endl;
  // std::cout << "Множество s1: " << mySet1 << std::endl;
  // std::cout << "Множество s: " << mySet << std::endl;
  // std::cout << std::endl;

  // mySet2 = mySet - mySet1;
  // std::cout << "Множество s2=s-s1: " << mySet2 << std::endl;
  // std::cout << "Множество s1: " << mySet1 << std::endl;
  // std::cout << "Множество s: " << mySet << std::endl;
  // std::cout << std::endl;

  // mySet2 = mySet1 + mySet;
  // std::cout << "Множество s2=s1+s: " << mySet2 << std::endl;
  // std::cout << "Множество s1: " << mySet1 << std::endl;
  // std::cout << "Множество s: " << mySet << std::endl;
  // std::cout << std::endl;

  // mySet2 = mySet1 * mySet;
  // std::cout << "Множество s2=s1*s: " << mySet2 << std::endl;
  // std::cout << "Множество s1: " << mySet1 << std::endl;
  // std::cout << "Множество s: " << mySet << std::endl;
  // std::cout << std::endl;

  // MySet mySet3 = mySet2;
  // std::cout << "Множество s3=s2: " << mySet3 << std::endl;
  // std::cout << std::endl;

  // if (mySet3 == mySet2) {
  //   std::cout << "Множество s3=s2\n";
  // } else {
  //   std::cout << "Множество s3!=s2\n";
  // }
  // std::cout << std::endl;
  // if (mySet3 == mySet1) {
  //   std::cout << "Множество s3=s1\n";
  // } else {
  //   std::cout << "Множество s3!=s1\n";
  // }
  // std::cout << std::endl;
  // if (mySet1 == mySet3) {
  //   std::cout << "Множество s1=s3\n";
  // } else {
  //   std::cout << "Множество s1!=s3\n";
  // }

  // std::cout << std::endl;
  // mySet2 += mySet1;
  // std::cout << "Множество s2+=s1: " << mySet2 << std::endl;
  // std::cout << "Множество s1: " << mySet1 << std::endl;

  // std::cout << std::endl;
  // mySet2 = mySet;
  // mySet2 *= mySet1;
  // std::cout << "Множество s2*=s1: " << mySet2 << std::endl;
  // std::cout << "Множество s1: " << mySet1 << std::endl;
  // std::cout << "Множество s: " << mySet << std::endl;

  // std::cout << std::endl;
  // mySet1 -= mySet2;
  // std::cout << "Множество s1-=s2: " << mySet1 << std::endl;
  // std::cout << "Множество s1: " << mySet2 << std::endl;
  // std::cout << std::endl;

  // if (mySet1.ExistingElement("csd")) {
  //   std::cout << "Такой элемент есть" << std::endl;
  // } else {
  //   std::cout << "Такого элемента нет" << std::endl;
  // }

  std::cout << std::endl;
  std::cout << "-----------------------------------------" << std::endl;
  std::cout << std::endl;

  MyVector<int> vector(20);
  vector.AddElement(20);
  vector.AddElement(20);
  vector.AddElement(20);
  vector.AddElement(20);
  std::cout << std::endl;
  std::cout << "Вектор v: " << vector << std::endl;

  vector.AddElement(1);
  vector.AddElement(1);
  vector.AddElement(1);
  std::cout << std::endl;
  std::cout << "Вектор v: " << vector << std::endl;

  MyVector<int> v1 = vector;
  std::cout << std::endl;
  std::cout << "второй элемент вектора:" << v1[1] << std::endl;
  std::cout << std::endl;
  std::cout << "Вектор v1: " << v1 << std::endl;
  v1.DeleteElement(0);

  std::cout << "Вектор v1: " << v1 << std::endl;
  std::cout << std::endl;
  MySet<int> mySet(23), mySet1, mySet2;
  mySet.AddElement(10);
  mySet.AddElement(1);
  mySet.AddElement(20);
  int number = 6;
  mySet.AddElement(number);
  std::cout << std::endl;

  std::cout << "Множество s: " << mySet << std::endl;
  mySet.DeleteElement(6);

  std::cout << "Множество s: " << mySet << std::endl;
  mySet1.AddElement(3);
  mySet1.AddElement(1);
  mySet1.AddElement(56);
  std::cout << std::endl;
  std::cout << "Множество s1: " << mySet1 << std::endl;
  mySet2 = mySet1 - mySet;

  std::cout << std::endl;
  std::cout << "Множество s2=s1-s: " << mySet2 << std::endl;
  std::cout << "Множество s1: " << mySet1 << std::endl;
  std::cout << "Множество s: " << mySet << std::endl;
  std::cout << std::endl;

  mySet2 = mySet - mySet1;
  std::cout << "Множество s2=s-s1: " << mySet2 << std::endl;
  std::cout << "Множество s1: " << mySet1 << std::endl;
  std::cout << "Множество s: " << mySet << std::endl;
  std::cout << std::endl;

  mySet2 = mySet1 + mySet;
  std::cout << "Множество s2=s1+s: " << mySet2 << std::endl;
  std::cout << "Множество s1: " << mySet1 << std::endl;
  std::cout << "Множество s: " << mySet << std::endl;
  std::cout << std::endl;

  mySet2 = mySet1 * mySet;
  std::cout << "Множество s2=s1*s: " << mySet2 << std::endl;
  std::cout << "Множество s1: " << mySet1 << std::endl;
  std::cout << "Множество s: " << mySet << std::endl;
  std::cout << std::endl;

  MySet mySet3 = mySet2;
  std::cout << "Множество s3=s2: " << mySet3 << std::endl;
  std::cout << std::endl;

  if (mySet3 == mySet2) {
    std::cout << "Множество s3=s2\n";
  } else {
    std::cout << "Множество s3!=s2\n";
  }
  std::cout << std::endl;
  if (mySet3 == mySet1) {
    std::cout << "Множество s3=s1\n";
  } else {
    std::cout << "Множество s3!=s1\n";
  }
  std::cout << std::endl;
  if (mySet1 == mySet3) {
    std::cout << "Множество s1=s3\n";
  } else {
    std::cout << "Множество s1!=s3\n";
  }

  std::cout << std::endl;
  mySet2 += mySet1;
  std::cout << "Множество s2+=s1: " << mySet2 << std::endl;
  std::cout << "Множество s1: " << mySet1 << std::endl;

  std::cout << std::endl;
  mySet2 = mySet;
  mySet2 *= mySet1;
  std::cout << "Множество s2*=s1: " << mySet2 << std::endl;
  std::cout << "Множество s1: " << mySet1 << std::endl;
  std::cout << "Множество s: " << mySet << std::endl;

  std::cout << std::endl;
  mySet1 -= mySet2;
  std::cout << "Множество s1-=s2: " << mySet1 << std::endl;
  std::cout << "Множество s2: " << mySet2 << std::endl;
  std::cout << std::endl;

  if (mySet1.ExistingElement(3)) {
    std::cout << "Такой элемент есть" << std::endl;
  } else {
    std::cout << "Такого элемента нет" << std::endl;
  }

  return 0;
}
