#include <iostream>

using namespace std;
template <typename T> struct my_vector {
  int capacity = 5;
  T *ptr = new T[capacity];
  int length = 0;
  void add(T a) {
    if (length == capacity) {
      expand();
    }
    *(ptr + length) = a;
    length += 1;
  }
  void pop(){
    *(ptr + length) = 0;
    length -= 1;

  }
  void print() {
    for (int i = 0; i < length; i++) {
      cout << *(ptr + i) << " ";
    }
  }
  void expand() {
    int temp_capacity = capacity;
    capacity *= 2;
    T *next_ptr = new T[capacity];
    for (int i = 0; i < temp_capacity; i++) {
      *(next_ptr + i) = *(ptr +i);
    }
     delete[] ptr;
    ptr = next_ptr;
  }
};
