#include <algorithm>
#include <unordered_map>
#include <unordered_set>
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct TreeNode {
  int val;
  TreeNode* left;
  TreeNode* right;
  TreeNode(int _val, TreeNode* _left, TreeNode* _right) : val(_val), left(_left), right(_right) {}
};

class Solution {
private:
  unordered_map<int, vector<int>> graph;

  void createGraph(TreeNode* root) {
    if(root == nullptr) return;
    if(root->left != nullptr) {
      graph[root->val].push_back(root->left->val);
      graph[root->left->val].push_back(root->val);
    }
    if(root->right != nullptr) {
      graph[root->val].push_back(root->right->val);
      graph[root->right->val].push_back(root->val);
    }
    createGraph(root->left); createGraph(root->right);
  }

public:
  int amountOfTime(TreeNode* root, int val) {
    createGraph(root);
    queue<int> bfsQueue; bfsQueue.push(val);
    unordered_set<int> visited; visited.insert(val);
    int minutes = -1;
    while(bfsQueue.size()) {
      int queueSize = bfsQueue.size();
      while(queueSize) {
        int currNode = bfsQueue.front(); bfsQueue.pop();
        for(int child: graph[currNode]) {
          if(visited.find(child) == visited.end()) {
            visited.insert(child); bfsQueue.push(child);
          }
        }
        queueSize--;
      }
      minutes++;
    }
    return minutes;
  }
};
