#include <iostream>

using namespace std;
template <typename T> struct my_vector {
  int capacity = 5;
  T *ptr = new T[capacity];
  int length = 0;
  void push(T a) {
    if (length == capacity) {
      expand();
    }
    *(ptr + length) = a;
    length += 1;
  }
  T pop() {
    T val = *(ptr + length);
    *(ptr + length) = 0;
    length -= 1;
    return val;
  }
  void insert(int index, int value) {
    capacity += 1;

    int temp_capacity = capacity;
    T *next_ptr = new T[capacity];
    copy(next_ptr, 0, index);
    *(next_ptr + index) = value;
    copy(next_ptr, index, temp_capacity, 1);
    delete[] ptr;
    ptr = next_ptr;
  }
  

  void print() {
    for (int i = 0; i < length; i++) {
      cout << *(ptr + i) << " ";
    }
  }
  void expand() {
    int temp_capacity = capacity;
    capacity = 2 * capacity;
    T *next_ptr = new T[capacity];
    copy(next_ptr, 0, temp_capacity);
    delete[] ptr;
    ptr = next_ptr;
  }
  void copy(T *new_ptr, int start, int end , int offset = 0) {
    for (int i = start; i < end; i++) {
      *(new_ptr + i + offset) = *(ptr + i);
    }
  }
};
