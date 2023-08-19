#include <climits>
#include <iostream>
#include <set>
#include <string>
#include <vector>
using namespace std;
template<typename T>
void print(T t){
  for (auto i : t ){
    cout << i << " ";
  }
  cout << endl;
}
vector<int> dp(100000, -1);
string crypt(string s, string key){
  string val = "";
  for (int i = 0; i < s.length(); i++){
    int keyIdx = i % key.length();
    char sChar = s[i];
    char keyChar = key[keyIdx];
    int encryptedNum = ( int(sChar) ^ int(keyChar)) ;
    char valChar = char(encryptedNum);
    val += valChar;

  }
  return val;
}


int grundy(int n) {
  if (n == 0) return 0;
  if (dp[n] != -1) return dp[n];
  set<int> values;
  for (int i = n - 1; i >= max(n - 3, 0); i--){
    values.insert(grundy(i));
  }

  int mex = 0;
  while(values.find(mex) != values.end())
    mex += 1;
  dp[n] = mex;
  return mex;

}

int main() {
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  freopen("output.txt", "w", stderr);
  string s, key;
  std::getline(std::cin, s);
  std::getline(std::cin, key);
  string encryted = crypt(s, key);
  string decryted = crypt(encryted, key);
  
  cout << "encryted: " << encryted << endl;
  cout << "decryted: " << decryted << endl;
  vector<int> v = {1, 2, 3, 4, 5};
  vector<string> m = {"a", "b", "c", "d"};
  print(v);
  print(m);
  print("a");

  return 0;
}
