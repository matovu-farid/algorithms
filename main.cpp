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

  
  my_vector<int> m;
  for (int i = 0; i < n; i++)
    m.add(i);
  m.print();
  cout << m.length << endl;
  m.pop();
  m.print();
  cout << m.length << endl;
}
