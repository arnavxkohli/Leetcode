#include <vector>
using namespace std;

class CustomStack {
private:
int* stack;
int* increments;
int capacity;
int occupancy;

public:
  CustomStack(int maxSize): capacity(maxSize), occupancy(0) {
    stack = new int[maxSize];
    increments = new int[maxSize];
  }

  void push(int x) {
    if(occupancy >= capacity) return;
    stack[occupancy] = x;
    increments[occupancy] = 0;
    occupancy++;
  }

  int pop() {
    if(occupancy == 0) return -1;
    if (occupancy >= 2) increments[occupancy-2] += increments[occupancy-1];
    occupancy--;
    int res = stack[occupancy] + increments[occupancy];
    stack[occupancy] = 0, increments[occupancy] = 0;
    return res;
  }

  void increment(int k, int val) {
    if(occupancy == 0) return;
    increments[min(k, occupancy)-1] += val;
  }

  ~CustomStack() {
    delete[] stack;
    delete[] increments;
  }
};
