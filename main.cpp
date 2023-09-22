#ifndef ONLINE_JUDGE
#include "store/print.h"
#endif

#include <iostream>
#include <vector>
using ll = long long;

using namespace std;
/*
 Decode Permutation
There is an integer array perm that is a permutation of the first n positive integers, where n is always odd.

It was encoded into another integer array encoded of length n - 1, such that encoded[i] = perm[i] XOR perm[i + 1]. For example, if perm = [1,3,2], then encoded = [2,1].

Given the encoded array, return the original array perm. It is guaranteed that the answer exists and is unique.
 */
vector<int> decode(vector<int> encoded) {
    int n = encoded.size() + 1; // Length of the original perm array
    vector<int> perm(n); // Initialize the original array

    // Find the XOR of all elements from 1 to n
    int XOR_all = 0;
    for (int i = 1; i <= n; ++i) {
        XOR_all ^= i;
    }

    // Find the XOR of the encoded array, skipping every other element
    int XOR_encoded = 0;
    for (int i = 1; i < encoded.size(); i += 2) {
        XOR_encoded ^= encoded[i];
    }

    // Find the first element in the original perm array
    perm[0] = XOR_all ^ XOR_encoded;

    // Use the first element to decode the rest of the array
    for (int i = 0; i < encoded.size(); ++i) {
        perm[i + 1] = perm[i] ^ encoded[i];
    }

    return perm;
}
void solve() {

  vector<int> encoded = {3, 1};
  vector<int> output = decode(encoded);
  print(output);
}

int main() {
#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
#endif
  ios::sync_with_stdio(0);
  cin.tie(0);
  solve();

  return 0;
}
