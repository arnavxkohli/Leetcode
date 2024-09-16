#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
private:
  int timeDifference(string time1, string time2) {
    return 60 * (stoi(time2.substr(0, 2)) - \
      stoi(time1.substr(0, 2))) + \
        (stoi(time2.substr(3)) - stoi(time1.substr(3)));
  }

public:
  int findMinDifference(vector<string>& timePoints) {
    sort(timePoints.begin(), timePoints.end());
    int length = timePoints.size();
    int res = 24 * 60;
    for(int i=0; i<length; i++) {
      int hours = stoi(timePoints[i].substr(0, 2));
      if(hours < 12) timePoints.push_back(to_string(hours+24) + timePoints[i].substr(2));
    }
    for(int i=1; i<timePoints.size(); i++) {
      res = min(res, timeDifference(timePoints[i-1], timePoints[i]));
      if(res == 0) return 0;
    }
    return res;
  }
};
