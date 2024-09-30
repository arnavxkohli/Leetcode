#include <vector>
#include <string>

using namespace std;

struct Trie {
  struct TrieNode {
    TrieNode* children[26];
    bool end;
    TrieNode(): end(false) { for(int i=0; i<26; i++) children[i] = nullptr; }
  };

  TrieNode* root;
  Trie() { root = new TrieNode(); }

  void insertWord(const string& word) {
    TrieNode* curr = root;
    for(const char& c: word) {
      if(curr->children[c - 'a'] == nullptr) curr->children[c - 'a'] = new TrieNode();
      curr = curr->children[c - 'a'];
    }
    curr->end = true;
  }

  vector<string> findSuggestions(string& word, const TrieNode* curr) {
    if(curr == nullptr) return {};
    vector<string> suggestions; int index = 0;
    if(curr->end) suggestions.push_back(word);
    while(index < 26 && suggestions.size() < 3) {
      if(curr->children[index] != nullptr) {
        word.push_back(index + 'a');
        vector<string> currentSuggestions = findSuggestions(word, curr->children[index]);
        for(string suggestion: currentSuggestions) {
          if(suggestions.size() == 3) break;
          else suggestions.push_back(suggestion);
        }
        word.pop_back();
      }
      index++;
    }
    return suggestions;
  }
};

class Solution {
public:
  vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
    Trie trie = Trie();
    vector<vector<string>> results;
    for(string word: products) {
      trie.insertWord(word);
    }
    string word = "";
    Trie::TrieNode* curr = trie.root;
    for(char c: searchWord) {
      if(curr != nullptr) curr = curr->children[c - 'a'];
      word.push_back(c);
      results.push_back(trie.findSuggestions(word, curr));
    }
    return results;
  }
};
