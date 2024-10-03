#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
public:
  int minSubarray(vector<int>& nums, int p) {
    int remainder = 0;
    for(int num: nums) {
      remainder = (remainder + num) % p;
    }
    if(find(nums.begin(), nums.end(), remainder) != nums.end()) return 1;
    if(remainder == 0) return 0;
    int length = INT_MAX;
    unordered_map<int, int> prefixMap; int runningSum = 0;
    prefixMap[0] = -1;
    for(int i=0; i<nums.size(); i++) {
      runningSum = (runningSum + nums[i]) % p;
      int currentRemainder = (runningSum - remainder + p) % p;
      if(prefixMap.find(currentRemainder) != prefixMap.end()) {
        length = min(length, i - prefixMap[currentRemainder]);
      }
      prefixMap[runningSum] = i;
    }
    return length < nums.size() ? length : -1;
  }
};
