#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
  int longestSubarray(vector<int>& nums) {
    int candidate = *max_element(nums.begin(), nums.end());
    int l = 0, res = 1;
    while(l < nums.size()) {
      int r = l;
      while(r < nums.size() && nums[r] == candidate) r++;
      res = max(res, r-l);
      l = max(l+1, r);
    }
    return res;
  }
};