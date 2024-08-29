#include <optional>
#include <vector>

using namespace std;

struct Node {
  Node* ancestor;
  vector<Node*> children;
  bool isLocked;
  optional<int> userLocked;

  Node(Node *_ancestor=nullptr) :
   ancestor(_ancestor), isLocked(false), userLocked(nullopt) {}

  void addChild(Node *child) {
    children.push_back(child);
  }

  bool lock(int user) {
    if(isLocked) return false;
    isLocked = true, userLocked = optional<int>{user};
    return true;
  }

  bool unlock(optional<int> user) {
    if(!isLocked || user != nullopt && user.value() != userLocked.value_or(-1)) return false;
    isLocked = false, userLocked = nullopt;
    return true;
  }

  void forceUnlockDescendants() {
    for(Node* child: children){
      child->unlock(nullopt);
      child->forceUnlockDescendants();
    }
  }

  bool lockedDescendants() {
    if(isLocked) return true;
    for(Node* child: children) {
      if(child->isLocked || child->lockedDescendants()) return true;
    }
    return false;
  }
};

class LockingTree {
Node** treeMappings;
int numNodes;

public:
  LockingTree(vector<int>& parent) {
    numNodes = parent.size();
    treeMappings = new Node*[parent.size()];
    for(int i=0; i<parent.size(); i++) {
      treeMappings[i] = new Node();
    }
    for(int i=1; i<parent.size(); i++){
      treeMappings[i]->ancestor = treeMappings[parent[i]];
      treeMappings[parent[i]]->children.push_back(treeMappings[i]);
    }
  }

  ~LockingTree() {
    for(int i=0; i<numNodes; i++) {
      delete treeMappings[i];
    }
    delete[] treeMappings;
  }

  bool lock(int num, int user) {
    return treeMappings[num]->lock(user);
  }

  bool unlock(int num, int user) {
    return treeMappings[num]->unlock(optional<int>{user});
  }

  bool upgrade(int num, int user) {
    Node *node = treeMappings[num];
    Node *curr = node;
    while(curr != nullptr) {
      if(curr->isLocked) return false;
      curr = curr->ancestor;
    }

    if(!node->lockedDescendants()) return false;
    node->forceUnlockDescendants();
    return node->lock(user);
  }
};

