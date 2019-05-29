/*
 * @lc app=leetcode id=224 lang=cpp
 *
 * [224] Basic Calculator
 */
#include <iostream>
#include <stack>
#include <string>

using namespace std;

// class Solution
// {
//   public:
//     int calculate(string s)
//     {
//         stack<int> num;
//         stack<char> sign;
//         char temp_char;
//         bool compute_flag = false;
//         // push the numbers into number stack and put the signs into sign stack
//         for (int i = 0; i < s.length(); i++)
//         {
//             if (isdigit(s[i]))
//             {
//                 string temp_string;
//                 temp_char = s[i];
//                 temp_string = temp_string + temp_char;
//                 while(isdigit(s[i+1]) && (i+1) < s.length())
//                 {
//                     i+=1;
//                     temp_char = s[i];
//                     temp_string = temp_string + temp_char;
//                 }
//                 num.push(stoi(temp_string));
//                 if (compute_flag)
//                 {
//                     int a = num.top();
//                     num.pop();
//                     int b = num.top();
//                     num.pop();
//                     char cur_sign = sign.top();
//                     sign.pop();
//                     if (cur_sign == '+')
//                     {
//                         a = b + a;
//                         num.push(a);
//                     }
//                     else if (cur_sign == '-')
//                     {
//                         a = b - a;
//                         num.push(a);
//                     }
//                     compute_flag = false;
//                 }
//             }
//             else
//             {
//                 char temp_sign = s[i];
//                 if (temp_sign == '+' || temp_sign == '-')
//                 {
//                     sign.push(s[i]);
//                     compute_flag = true;
//                 }
//                 else if(temp_sign == ')')
//                 {
//                     compute_flag = true;
//                     int a = num.top();
//                     num.pop();
//                     int b = num.top();
//                     num.pop();
//                     char cur_sign = sign.top();
//                     sign.pop();
//                     if (cur_sign == '+')
//                     {
//                         a = b + a;
//                         num.push(a);
//                     }
//                     else if (cur_sign == '-')
//                     {
//                         a = b - a;
//                         num.push(a);
//                     }
//                     compute_flag = false;
//                 }
//                 else    
//                 {
//                     compute_flag = false;
//                 }
//             }
//         }
//         return num.top();
//     }
// };

// int main()
// {
//     string s = "(1+(4+5+2)-3)+(6+8)";
//     Solution ans;
//     int res = ans.calculate(s);
//     cout<<res;
// }

class Solution{
    public:
        int calculate(string s) {
            
        }
}

