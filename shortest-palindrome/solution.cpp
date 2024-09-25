#include <string>
#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
  string shortestPalindrome(string s) {
    if (s.empty()) return s;
    long long prefixHash = 0ll, postfixHash = 0ll, power = 1ll;
    long long mod = 1e9 + 7;
    int longest = 0;
    for (int i = 0; i < s.size(); ++i) {
      prefixHash = (prefixHash * 29 + s[i] - 'a' + 1) % mod;
      postfixHash = (postfixHash + (s[i] - 'a' + 1) * power) % mod;
      power = (power * 29) % mod;
      if (prefixHash == postfixHash) longest = i + 1;
    }
    string reversed = string(s.rbegin(), s.rbegin() + s.size() - longest);
    return reversed + s;
  }
};
