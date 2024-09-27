#include <algorithm>
#include <map>

using namespace std;

class MyCalendarThree {
private:
  map<int, int> line;

public:
  MyCalendarThree() {  }
  int book(int startTime, int endTime) {
    line[startTime]++; line[endTime]--;
    int k = 0, active = 0;
    for(auto [_, count]: line) {
      active += count; // the [10, 20), [20, 30), [20, 40) edge case still works because the count will be 1 at 20 and active becomes 2
      k = max(k, active);
    }
    return k;
  }
};
