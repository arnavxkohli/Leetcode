#include <string>
#include <vector>

using namespace std;

class Solution {
private:
  string s;

  tuple<string, int> decodeCount(int ptr) {
    if(ptr >= s.size()) return {"", s.size()};
    string curr = "", count = "";
    while(ptr < s.size() && s[ptr] != ']') {
      if(s[ptr] >= 'a') {
        curr.push_back(s[ptr]);
      } else if(s[ptr] <= '9') {
        count.push_back(s[ptr]);
      } else if(s[ptr] == '[') {
        auto [res, newPtr] = decodeCount(ptr+1);
        ptr = newPtr;
        for(int j=0; j<stoi(count); j++) {
          for(char c: res) {
            curr.push_back(c);
          }
        }
        count.clear();
      }
      ptr++;
    }
    return {curr, ptr};
  }

public:
  string decodeString(string s) {
    this->s = s;
    int ptr = 0;
    string res = "";
    while(ptr < s.size()) {
      if(s[ptr] >= 'a') {
        res.push_back(s[ptr]);
        ptr++;
      } else if(s[ptr] <= '9') {
        auto [newRes, newPtr] = decodeCount(ptr);
        ptr = newPtr;
        for(char c: newRes) {
          res.push_back(c);
        }
      }
    }
    return res;
  }
};
