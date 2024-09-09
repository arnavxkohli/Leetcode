struct ListNode {
  int val;
  ListNode* next;
  ListNode(int _val=0, ListNode* _next=nullptr) : val(_val), next(_next) {}
};

struct TreeNode {
  int val;
  TreeNode* left;
  TreeNode* right;
  TreeNode(int _val=0, TreeNode* _left=nullptr, TreeNode* _right=nullptr) :
    val(_val), left(_left), right(_right) {}
};

class Solution {
private:
  bool pathMatch(ListNode *head, TreeNode *root) {
    if(head == nullptr) return true;
    if(root == nullptr || root->val != head->val) return false;
    return pathMatch(head->next, root->left) || pathMatch(head->next, root->right);
  }

public:
  bool isSubPath(ListNode *head, TreeNode *root) {
    if(root == nullptr) return false;
    if(pathMatch(head, root)) return true;
    return isSubPath(head, root->left) || isSubPath(head, root->right);
  }
};
