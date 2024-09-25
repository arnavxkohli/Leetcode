#include <string>

using namespace std;

class Solution {
private:
  string add(string num1, string num2) {
    string res = "";
    int carry = 0, calc = 0, num1_ptr = num1.size()-1, num2_ptr = num2.size()-1;
    while(num1_ptr >= 0 && num2_ptr >= 0) {
      calc = carry + (num1[num1_ptr] - '0') + (num2[num2_ptr] - '0');
      carry = int(calc >= 10);
      res = to_string(int(calc % 10)) + res;
      num1_ptr--; num2_ptr--;
    }
    while(num1_ptr >= 0) {
      calc = carry + (num1[num1_ptr] - '0');
      carry = int(calc >= 10);
      res = to_string(int(calc % 10)) + res;
      num1_ptr--;
    }
    while(num2_ptr >= 0) {
      calc = carry + (num2[num2_ptr] - '0');
      carry = int(calc >= 10);
      res = to_string(int(calc % 10)) + res;
      num2_ptr--;
    }
    if(carry) res = "1" + res;
    return res;
  }

  string multiplyDigit(string num, int digit) {
    string res = ""; int carry = 0; int calc = 0;
    for(int i=num.size()-1; i>=0; i--){
      calc = (num[i] - '0') * digit + carry;
      carry = int(calc / 10);
      res = to_string(int(calc % 10)) + res;
    }
    if(carry) res = to_string(carry) + res;
    return res;
  }

public:
  string multiply(string num1, string num2) {
    if(num1 == "0" || num2 == "0") return "0";
    int zeros = 0; string res = "";
    for(int i=num2.size()-1; i>=0; i--) {
      string calc = multiplyDigit(num1, num2[i] - '0');
      calc.append(zeros++, '0');
      res = add(res, calc);
    }
    return res;
  }
};
