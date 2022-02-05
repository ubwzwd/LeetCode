/*
224. Basic Calculator

Implement a basic calculator to evaluate a simple expression string.

The expression string may contain open ( and closing parentheses ), the plus + or minus sign -, non-negative integers and empty spaces .

Example 1:
Input: "1 + 1"
Output: 2

Example 2:
Input: " 2-1 + 2 "
Output: 3

Example 3:
Input: "(1+(4+5+2)-3)+(6+8)"
Output: 23

Note:
You may assume that the given expression is always valid.
Do not use the eval built-in library function.
*/
#include <iostream>
#include <stack>
#include <string>

using namespace std;

class Solution
{
  public:
    int calculate(string s)
    {
        stack<int> num;
        stack<char> sign;
        char temp_char;
        bool compute_flag = false;
        // push the numbers into number stack and put the signs into sign stack
        for (int i = 0; i < s.length(); i++)
        {
            if (isdigit(s[i]))
            {
                string temp_string;
                temp_char = s[i];
                temp_string = temp_string + temp_char;
                while(isdigit(s[i+1]) && (i+1) < s.length())
                {
                    i+=1;
                    temp_char = s[i];
                    temp_string = temp_string + temp_char;
                }
                num.push(stoi(temp_string));
                if (compute_flag)
                {
                    int a = num.top();
                    num.pop();
                    int b = num.top();
                    num.pop();
                    char cur_sign = sign.top();
                    sign.pop();
                    if (cur_sign == '+')
                    {
                        a = b + a;
                        num.push(a);
                    }
                    else if (cur_sign == '-')
                    {
                        a = b - a;
                        num.push(a);
                    }
                    compute_flag = false;
                }
            }
            else
            {
                char temp_sign = s[i];
                if (temp_sign == '+' || temp_sign == '-')
                {
                    sign.push(s[i]);
                    compute_flag = true;
                }
                else if(temp_sign == ')')
                {
                    compute_flag = true;
                    int a = num.top();
                    num.pop();
                    int b = num.top();
                    num.pop();
                    char cur_sign = sign.top();
                    sign.pop();
                    if (cur_sign == '+')
                    {
                        a = b + a;
                        num.push(a);
                    }
                    else if (cur_sign == '-')
                    {
                        a = b - a;
                        num.push(a);
                    }
                    compute_flag = false;
                }
                else    
                {
                    compute_flag = false;
                }
            }
        }
        return num.top();
    }
};

int main()
{
    string s = "(1+(4+5+2)-3)+(6+8)";
    Solution ans;
    int res = ans.calculate(s);
    cout<<res;
}