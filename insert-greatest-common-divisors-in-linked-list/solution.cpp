struct ListNode {
  int val;
  ListNode* next;
  ListNode(int _val, ListNode* _next) : val(_val), next(_next) {}
};

class Solution {
private:
  int greatestCommonDivisor(int num1, int num2) {
    while(num1){
      int temp = num1;
      num1 = num2 % num1;
      num2 = temp;
    }
    return num2;
  }

public:
  ListNode* insertGreatestCommonDivisors(ListNode* head) {
    ListNode *fast = head, *slow = head->next;
    while(slow != nullptr) {
      ListNode* between = new ListNode(greatestCommonDivisor(fast->val, slow->val), slow);
      fast->next = between;
      fast = slow;
      slow = slow->next;
    }
    return head;
  }
};
