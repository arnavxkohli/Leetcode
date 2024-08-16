#include <vector>
#include <deque>
using namespace std;

class Solution {
public:
  bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
    vector<int> result;

    int pointsTo[numCourses];
    memset(pointsTo, 0, sizeof(pointsTo));
    vector<int> graph[numCourses];

    for(vector<int> edge: prerequisites) {
      int end = edge[0], start = edge[1];
      pointsTo[end]++;
      graph[start].push_back(end);
    }

    deque<int> bfs;
    for(int i=0; i<numCourses; i++) {
      if(pointsTo[i] == 0) bfs.push_back(i);
    }

    while(bfs.size()) {
      int curr = bfs.front();
      vector<int> children = graph[curr];
      for(int child: children) {
        if(--pointsTo[child] == 0) bfs.push_back(child);
      }
      result.push_back(curr);
      bfs.pop_front();
    }

    return result.size() == numCourses;
  }
};

int main() {
  Solution solution = Solution();
  vector<vector<int>> preReqs = {{2, 1}, {2, 0}, {2, 3}, {1, 3}};
  cout << solution.canFinish(6, preReqs) << endl;
}