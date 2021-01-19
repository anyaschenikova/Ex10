// Copyright 2021 Schenikova
#ifndef INCLUDE_MYSTACK_H_
#define INCLUDE_MYSTACK_H_

template<class T>
class MyStack {
 private:
  int maxSize;
  int currentSize;
  T* data;

 public:
  explicit MyStack(unsigned int size) {
    currentSize = 0;
    maxSize = size;
    data = new T[maxSize];
  }

  MyStack(const MyStack& newStack) {
    currentSize = newStack.currentSize;
    maxSize = newStack.maxSize;
    data = new T[maxSize];
    for (unsigned i = 0; i < currentSize; i++)
      data[i] = newStack.data[i];
  }

  ~MyStack() {
    delete[] data;
  }

  T get() const {
    if (!isEmpty())
      return data[currentSize - 1];
  }

  T pop() {
    if (!isEmpty()) {
      currentSize -= 1;
      return data[currentSize];
    }
  }

  void push(T value) {
    if (!isFull()) {
      data[currentSize++] = value;
    }
  }

  bool isFull() const {
    return (maxSize == currentSize) ? 1 : 0;
  }

  bool isEmpty() const {
    return (currentSize == 0) ? 1 : 0;
  }
};

#endif  // INCLUDE_MYSTACK_H_
