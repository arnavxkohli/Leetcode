#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
  bool checkInclusion(string s1, string s2) {
    if(s1.size() > s2.size()) return false;
    unordered_map<char, int> s1Map, s2Map;
    int s1Count = 0, s2Count = 0;
    for(char c: s1) {
      s1Map[c]++;
    }
    s1Count = s1Map.size();
    for(int i=0; i<s1.size(); i++) {
      char c = s2[i];
      if(s1Map.find(c) == s1Map.end()) continue;
      s2Map[c]++;
      if(s1Map[c] == s2Map[c]) s2Count++;
    }
    if(s1Count == s2Count) return true;
    for(int i=s1.size(); i<s2.size(); i++) {
      char remove = s2[i-s1.size()], add = s2[i];
      if(s1Map.find(remove) != s1Map.end()) {
        if(s1Map[remove] == s2Map[remove]) s2Count--;
        s2Map[remove]--;
      }
      if(s1Map.find(add) != s1Map.end()) {
        s2Map[add]++;
        if(s1Map[add] == s2Map[add]) s2Count++;
      }
      if(s1Count == s2Count) return true;
    }
    return false;
  }
};
