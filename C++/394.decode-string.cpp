/*
 * @lc app=leetcode id=394 lang=cpp
 *
 * [394] Decode String
 */
#include <stack>
#include <string>
using namespace std;
// @lc code=start
class Solution {
private:
  bool isDigit(char c) { return c >= '0' && c <= '9'; }

public:
  string decodeString(string s) {
    stack<int> countStack;
    stack<string> stringStack;
    string temp;
    int count = 0;
    for (auto c : s) {
      if (isDigit(c)) {
        count = count * 10 + c - '0';
      } else if (c == '[') {
        // push count into countStack first, then push any temp string into
        // string stack
        countStack.push(count);
        count = 0;
        stringStack.push(temp);
        temp = "";
      } else if (c == ']') {
        // temp string has a complete string inside, we can start decode
        string decodedString = stringStack.top();
        stringStack.pop();
        int curCount = countStack.top();
        countStack.pop();
        while (curCount > 0) {
          decodedString += temp;
          curCount--;
        }
        temp = decodedString;
      } else {
        temp.push_back(c);
      }
    }
    return temp;
  }
};
// @lc code=end
