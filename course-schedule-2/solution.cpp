#include <vector>
#include <deque>
using namespace std;

class Solution {
public:
  vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
    vector<int> result;
    vector<int> empty;

    vector<int> graph[numCourses];
    int depends[numCourses];
    memset(depends, 0, sizeof(depends));
    for(vector<int> edge: prerequisites) {
      int end = edge[0], start = edge[1];
      depends[end]++;
      graph[start].push_back(end);
    }

    deque<int> bfs;
    for(int i=0; i<numCourses; i++) {
      if(depends[i] == 0) bfs.push_back(i);
    }

    while(bfs.size()) {
      int curr = bfs.front();

      vector<int> children = graph[curr];
      for(int child: children) {
        if(--depends[child] == 0) bfs.push_back(child);
      }

      result.push_back(curr);
      bfs.pop_front();
    }

    return (result.size() == numCourses) ? result : empty;
  }
};