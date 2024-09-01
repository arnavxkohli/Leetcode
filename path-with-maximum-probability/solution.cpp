#include <functional>
#include <queue>
#include <vector>
using namespace std;

class Solution {
public:
  double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) {
    vector<double> distances(n, 0.0);
    distances[start_node] = 1.0;

    auto cmp = [](pair<int, double> l, pair<int, double> r) {
      return l.first < r.first;
    };

    vector<vector<pair<int, double>>> graph(n);
    for(int i=0; i<edges.size(); i++) {
      int u = edges[i][0], w = edges[i][1]; double d = succProb[i];
      graph[u].push_back({w, d});
      graph[w].push_back({u, d});
    }

    priority_queue<pair<double, int>, vector<pair<double, int>>, decltype(cmp)> pq(cmp);

    pq.push({1.0, start_node});
    while(pq.size() > 0) {
      auto [cur_dist, cur_node] = pq.top();
      pq.pop();
      if(cur_node == end_node) return cur_dist;
      for(auto[child, child_dist]: graph[cur_node]) {
        if(distances[child] < child_dist * cur_dist) {
          distances[child] = child_dist * cur_dist;
          pq.push({distances[child], child});
        }
      }
    }
    return 0.0;
  }
};
