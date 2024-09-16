#include <vector>

using namespace std;

class Solution {
public:
  vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
    vector<int> prefix = {0}, res;
    for(int num: arr) prefix.push_back(prefix.back() ^ num);
    for(vector<int> query: queries) res.push_back(prefix[query[0]] ^ prefix[query[1]+1]);
    return res;
  }
};