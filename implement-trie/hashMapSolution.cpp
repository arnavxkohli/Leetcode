#include <string>
#include <unordered_map>
#include <iostream>
using namespace std;

struct TrieNode {
  unordered_map<char, TrieNode*> trieMap;
  bool end;

  TrieNode() : end(false) {}
  void insertChar(char curr) {
    trieMap[curr] = new TrieNode();
  }
};

class Trie {
private:
  TrieNode *trie;

public:
  Trie() {
    trie = new TrieNode();
  }

  void insert(string word) {
    TrieNode *curr = trie;
    for(int i=0; i<word.size(); i++) {
      if(curr->trieMap.find(word[i]) == curr->trieMap.end()) {
        curr->insertChar(word[i]);
      }
      curr = curr->trieMap[word[i]];
    }
    curr->end = true;
  }

  bool search(string word) {
    TrieNode *curr = trie;
    for(int i=0; i<word.size(); i++) {
      if(curr->trieMap.find(word[i]) == curr->trieMap.end()) return false;
      curr = curr->trieMap[word[i]];
    }
    return curr->end;
  }

  bool startsWith(string prefix) {
    TrieNode *curr = trie;
    for(int i=0; i<prefix.size(); i++) {
      if(curr->trieMap.find(prefix[i]) == curr->trieMap.end()) return false;
      curr = curr->trieMap[prefix[i]];
    }
    return true;
  }
};
