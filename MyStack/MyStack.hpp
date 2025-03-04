#pragma once

#include <iostream>

template <class Object, class FRIEND> class ListNode {
private:
  Object informationNode;
  ListNode *nextNode;
  ListNode() : nextNode(nullptr) {}
  friend FRIEND;
};

template <class Object> class MyStack {
  typedef class ListNode<Object, MyStack<Object>> Node;
  Node *nodeTop;

public:
  MyStack() : nodeTop(nullptr) {};

  ~MyStack() {
    while (!CheckEmpty()) {
      PopObject();
    }
  }

  bool CheckEmpty() {
    if (!nodeTop) {
      return true;
    }

    return false;
  }

  void PushObject(Object object) {
    Node *newNode = new Node;
    newNode->informationNode = object;
    newNode->nextNode = nodeTop;
    nodeTop = newNode;
  }

  void PopObject() {
    if (!CheckEmpty()) {
      Node *oldNode = nodeTop;
      nodeTop = nodeTop->nextNode;
      delete oldNode;
    } else {
      std::cerr << "Стек пуст" << std::endl;
      return;
    }
  }

  Object GetInformationNode() {
    if (!CheckEmpty()) {
      Object informationNode = nodeTop->informationNode;
      PopObject();
      return informationNode;
    } else {
      std::cerr << "Стек пуст" << std::endl;
      return -1;
    }

    return 0;
  }
};
