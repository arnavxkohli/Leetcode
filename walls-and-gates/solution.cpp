#include <vector>
#include <queue>
using namespace std;

struct QueueEntry {
  pair<int, int> coordinates;
  int distance;

  QueueEntry(int row, int col, int dist) : coordinates({row, col}), distance(dist) {}
};

class Solution {
public:
  void islandsAndTreasure(vector<vector<int>>& grid) {
    int rows = grid.size(), cols = grid[0].size();
    const long INF = pow(2, 31)-1;
    vector<pair<int, int>> neighbors = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
    for(int r=0; r<rows; r++) {
      for(int c=0; c<cols; c++) {
        if (grid[r][c] == 0) {
          queue<QueueEntry> bfs;
          bfs.push(QueueEntry(r, c, 0));
          while(bfs.size()) {
            QueueEntry curr = bfs.front();
            bfs.pop();
            for(auto[nr, nc]: neighbors) {
              int dr = nr + curr.coordinates.first, dc = nc + curr.coordinates.second;
              if((0 <= dr && dr < rows) && (0 <= dc && dc < cols)) {
                if(curr.distance+1 < grid[dr][dc]) {
                  grid[dr][dc] = curr.distance+1;
                  bfs.push(QueueEntry(dr, dc, curr.distance+1));
                }
              }
            }
          }
        }
      }
    }
  }
};