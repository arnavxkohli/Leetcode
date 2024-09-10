#include <unordered_set>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>

using namespace std;

struct QueueEntry {
  string curr;
  int turns;

  QueueEntry(string _curr, int _turns) : curr(_curr), turns(_turns) {}
};

class Solution {
public:
  int openLock(vector<string>& deadend, string target) {
    if(find(deadend.begin(), deadend.end(), "0000") != deadend.end()) return -1;
    unordered_set<string> deadendSet(deadend.begin(), deadend.end());
    unordered_set<string> visitedSet; visitedSet.insert("0000");
    queue<QueueEntry> bfsQueue; bfsQueue.push(QueueEntry("0000", 0));
    while(bfsQueue.size()) {
      QueueEntry queueCurr = bfsQueue.front(); bfsQueue.pop();
      string curr = queueCurr.curr; int turns = queueCurr.turns;
      if(curr == target) return turns;
      for(int i=0; i<4; i++) {
        string next = curr, before = curr;
        if(curr[i] == '0') { next[i] = '1'; before[i] = '9'; }
        else if(curr[i] == '9') { next[i] = '0'; before[i] = '8'; }
        else { next[i] = char(next[i] + 1); before[i] = char(before[i] - 1); }
        if(visitedSet.find(next) == visitedSet.end() && deadendSet.find(next) == deadendSet.end()) {
          visitedSet.insert(next); bfsQueue.push(QueueEntry(next, turns+1));
        }
        if(visitedSet.find(before) == visitedSet.end() && deadendSet.find(before) == deadendSet.end()) {
          visitedSet.insert(before); bfsQueue.push(QueueEntry(before, turns+1));
        }
      }
    }
    return -1;
  }
};
