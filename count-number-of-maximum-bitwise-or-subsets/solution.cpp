#include <vector>

using namespace std;


class Solution {
int maxOr = 0;
vector<int> nums;

private:
  int backtrack(int index, int currOr) {
    if(index == nums.size()) return currOr == maxOr;
    return backtrack(index+1, currOr) + backtrack(index+1, currOr | nums[index]);
  }

public:
  int countMaxOrSubsets(vector<int>& nums) {
    for(int num: nums) maxOr |= num;
    this->nums = nums;
    return backtrack(0, 0);
  }
};