#include <vector>
using namespace std;

struct ListNode {
  int val;
  ListNode* next;
  ListNode(int _val=0, ListNode* _next=nullptr) : val(_val), next(_next) {}
};

class Solution {
public:
  vector<ListNode*> splitListToParts(ListNode* head, int k) {
    int length = 0;
    ListNode* curr = head;
    while(curr != nullptr) {
      length ++;
      curr = curr->next;
    }
    vector<ListNode*> res;
    int splits = length / k, remainder = length % k;
    vector<int> parts(k, splits);
    int ptr = 0;
    while(remainder) {
      parts[ptr]++; remainder--; ptr++;
    }
    ListNode* dummy = new ListNode(0, head);
    curr = dummy;
    ListNode* main_head = dummy;
    for(int i=0; i<parts.size(); i++) {
      int part = parts[i];
      while(part) {
        curr = curr->next;
        part--;
      }
      if(curr->next) {
        ListNode* temp = curr->next;
        curr->next = nullptr;
        res.push_back(main_head->next);
        curr = new ListNode(curr->val, temp);
        main_head = curr;
      } else break;
    }
    res.push_back(main_head->next);
    while(res.size() < k) {
      res.push_back(nullptr);
    }
    return res;
  }
};
