#include <algorithm>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
  int countConsistentStrings(string allowed, vector<string>& words) {
    int res = 0;
    for(string word: words) {
      bool consistent = true; int i = 0;
      while(i < word.size() && consistent) consistent = allowed.find(word[i++]) != string::npos;
      res += consistent;
    }
    return res;
  }
};
