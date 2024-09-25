#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
unordered_map<string, vector<int>> cache;
public:
  vector<int> diffWaysToCompute(string expression) {
    if(expression.size() <= 2) return {stoi(expression)};
    if(cache.find(expression) != cache.end()) return cache[expression];
    vector<int> result;
    for(int i=1; i<expression.size()-1; i++) {
      char currChar = expression[i];
      vector<int> left, right;
      switch (currChar) {
      case '+':
        left = diffWaysToCompute(expression.substr(0, i));
        right = diffWaysToCompute(expression.substr(i + 1));
        for(int l : left) {
          for(int r : right) {
            result.push_back(l + r);
          }
        }
        break;
      case '-':
        left = diffWaysToCompute(expression.substr(0, i));
        right = diffWaysToCompute(expression.substr(i + 1));
        for(int l: left) {
          for(int r: right) {
            result.push_back(l - r);
          }
        }
        break;
      case '*':
        left = diffWaysToCompute(expression.substr(0, i));
        right = diffWaysToCompute(expression.substr(i + 1));
        for(int l: left) {
          for(int r: right) {
            result.push_back(l * r);
          }
        }
        break;
      default:
        break;
      }
    }
    cache[expression] = result;
    return result;
  }
};