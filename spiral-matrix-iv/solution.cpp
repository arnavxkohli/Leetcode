#include <vector>
using namespace std;

struct ListNode {
  int val;
  ListNode* next;
  ListNode(int _val, ListNode* _next) : val(_val), next(_next) {}
};

class Solution {
public:
  vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
    vector<vector<int>> matrix(m, vector<int>(n, -1));
    vector<pair<int, int>> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    int direction = 0, row = 0, col = 0;
    ListNode* curr = head;
    while(curr != nullptr) {
      matrix[row][col] = curr->val;
      auto [drow, dcol] = directions[direction % 4];
      int nrow = row + drow, ncol = col + dcol;
      if(nrow >= m || nrow < 0 || ncol >= n || ncol < 0 || matrix[nrow][ncol] > 0) {
        auto [drow, dcol] = directions[++direction % 4];
        nrow = row + drow, ncol = col + dcol;
      }
      row = nrow, col = ncol;
      curr = curr->next;
    }
    return matrix;
  }
};
