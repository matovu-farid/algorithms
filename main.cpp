// freopen("input.txt", "r", stdin);
// freopen("output.txt", "w", stdout);

#include "store/print.h"
#include "store/my_vector.h"
#include <iostream>
#include <string>
#include <vector>
using namespace std;

using namespace std;
void printPtr(int *p) {
  int oldValue = *p;
  while (true) {
    if (oldValue != *p) {
      oldValue = *p;

      cout << *p << endl;
    }
  }
}


int main() {
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  cout << "How big should the array be" << endl;
  int n;
  cin >> n;
  int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  my_vector<int> v {arr, 5};
  v.end();


  my_vector<int> m{v.begin(), v.end()};

  m.print();
  cout << m.length << endl;
  m.pop();
  m.print();
  cout << m.length << endl;
  m.insert(2, 100);
  m.print();
  cout << m.length << endl;
  
  
}
