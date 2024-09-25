#include <vector>
#include <string>

using namespace std;

struct Trie {
private:
  struct TrieNode {
    TrieNode* currChars[26];
    bool end;
    TrieNode(): end(false) {
      for(int i=0; i<26; i++) {
        currChars[i] = nullptr;
      }
    }
  };

  void clear(TrieNode* _root) {
    if(_root == nullptr) return;
    for(int i=0; i<26; i++) {
      clear(_root->currChars[i]);
    }
    delete _root;
  }

public:
  TrieNode* root;
  Trie() { root = new TrieNode(); }

  void insertWord(string word) {
    TrieNode* curr = root;
    for(char c: word) {
      if(curr->currChars[c - 'a'] == nullptr) curr->currChars[c - 'a'] = new TrieNode();
      curr = curr->currChars[c - 'a'];
    }
    curr->end = true;
  }

  static bool search(string word, int index, TrieNode* curr, bool replace) {
    if (index == word.size()) return curr->end;
    int currChar = word[index] - 'a';
    if (curr->currChars[currChar] != nullptr) {
      if (search(word, index + 1, curr->currChars[currChar], replace)) {
        return true;
      }
    }
    if (replace) {
      for (int i = 0; i < 26; i++) {
        if (i != currChar && curr->currChars[i] != nullptr) {
          if (search(word, index + 1, curr->currChars[i], false)) {
            return true;
          }
        }
      }
    }
    return false;
  }

  // ~Trie() { clear(root); }
};

class MagicDictionary {
private:
  Trie trie;
public:
  MagicDictionary() {
    trie = Trie();
  }

  void buildDict(vector<string> dictionary) {
    for(string word: dictionary) trie.insertWord(word);
  }

  bool search(string searchWord) {
    return trie.search(searchWord, 0, trie.root, true);
  }
};