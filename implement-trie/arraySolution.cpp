#include <string>
#include <unordered_map>
#include <iostream>
using namespace std;

struct TrieNode {
  TrieNode* next[26];
  bool end;

  TrieNode() : end(false) {
    for(int i=0; i<26; i++) {
      next[i] = nullptr;
    }
  }
};

class Trie {
private:
  TrieNode *trie;
  int firstAscii;

public:
  Trie() : firstAscii(97) {
    trie = new TrieNode();
  }

  void insert(string word) {
    TrieNode* curr = trie;
    for(int i=0; i<word.size(); i++) {
      if(curr->next[(int)word[i]-firstAscii] == nullptr) {
        curr->next[(int)word[i]-firstAscii] = new TrieNode();
      }
      if(i == word.size()-1) curr->next[(int)word[i]-firstAscii]->end = true;
      curr = curr->next[(int)word[i]-firstAscii];
    }
  }

  bool search(string word) {
    TrieNode* curr = trie;
    for(int i=0; i<word.size(); i++) {
      if(curr->next[(int)word[i]-firstAscii] == nullptr) return false;
      if(i == word.size()-1) return curr->next[(int)word[i]-firstAscii]->end;
      curr = curr->next[(int)word[i]-firstAscii];
    }
    return true;
  }

  bool startsWith(string prefix) {
    TrieNode* curr = trie;
    for(int i=0; i<prefix.size(); i++) {
      if(curr->next[(int)prefix[i]-firstAscii] == nullptr) return false;
      curr = curr->next[(int)prefix[i]-firstAscii];
    }
    return true;
  }
};
