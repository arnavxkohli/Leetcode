#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
  int maxOperations(vector<int>& nums, int k) {
    sort(nums.begin(), nums.end());
    int l = 0, r = nums.size()-1, res = 0;
    while(l < r) {
      int curSum = nums[l] + nums[r];
      if(curSum == k) {
        l++; r--; res++;
      } else if (curSum > k) {
        r--;
      } else {
        l++;
      }
    }
    return res;
  }
};
