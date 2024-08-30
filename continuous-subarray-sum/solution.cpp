#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
  bool checkSubarraySum(vector<int>& nums, int k) {
    if(nums.size() < 2) return false;
    if((nums[0] + nums[1]) % k == 0) return true;
    unordered_map<int, int> prefixMap;
    prefixMap[0] = -1;
    int runningSum = 0;
    for(int i=0; i<nums.size(); i++) {
      runningSum = (runningSum + nums[i]) % k;
      if(prefixMap.find(runningSum) != prefixMap.end()) {
        if(i-prefixMap[runningSum] > 1) return true;
      }
      else if(prefixMap.find(runningSum) == prefixMap.end()) prefixMap[runningSum] = i;
    }
    return false;
  }
};
