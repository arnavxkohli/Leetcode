#include <algorithm>
using namespace std;

struct TreeNode {
  int val;
  TreeNode* left;
  TreeNode* right;
  TreeNode(int _val=0, TreeNode* _left=nullptr, TreeNode* _right=nullptr) : val(_val), left(_left), right(_right) {}
};

class Solution {
private:
  int depth(TreeNode* root) {
    return (root == nullptr) ? 0 : 1 + max(depth(root->left), depth(root->right));
  }

public:
  TreeNode* lcaDeepestLeaves(TreeNode* root) {
    int leftDepth = depth(root->left), rightDepth = depth(root->right);
    if(leftDepth == rightDepth) return root;
    return leftDepth > rightDepth ? lcaDeepestLeaves(root->left) : lcaDeepestLeaves(root->right);
  }
};
