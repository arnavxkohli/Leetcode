#include <vector>

using namespace std;

class Solution {
private:
  int largestFactor(int n) {
    int res = 1;
    for(int i=2; i<n; i++) if(n%i == 0) res = i;
    return res;
  }

public:
  int minSteps(int n) {
    vector<int> dp(n+1, 0);
    for(int i=2; i<n+1; i++) {
      int lf = largestFactor(i); dp[i] = i/lf + dp[lf];
    }
    return dp[n];
  }
};
