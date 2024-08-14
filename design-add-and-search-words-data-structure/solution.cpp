#include <array>
#include <string>
#include <iostream>
#include <memory>
using namespace std;

struct TrieNode {
  array<unique_ptr<TrieNode>, 26> currChars;
  bool end;

  TrieNode() : end(false) {}
};

class WordDictionary {
private:
  unique_ptr<TrieNode> trie;
  int firstAscii;

public:
  WordDictionary() : firstAscii(97), trie(make_unique<TrieNode>()) {}

  void addWord(string word) {
    TrieNode* curr = trie.get();
    for(int curAscii: word) {
      curAscii -= firstAscii;
      if(curr->currChars[curAscii] == nullptr) curr->currChars[curAscii] = make_unique<TrieNode>();
      curr = curr->currChars[curAscii].get();
    }
    if(curr == nullptr) curr = new TrieNode();
    curr->end = true;
  }

  bool recursiveSearch(TrieNode *curr, int index, string word) {
    if(index == word.size()) return curr != nullptr && curr->end;
    int curAscii = word[index]-firstAscii;
    if(curAscii >= 0) {
      return curr->currChars[curAscii] != nullptr && recursiveSearch(curr->currChars[curAscii].get(), index+1, word);
    }
    for(curAscii=0; curAscii<26; curAscii++) {
      if(curr->currChars[curAscii] != nullptr && recursiveSearch(curr->currChars[curAscii].get(), index+1, word)){
        return true;
      }
    }
    return false;
  }

  bool search(string word) {
    return recursiveSearch(trie.get(), 0, word);
  }
};
