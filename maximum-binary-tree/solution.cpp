#include <vector>

using namespace std;

struct TreeNode {
  int val;
  TreeNode* left;
  TreeNode* right;
  TreeNode(int _val=0, TreeNode* _left=nullptr, TreeNode* _right=nullptr): val(_val), left(_left), right(_right) {}
};

class Solution {
private:
  vector<int> nums;

  TreeNode* constructTree(int l, int r) {
    if(l >= r) return nullptr;
    int maxVal = nums[l], maxIndex = l;
    for(int i = l + 1; i < r; i++) {
      if(nums[i] > maxVal) {
        maxVal = nums[i];
        maxIndex = i;
      }
    }
    TreeNode* res = new TreeNode(maxVal, constructTree(l, maxIndex), constructTree(maxIndex + 1, r));
    return res;
  }

public:
  TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
    this->nums = nums;
    return constructTree(0, nums.size());
  }
};
