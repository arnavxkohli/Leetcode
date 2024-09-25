#include <string>
#include <vector>
#include <set>
#include <unordered_map>

using namespace std;

struct TrieNode {
  TrieNode* currChars[26];
  bool end;

  TrieNode() : end(false) {
    for (int i = 0; i < 26; i++) {
      currChars[i] = nullptr;
    }
  }
};

struct Trie {
  TrieNode* trie;

  Trie() {
    trie = new TrieNode();
  }

  void insertWord(string word) {
    TrieNode* curr = trie;
    for (char c : word) {
      int index = c - 'a';
      if (curr->currChars[index] == nullptr)
        curr->currChars[index] = new TrieNode();
      curr = curr->currChars[index];
    }
    curr->end = true;
  }
};

class Solution {
private:
  vector<vector<char>> board;
  int rows;
  int cols;
  vector<pair<int, int>> neighbours = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};

  void searchWord(string& currWord, TrieNode* currTrie, int row, int col, vector<vector<bool>>& visited, vector<string>& result) {
    if(currTrie == nullptr) return;
    if (currTrie->end) {
      result.push_back(currWord);
      currTrie->end = false;
    }
    for (auto [dr, dc] : neighbours) {
      int nr = row + dr, nc = col + dc;
      if ((0 <= nr && nr < rows) && (0 <= nc && nc < cols)
          && (!visited[nr][nc])) {
        TrieNode* nextNode = currTrie->currChars[board[nr][nc] - 'a'];
        if (nextNode == nullptr) continue;
        visited[nr][nc] = true;
        currWord.push_back(board[nr][nc]);
        searchWord(currWord, nextNode, nr, nc, visited, result);
        currWord.pop_back();
        visited[nr][nc] = false;
      }
    }
  }

public:
  vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
    Trie trie;
    this->board = board;
    for (const string& word : words) {
      trie.insertWord(word);
    }
    rows = board.size(), cols = board[0].size();
    vector<string> result;
    vector<vector<bool>> visited(rows, vector<bool>(cols, false));
    for(int r=0; r<rows; r++) {
      for(int c=0; c<cols; c++) {
        TrieNode* startNode = trie.trie->currChars[board[r][c] - 'a'];
        if(startNode == nullptr) continue;
        string currWord(1, board[r][c]);
        visited[r][c] = true;
        searchWord(currWord, startNode, r, c, visited, result);
        visited[r][c] = false;
      }
    }
    return result;
  }
};
