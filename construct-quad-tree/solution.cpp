#include <vector>
#include <iostream>
using namespace std;

class Node {
public:
  bool val;
  bool isLeaf;
  Node *topLeft;
  Node *topRight;
  Node *bottomLeft;
  Node *bottomRight;

  Node(bool _val = false, bool _isLeaf = false, Node* _topLeft = nullptr,
    Node* _topRight = nullptr, Node* _bottomLeft = nullptr,
    Node* _bottomRight = nullptr) {}
};

class Solution {
public:
  Node *construct(vector<vector<int>>& grid) {
    int n = grid.size(), size = grid.size() * grid.size();
    int sum = 0;
    for(vector<int> row: grid) for(int element: row) sum += element;
    cout << (sum < size) << endl;
    if(sum == 0 || sum == size) return new Node(sum == size, true);
    vector<vector<int>> tl, tr, bl, br;
    for(int r=0; r<int(n/2); r++) {
      vector<int> tlRow, trRow, blRow, brRow;
      for(int c=0; c<int(n/2); c++) {
        tlRow.push_back(grid[r][c]);
        trRow.push_back(grid[r][c+int(n/2)]);
        blRow.push_back(grid[r+int(n/2)][c]);
        brRow.push_back(grid[r+int(n/2)][c+int(n/2)]);
      }
      tl.push_back(tlRow);
      tr.push_back(trRow);
      bl.push_back(blRow);
      br.push_back(brRow);
    }
    return new Node(sum > (size/2), false, construct(tl),
      construct(tr), construct(bl), construct(br));
  }
};


int main() {
  vector<vector<int>> test = {{0, 1}, {1, 0}};
  Solution solution = Solution();
  solution.construct(test);
}