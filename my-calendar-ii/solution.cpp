#include <algorithm>
#include <set>

using namespace std;

class MyCalendarTwo {
private:
  set<pair<int, int>> bookings;
  set<pair<int, int>> doubleBookings;
public:
  MyCalendarTwo() {  }

  bool book(int start, int end) {
    end--;
    for(auto[dbStart, dbEnd]: doubleBookings) {
      if(max(dbStart, start) <= min(dbEnd, end)) {
        return false;
      }
    }
    for(auto[bStart, bEnd]: bookings) {
      int intervalStart = max(bStart, start), intervalEnd = min(bEnd, end);
      if(intervalStart <= intervalEnd) {
        doubleBookings.insert({intervalStart, intervalEnd});
      }
    }
    bookings.insert({start, end});
    return true;
  }
};