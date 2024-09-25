#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
private:
  unordered_map<string, int> cache;
  vector<string> dictionary;

  int dp(string remaining) {
    if(remaining.size() == 0) return 0;
    if(cache.find(remaining) != cache.end()) return cache[remaining];
    int result = remaining.size();
    for(string word: dictionary) {
      if(remaining.substr(0, word.size()) == word) {
        result = min(result, dp(remaining.substr(word.size())));
      }
    }
    result = min(result, 1 + dp(remaining.substr(1)));
    cache[remaining] = result;
    return result;
  }

public:
  int minExtraChar(string s, vector<string>& dictionary) {
    this->dictionary = dictionary;
    return dp(s);
  }
};
