#include <string>

using namespace std;

class Solution {
public:
  int maxVowels(string s, int k) {
    string vowels = "aeiou"; int vowelCount = 0;
    for(int i=0; i<k; i++) {
      if(vowels.find(s[i]) != string::npos) {
        vowelCount++;
      }
    }
    int res = vowelCount;
    int l = 0, r = k;
    while(r < s.size()){
      if(vowels.find(s[l]) != string::npos) {
        vowelCount--;
      }
      if(vowels.find(s[r]) != string::npos) {
        vowelCount++;
      }
      res = max(res, vowelCount);
      l++; r++;
    }
    return res;
  }
};
