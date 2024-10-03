#include <bitset>

using namespace std;

class Solution {
public:
  int minFlips(int a, int b, int c) {
    int mask = 1, res = 0;
    while(a || b || c) {
      int aBit = a&1, bBit = b&1, cBit = c&1;
      if((aBit | bBit) != cBit) {
        if(cBit == 1) {
          res += 1;
        } else {
          res += aBit + bBit;
        }
      }
      a >>=1, b >>= 1, c >>= 1;
    }
    return res;
  }
};
