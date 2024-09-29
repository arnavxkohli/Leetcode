#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
  static inline bool cmp(const vector<int>& i1, const vector<int> & i2) { return i1[1] < i2[1]; }

  int eraseOverlapIntervals(vector<vector<int>>& intervals) {
    sort(intervals.begin(), intervals.end(), cmp);
    int end = -(6 * pow(10, 4)), count = 0;
    for(const vector<int>& interval: intervals) {
      if(interval[0] >= end) {
        end = interval[1]; count++;
      }
    }
    return intervals.size() - count;
  }
};
