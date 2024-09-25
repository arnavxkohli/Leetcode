#include <vector>

using namespace std;

class Solution {
public:
  int triangularSum(vector<int>& nums) {
    vector<int> currNums = nums;
    while(currNums.size() > 1) {
      vector<int> newNums;
      for(int i=1; i<currNums.size(); i++) {
        newNums.push_back((currNums[i-1] + currNums[i]) % 10);
      }
      currNums = newNums;
    }
    return currNums[0];
  }
};
