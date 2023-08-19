#include <string>
#include <vector>
using namespace std;

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
