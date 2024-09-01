#include <vector>
using namespace std;

class Solution {
public:
  vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {
    if(original.size() != m * n) return {};
    vector<vector<int>> res;
    vector<int> row;
    for(int i=0; i<m*n; i++) {
      if((i%n) == 0 && i > 0) {
        res.push_back(row);
        row.clear();
        row.push_back(original[i]);
      } else {
        row.push_back(original[i]);
      }
    }
    if(row.size() > 0) res.push_back(row);
    return res;
  }
};
