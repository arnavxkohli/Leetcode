#include <algorithm>

using namespace std;

class Solution {
private:
  long long n;

  long long prefixBetween(long long previous) {
    long long candidate = previous, next = previous + 1, count = 0;
    while (candidate <= n) {
      count += min(next, n + 1) - candidate; // To count the case when n = 20
      candidate *= 10; next *= 10;
    }

    return count;
  }

public:
  int findKthNumber(int n, int k) {
    this->n = static_cast<long long>(n);
    long long result = 1; k--;
    while(k > 0) {
      long long count = prefixBetween(result);
      if(k >= count) { k -= count; result++; }
      else { k--; result *= 10; }
    }
    return result;
  }
};