#include <string>
#include <vector>

using namespace std;

class Solution {
public:
  int compress(vector<char>& chars) {
    string charString = "";
    for(char c: chars) {
      charString.push_back(c);
    }
    chars.clear();
    int ptr = 1, count = 1; char curr = charString[0];
    while(ptr < charString.size()) {
      if(charString[ptr] == curr) {
        count++;
      } else {
        chars.push_back(curr);
        if(count > 1){
          for(char c: to_string(count)) {
            chars.push_back(c);
          }
        }
        curr = charString[ptr], count = 1;
      }
      ptr++;
    }
    chars.push_back(curr);
    if(count > 1){
      for(char c: to_string(count)) {
        chars.push_back(c);
      }
    }
    return chars.size();
  }
};
