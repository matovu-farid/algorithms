#include <string>
#include <vector>
#include <iostream>
#include <set>
#include <map>

#pragma once
using namespace std;
template<typename T>
void print(T t){
     cout << t << " ";
}
template<typename T>
void print(vector<T> t){
  for (auto i : t ){
    print(i);
  }
  cout << endl;
}

template<typename T>
void print(set<T> t){
  for (auto i : t ){
    print(i);
  }
  cout << endl;
}
template<class K, class T>
void print(pair<K,T> t){
    K key = t.first;
    T val = t.second;
  cout << key << ": " << val <<endl;
}
template<class K, class T>
void print(map<K,T> t){
  for (auto i : t ){
    print(i);
  }
  cout << endl;
}


