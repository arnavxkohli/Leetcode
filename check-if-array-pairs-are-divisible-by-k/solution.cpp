#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
  bool canArrange(vector<int>& arr, int k) {
    int remainders[k]; memset(remainders, 0, sizeof(remainders));
    for(int num: arr) {
      int remainder = num%k;
      if(remainder < 0) remainder += k;
      remainders[remainder]++;
    }
    if(remainders[0] % 2) return false;
    if(!(k%2) && remainders[k/2] % 2) return false;
    for(int i=1; i<k; i++) {
      if(remainders[i] != remainders[k-i]) return false;
    }
    return true;
  }
};
