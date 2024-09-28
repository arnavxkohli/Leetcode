struct Node {
  int value;
  Node* next;
  Node* prev;

  Node(int _value, Node* _next=nullptr, Node* _prev=nullptr)
    : value(_value), next(_next), prev(_prev) {}
};

class MyCircularDeque {
private:
  int capacity;
  int occupancy;
  Node* front;
  Node* last;

public:
  MyCircularDeque(int k) : capacity(k) {
    occupancy = 0;
    front = nullptr;
    last = nullptr;
  }

  bool insertFront(int value) {
    if(isFull()) return false;
    Node* curr = new Node(value, front, last);
    if(isEmpty()) {
      front = last = curr;
      front->next = front->prev = front;
    } else {
      front->prev = curr;
      last->next = curr;
      front = curr;
    }
    occupancy++;
    return true;
  }

  bool insertLast(int value) {
    if(isFull()) return false;
    Node* curr = new Node(value, front, last);
    if(isEmpty()) {
      last = front = curr;
      last->next = last->prev = last;
    } else {
      front->prev = curr;
      last->next = curr;
      last = curr;
    }
    occupancy++;
    return true;
  }

  bool deleteFront() {
    if(isEmpty()) return false;
    Node* curr = front;
    if(occupancy == 1) {
      front = last = nullptr;
    } else {
      front = front->next;
      front->prev = last;
      last->next = front;
    }
    delete curr;
    occupancy--;
    return true;
  }

  bool deleteLast() {
    if(isEmpty()) return false;
    Node* curr = last;
    if(occupancy == 1) {
      front = last = nullptr;
    } else {
      last = last->prev;
      last->next = front;
      front->prev = last;
    }
    delete curr;
    occupancy--;
    return true;
  }

  int getFront() {
    if(isEmpty()) return -1;
    return front->value;
  }

  int getRear() {
    if(isEmpty()) return -1;
    return last->value;
  }

  bool isEmpty() {
    return occupancy == 0;
  }

  bool isFull() {
    return occupancy == capacity;
  }
};