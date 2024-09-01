#include <string>
#include <vector>
using namespace std;

class Solution {
public:
  string getRLE(string s) {
    string res = "";
    int ptr = 1;
    char currChar = s[0];
    int currCount = 1;
    while(ptr < s.size()) {
      if(s[ptr] == currChar) currCount++;
      else {
        res += to_string(currCount) + to_string(currChar-48);
        currChar = s[ptr], currCount = 1;
      }
      ptr++;
    }
    res += to_string(currCount) + to_string(currChar-48);
    return res;
  }

  string countAndSay(int n) {
    string res = "1";
    for(int i=2; i<=2; i++) {
      res = getRLE(res);
    }
    return res;
  }
};