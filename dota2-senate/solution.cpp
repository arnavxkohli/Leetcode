#include <string>
#include <queue>

using namespace std;

class Solution {
public:
  string predictPartyVictory(string senate) {
    int length = senate.size();
    queue<int> r, d;
    for(int i=0; i<length; i++) if(senate[i] == 'R') r.push(i); else d.push(i);
    while(r.size() && d.size()) {
      if(r.front() < d.front()) { r.push(r.front()+length); r.pop(); d.pop(); }
      else { d.push(d.front()+length); d.pop(); r.pop(); }
    }
    return r.size() ? "Radiant" : "Dire";
  }
};
