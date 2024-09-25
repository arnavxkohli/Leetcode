#include <vector>
#include <string>
#include <algorithm>

using namespace std;

struct TrieNode {
  TrieNode* currNum[10];
  bool end;

  TrieNode(): end(false) {
    for(int i=0; i<10; i++) {
      currNum[i] = nullptr;
    }
  }
};

struct Trie {
  TrieNode* root;

  Trie() {
    root = new TrieNode();
  }

  void addNum(const string& num) {
    TrieNode* curr = root;
    for(char digit: num) {
      if(curr->currNum[digit - '0'] == nullptr) curr->currNum[digit - '0'] = new TrieNode();
      curr = curr->currNum[digit - '0'];
    }
    curr->end = true;
  }

  int countPrefix(const string& num) {
    TrieNode* curr = root;
    int result = 0;
    for(char digit: num) {
      if(curr->currNum[digit - '0'] == nullptr) return result;
      curr = curr->currNum[digit - '0'];
      result++;
    }
    return result;
  }
};

class Solution {
public:
  int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
    if(arr1.size() < arr2.size()) {
      return longestCommonPrefix(arr2, arr1);
    }
    Trie trie = Trie();
    for(int num: arr1) {
      trie.addNum(to_string(num));
    }
    int result = 0;
    for(int num: arr2) {
      result = max(result, trie.countPrefix(to_string(num)));
    }
    return result;
  }
};
