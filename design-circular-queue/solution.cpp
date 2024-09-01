struct QueueNode {
  int val;
  QueueNode* next;
  QueueNode(int _val=0, QueueNode* _next=nullptr): val(_val), next(_next) {}
};

class MyCircularQueue {
private:
  int capacity;
  int occupancy;
  QueueNode* front;
  QueueNode* rear;

public:
  MyCircularQueue(int k):
    capacity(k), occupancy(0), front(nullptr), rear(nullptr) {}

  ~MyCircularQueue() {
    if(front == nullptr) return;
    rear->next = nullptr;
    QueueNode* curr = front;
    while(curr != nullptr){
      QueueNode* tmp = curr;
      curr = curr->next;
      delete tmp;
    }
  }

  bool enQueue(int value) {
    if(occupancy >= capacity) return false;
    QueueNode* curr = new QueueNode(value, rear);
    if(occupancy == 0) {
      front = curr, rear = curr;
    } else {
      rear->next = curr;
      rear = curr;
    }
    rear->next = front;
    occupancy++;
    return true;
  }

  bool deQueue() {
    if(occupancy == 0) return false;
    if(occupancy == 1) {
      delete front;
      front = nullptr, rear = nullptr;
    } else {
      QueueNode* curr = front;
      front = front->next;
      rear->next = front;
      delete curr;
    }
    occupancy--;
    return true;
  }

  int Front() {
    return (front == nullptr) ? -1 : front->val;
  }

  int Rear() {
    return (rear == nullptr) ? -1 : rear->val;
  }

  bool isEmpty() {
    return (occupancy == 0);
  }

  bool isFull () {
    return (occupancy == capacity);
  }
};
