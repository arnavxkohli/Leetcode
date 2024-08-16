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
private:
  vector<vector<int>> grid;

public:
  Node *recursiveConstruct(int rStart, int cStart, int n) {
    if(n == 1) return new Node(grid[rStart][cStart], true);
    bool isLeaf = true;
    for(int r=rStart; r<rStart+n; r++) {
      int c = cStart;
      while(c < cStart+n && isLeaf) {
        isLeaf = grid[r][c] == grid[rStart][cStart];
        c++;
      }
      if(!isLeaf) break;
    }
    if(isLeaf) return new Node(grid[rStart][cStart], true);
    int half = n/2;
    return new Node(grid[rStart][cStart], false,
      recursiveConstruct(rStart, cStart, half),
      recursiveConstruct(rStart, cStart+half, half),
      recursiveConstruct(rStart+half, cStart, half),
      recursiveConstruct(rStart+half, cStart+half, half));
  }

  Node *construct(vector<vector<int>>& grid) {
    this->grid = grid;
    return recursiveConstruct(0, 0, grid.size());
  }
};


int main() {
  vector<vector<int>> test = {{0, 1}, {1, 0}};
  Solution solution = Solution();
  solution.construct(test);
}