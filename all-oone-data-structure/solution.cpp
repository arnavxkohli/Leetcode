#include <string>
#include <unordered_map>
#include <unordered_set>

using namespace std;

struct Node {
  int count;
  unordered_set<string> words;
  Node* next;
  Node* prev;
  Node(int _count, Node* _next=nullptr, Node* _prev=nullptr): count(_count), next(_next), prev(_prev) {}
};

class AllOne {
private:
  unordered_map<string, Node*> wordCount;
  Node* minNode;
  Node* maxNode;

public:
  AllOne() : minNode(nullptr), maxNode(nullptr) {}

  void removeNode(Node* curr) {
    if(curr->prev != nullptr) {
      curr->prev->next = curr->next;
    }
    if(curr->next != nullptr) {
      curr->next->prev = curr->prev;
    }
    if(minNode == curr) {
      minNode = curr->next;
    }
    if(maxNode == curr) {
      maxNode = curr->prev;
    }
    delete curr;
  }

  void inc(string key) {
    if(wordCount.find(key) == wordCount.end()) {
      if(minNode == nullptr) {
        Node* curr = new Node(1);
        minNode = maxNode = curr;
        curr->words.insert(key);
        wordCount[key] = curr;
      } else if(minNode->count > 1) {
        Node* curr = new Node(1, minNode);
        minNode->prev = curr;
        minNode = curr;
        curr->words.insert(key);
        wordCount[key] = curr;
      } else {
        minNode->words.insert(key);
        wordCount[key] = minNode;
      }
    } else {
      Node* curr = wordCount[key];
      curr->words.erase(key);
      if(curr->next == nullptr) {
        curr->next = new Node(curr->count+1, nullptr, curr);
        maxNode = curr->next;
      } else if (curr->next->count > curr->count + 1) {
        Node* newNode = new Node(curr->count+1, curr->next, curr);
        curr->next->prev = newNode;
        curr->next = newNode;
      }
      curr->next->words.insert(key);
      wordCount[key] = curr->next;
      if(curr->words.empty()) removeNode(curr);
    }
  }

  void dec(string key) {
    Node* curr = wordCount[key];
    curr->words.erase(key);
    if(curr->count > 1) {
      if(curr->prev == nullptr) {
        curr->prev = new Node(curr->count-1, curr, nullptr);
        minNode = curr->prev;
      } else if (curr->prev->count < curr->count - 1) {
        Node* newNode = new Node(curr->count-1, curr, curr->prev);
        curr->prev->next = newNode;
        curr->prev = newNode;
      }
      curr->prev->words.insert(key);
      wordCount[key] = curr->prev;
    } else {
      wordCount.erase(key);
    }
    if(curr->words.empty()) removeNode(curr);
  }

  string getMaxKey() {
    return maxNode == nullptr ? "" : *(maxNode->words.begin());
  }

  string getMinKey() {
    return minNode == nullptr ? "" : *(minNode->words.begin());
  }
};
