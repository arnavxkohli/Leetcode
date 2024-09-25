#include <string>
#include <vector>

using namespace std;

struct TrieNode {
  TrieNode* currChars[26];
  int count;

  TrieNode(): count(0) {
    for(int i=0; i<26; i++) currChars[i] = nullptr;
  }
};

struct Trie {
  TrieNode* root;

  Trie() {
    root = new TrieNode();
  }

  ~Trie() {
    clear(root);
  }

  void insertWord(string word) {
    TrieNode* curr = root;
    for(char c: word) {
      if(curr->currChars[c - 'a'] == nullptr) curr->currChars[c - 'a'] = new TrieNode();
      curr = curr->currChars[c - 'a'];
      curr->count++;
    }
  }

  int countScore(string word) {
    TrieNode* curr = root; int result = 0;
    for(char c: word) {
      curr = curr->currChars[c - 'a'];
      result += curr->count;
    }
    return result;
  }

private:
  void clear(TrieNode* node) {
    if (node == nullptr) return;
    for (int i = 0; i < 26; ++i) {
      clear(node->currChars[i]);
    }
    delete node;
  }
};

class Solution {
public:
  vector<int> sumPrefixScores(vector<string>& words) {
    vector<int> result;
    Trie trie = Trie();
    for(string word: words) {
      trie.insertWord(word);
    }

    for(string word: words) {
      result.push_back(trie.countScore(word));
    }
    return result;
  }
};
