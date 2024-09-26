#include <algorithm>
#include <set>

using namespace std;

struct SegmentTree {
  int start;
  int end;
  SegmentTree* left;
  SegmentTree* right;

  SegmentTree(int _start, int _end, SegmentTree* _left=nullptr,
              SegmentTree* _right=nullptr) : start(_start), end(_end),
              left(_left), right(_right) {}
};

class MyCalendar {
private:
  SegmentTree* bookings;

public:
  MyCalendar(): bookings(nullptr) {}

  bool book(int start, int end) {
    if(bookings == nullptr) {
      bookings = new SegmentTree(start, end);
      return true;
    }
    return bookHelper(bookings, start, end);
  }

  bool bookHelper(SegmentTree* root, int start, int end) {
    if(end > root->start && start < root->end) return false;
    if(end <= root->start) {
      if(root->left == nullptr) {
        root->left = new SegmentTree(start, end);
        return true;
      }
      return bookHelper(root->left, start, end);
    }
    if(start >= root-> end) {
      if(root->right == nullptr) {
        root->right = new SegmentTree(start, end);
        return true;
      }
      return bookHelper(root->right, start, end);
    }
    return false;
  }
};