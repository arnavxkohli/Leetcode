#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

class Solution {
public:
  string largestNumber(vector<int>& nums) {
    string a, b;
    vector<string> numString;
    for(int num: nums) {
      numString.push_back(to_string(num));
    }
    sort(numString.begin(), numString.end(), [](string a, string b) {
      return a+b > b+a;
    });
    string res = "";
    for(string num: numString) {
      if(res == "" && num[0] == '0') continue;
      res += num;
    }
    return res;
  }
};