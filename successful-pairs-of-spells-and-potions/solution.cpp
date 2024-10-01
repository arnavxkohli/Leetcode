#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
  vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
    sort(potions.begin(), potions.end());
    int n = potions.size();
    vector<int> res;
    for(const int& spell: spells) {
      int l = 0, r = n;
      while(l < r) {
        int mid = l + int((r-l)/2);
        if(static_cast<long long>(potions[mid]) * spell >= success) {
          r = mid;
        } else {
          l = mid + 1;
        }
      }
      res.push_back(n - l);
    }
    return res;
  }
};
